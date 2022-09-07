server: main.o ConsolLogger.o LoggerFactory.o SocketClient.o TemperatureSensor.o ILogger.o PayloadParser.o 
	g++ -Wall main.o ConsolLogger.o LoggerFactory.o SocketClient.o TemperatureSensor.o ILogger.o PayloadParser.o -o server -pthread

main.o: main.cpp
	g++ -c -Iinclude main.cpp

ConsolLogger.o: src/ConsolLogger.cpp include/ConsolLogger.h include/ILogger.h
	g++ -c -Iinclude src/ConsolLogger.cpp

LoggerFactory.o: src/LoggerFactory.cpp include/LoggerFactory.h
	g++ -c -Iinclude src/LoggerFactory.cpp

SocketClient.o: src/SocketClient.cpp include/SocketClient.h include/INetworkClient.h
	g++ -c -Iinclude src/SocketClient.cpp

TemperatureSensor.o: src/TemperatureSensor.cpp include/TemperatureSensor.h
	g++ -c -Iinclude src/TemperatureSensor.cpp

ILogger.o: src/ILogger.cpp include/ILogger.h
	g++ -c -Iinclude src/ILogger.cpp

PayloadParser.o: src/PayloadParser.cpp include/PayloadParser.h
	g++ -c -Iinclude src/PayloadParser.cpp

clean:
	rm *.o server

