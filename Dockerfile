FROM gcc:latest AS coverage

RUN apt-get update
RUN apt-get install -y libboost-dev libboost-program-options-dev libgtest-dev cmake lcov
ADD . /re
RUN mkdir -p /re/build
WORKDIR /re/build
RUN cmake ..
RUN make coverage