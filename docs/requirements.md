# Requirement Analysis

## 1) Generate Data CSV

    - python script to generate random data
    - random temp and humidity data in csv format

## 2) Sender Module

    - Read CSV (parse and store) --> SOLID
    - stdout write temperature and humidity values
    - threading ('N' seconds callback) or sleep(seconds)
    - trigger --> run
    - depends on csv or any other data files --> SOLID
    - Stopping mechanism
    - Error handling

## 3) Receiver Module

    - stdin read data
    - Process data --> SOLID // Constraints --> S --> class, module, function --> one reason to change
        Base class: Params
        a) Temperature b) Humidity  
    - Alert (Warning and Error) LOGGING (LOG LEVELS --> Info Warning Error)
    - threading (if no data received for 'N' seconds alert): polling for data or interrupt driven
    - Stopping mechanism
    - Error handling

## 4) Receiver Constraint Violation Alert Format

    ALERT: Constraint Violation

    - Warning: temperature greater/lesser than "temp_value" (should be 4 <= temp <= 37)
    - Error: temperature greater/lesser than "temp_value" (should be 4 <= temp <= 37)

    ALERT: No data received for more than 'N' seconds

## 5) Testing

    - Individual testing of SenderModule and ReceiverModule using catch2 library

## 6) Main: Run

    - Client sender code includes SenderModule
    - Client receiver code includes ReceiverModule
    - Compile into separate executables
    - Pipe output of sender to receiver
        sender-executable | receiver-executable
