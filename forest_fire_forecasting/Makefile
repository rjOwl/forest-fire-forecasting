client: main.o ConsoleLogger.o LoggerFactory.o SocketClient.o TemperatureSensor.o ILogger.o PayloadParser.o TempOperations.o
	g++ -Wall main.o ConsoleLogger.o LoggerFactory.o SocketClient.o TemperatureSensor.o ILogger.o PayloadParser.o TempOperations.o -o client -pthread

main.o: main.cpp
	g++ -c -Iinclude main.cpp

ConsoleLogger.o: src/ConsoleLogger.cpp include/ConsoleLogger.h include/ILogger.h
	g++ -c -Iinclude src/ConsoleLogger.cpp

LoggerFactory.o: src/LoggerFactory.cpp include/LoggerFactory.h
	g++ -c -Iinclude src/LoggerFactory.cpp

SocketClient.o: src/SocketClient.cpp include/SocketClient.h include/INetworkClient.h
	g++ -c -Iinclude src/SocketClient.cpp

TemperatureSensor.o: src/TemperatureSensor.cpp include/TemperatureSensor.h
	g++ -c -Iinclude src/TemperatureSensor.cpp

TempOperations.o: src/TempOperations.cpp include/TempOperations.h
	g++ -c -Iinclude src/TempOperations.cpp

ILogger.o: src/ILogger.cpp include/ILogger.h
	g++ -c -Iinclude src/ILogger.cpp

PayloadParser.o: src/PayloadParser.cpp include/PayloadParser.h
	g++ -c -Iinclude src/PayloadParser.cpp

clean:
	rm *.o client


