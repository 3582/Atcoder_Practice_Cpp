package track;

import java.net.URI;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.io.IOException;

public class App {
    String url = "http://challenge-server.code-check.io/api/recursive/ask";
    String seed = "";

    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java App <seed> <n>");
            System.exit(1);
        }

        App app = new App();
        app.seed = args[0];
        int n = 0;
        try {
            n = Integer.parseInt(args[1]);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input for <n>: " + e.getMessage());
            System.exit(1);
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
            System.exit(1);
        }

        try {
            System.out.println(app.f(n));
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    private int f(int n) throws IOException, InterruptedException {
        if (n % 2 == 0) {
            if (n == 0) {
                return 1;
            } else if (n == 1) {
                return 2;
            } else {
                return f(n - 1) + f(n - 2) + f(n - 3) + f(n - 4);
            }
        } else {
            return askServer(n);
        }
    }

    private String askServer(int n) throws IOException, InterruptedException {
        String encodedSeed = URLEncoder.encode(seed, StandardCharsets.UTF_8);
        String fullUrl = String.format("%s?seed=%s&n=%d", url, encodedSeed, n);

        HttpClient client = HttpClient.newHttpClient();
        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create(fullUrl))
                .build();

        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
        if (response.statusCode() == 503) {
            throw new RuntimeException(
                    "Service Unavailable: You have exceeded the maximum number of requests per hour for the same seed.");
        } else if (response.statusCode() == 400) {
            throw new RuntimeException("Bad Request: The seed and/or n parameters were not specified.");
        }
        return response.body();
    }
}
