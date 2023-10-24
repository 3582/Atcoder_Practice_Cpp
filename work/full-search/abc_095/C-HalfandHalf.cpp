#include <iostream>
using namespace std;

int main()
{
    int A, B, C, X, Y = 0;
    cin >> A >> B >> C >> X >> Y;
    int ans = 0;

    int maxCount = max(X, Y);

    if (A + B > C * 2)
    {
        ans = C * 2 * min(X, Y);
        if (X != Y)
        {
            if (maxCount == X && A < C * 2)
            {
                ans += A * (X - Y);
            }
            else if (maxCount == Y && B < C * 2)
            {
                ans += B * (Y - X);
            }
            else
            {
                ans += C * 2 * (maxCount - min(X, Y));
            }
        }
    }
    else
    {
        ans += A * X;
        ans += B * Y;
    }

    cout << ans << endl;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, ab, x, y;
  cin >> a >> b >> ab >> x >> y;

  int price = 0, pmin = INT_MAX;
  for ( int i=0; i<=2*max(x,y); i+=2 ) {
    price = max(0,x-i/2)*a + max(0,y-i/2)*b + i*ab;
    pmin  = min(pmin,price);
  }

  cout << pmin << endl;
}
*/