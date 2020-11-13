# Build sender-executable
g++ -Wall -Wextra -Werror -o sender-executable sender.cpp SenderModule/CSVReader.cpp SenderModule/Timer.cpp Lib/DataProcessingUtility.cpp

# # Build receiver-executable
g++ receiver.cpp ReceiverModule/environment_checker.cpp ReceiverModule/Logger.cpp Lib/DataProcessingUtility.cpp -o receiver-executable -pthread

# # Run sender | receiver

./sender-executable | ./receiver-executable