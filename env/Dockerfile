FROM ubuntu:22.04

RUN apt update && apt install build-essential g++ gcc libstdc++6 libssl-dev -y && \
apt install wget -y && apt install zlib1g zlib1g-dev bzip2 cmake -y
RUN apt install libboost-all-dev libgtest-dev -y

ENTRYPOINT ["/bin/sh", "-c", "chmod +x $VOLUME_PATH/env/$TEST_TO_RUN && chmod +x $VOLUME_PATH/env/server.sh && $VOLUME_PATH/env/$TEST_TO_RUN"]