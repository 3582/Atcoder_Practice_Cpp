FROM ubuntu:20.04

RUN apt-get update && apt-get install -y \
    build-essential
WORKDIR /work
