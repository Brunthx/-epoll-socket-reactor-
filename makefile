#threadTest:
#	g++ -pthread src/threadpool.cpp ThreadPoolTest.cpp -o ThreadPoolTest

server:
	g++ src/util.cpp src/buffer.cpp src/socket.cpp src/inetaddress.cpp client.cpp -o client && g++ -pthread src/util.cpp src/epoll.cpp src/inetaddress.cpp src/socket.cpp src/connection.cpp src/channel.cpp src/eventloop.cpp src/server.cpp src/acceptor.cpp src/buffer.cpp src/threadpool.cpp server.cpp -o server

clean:
	rm client && rm server
