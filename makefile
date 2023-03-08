server:
	g++ src/util.cpp src/buffer.cpp src/socket.cpp src/inetaddress.cpp client.cpp -o client && g++ src/util.cpp src/epoll.cpp src/inetaddress.cpp src/socket.cpp src/connection.cpp src/channel.cpp src/eventloop.cpp src/server.cpp src/acceptor.cpp src/buffer.cpp server.cpp -o server

clean:
	rm client && rm server
