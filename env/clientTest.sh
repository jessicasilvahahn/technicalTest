#!/bin/bash

cd $VOLUME_PATH/build || exit 1

# Run CMake and make commands
cmake . && make && make install

mkdir -p $VOLUME_PATH/tests/data
rm -rf $VOLUME_PATH/tests/data/*
mkdir -p $VOLUME_PATH/tests/output
rm -rf $VOLUME_PATH/tests/output/*

export FILE=$VOLUME_PATH/tests/sample/resume.pdf

$VOLUME_PATH/env/server.sh start

sleep 15

$VOLUME_PATH/service client $HOST $PORT $FILE

sleep ${TIMEOUT_TESTS}

$VOLUME_PATH/mergeFiles $VOLUME_PATH/tests/data $VOLUME_PATH/tests/output/output.pdf

$VOLUME_PATH/env/server.sh stop



