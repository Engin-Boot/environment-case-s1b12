# Build sender-executable
g++ -Wall -Wextra -Werror -o sender-executable sender.cpp SenderModule/CSVReader.cpp SenderModule/Timer.cpp Lib/DataProcessingUtility.cpp

# Build receiver-executable
g++ -Wall -Wextra -Werror -o receiver-executable receiver.cpp -pthread


# Run sender | receiver

./sender-executable | ./receiver-executable