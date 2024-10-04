#!/bin/sh

mkdir -p $VOLUME_PATH/tests/data

chmod -R 777 $VOLUME_PATH/tests/data

# Navigate to the build directory
cd $VOLUME_PATH/build || exit 1

# Run CMake and make commands
cmake . && make && make install

# Start the server
if [ -x "$VOLUME_PATH/env/server.sh" ]; then
    $VOLUME_PATH/env/server.sh start
else
    echo "Server start script not found or not executable."
    exit 1
fi

# Run tests
if [ -x "$VOLUME_PATH/runTests" ]; then
    $VOLUME_PATH/runTests
else
    echo "Test script not found or not executable."
    exit 1
fi

# Wait for the specified timeout
sleep ${TIMEOUT_TESTS}

# Stop the server
$VOLUME_PATH/env/server.sh stop