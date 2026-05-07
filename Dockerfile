FROM ubuntu:22.04

RUN apt-get update && apt-get install -y build-essential cmake && rm -rf /var/lib/apt/lists/*
WORKDIR /workspace

COPY . /workspace
RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
RUN cmake --build build --parallel

CMD ["./build/twosum_tests"]
