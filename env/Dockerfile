FROM ubuntu:22.04

RUN apt update && apt install build-essential g++ gcc libstdc++6 libssl-dev -y && \
apt install wget -y && apt install zlib1g zlib1g-dev bzip2 cmake -y
RUN apt install libboost-all-dev libgtest-dev -y


# Build and running tests && Waiting server dump files in data before exit container
ENTRYPOINT ["/bin/sh", "-c", "$VOLUME_PATH/env/entrypoint.sh"]
#ENTRYPOINT ["/bin/sh", "-c", "cd /data/technicalTest/build && cmake . && make && make install && /data/technicalTest/env/server.sh start && /data/technicalTest/runTests && sleep 120 && /data/technicalTest/env/server.sh stop"]