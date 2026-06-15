all:
	g++ crack.cpp -o crack -lcrypto -lssl -ldl -lpthread