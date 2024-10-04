#!/bin/bash
export BIN=/data/technicalTest/service

start() {
    # Start the server in the background and redirect output to a log file
    $BIN server $PORT $THREADS $TIMEOUT $BUFFER_SIZE $PREFIX > $VOLUME_PATH/tests/server.log 2>&1 &

    # Store the PID of the server process
    echo $! > server.pid

    # Output the PID to the console
    echo "Server started with PID: $(cat server.pid)"
}

# Function to stop the server
stop() {
    # Check if the PID file exists
    if [ -f server.pid ]; then
        # Read the PID from the file
        PID=$(cat server.pid)

        # Kill the process
        kill $PID

        # Optionally, wait for the process to terminate
        wait $PID 2>/dev/null

        # Remove the PID file
        rm  server.pid

        echo "Server with PID $PID has been stopped."
    else
        echo "PID file not found. Is the server running?"
    fi
}

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <start|stop>"
    exit 1
fi

case "$1" in
    start)
        start
        ;;
    stop)
        stop
        ;;
    *)
        echo "Invalid command. Use 'start' or 'stop'."
        exit 1
        ;;
esac