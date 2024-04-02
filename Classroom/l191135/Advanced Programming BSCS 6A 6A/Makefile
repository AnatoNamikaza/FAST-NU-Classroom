all:
	javac Server.java
	javac Client.java
	gnome-terminal -- java Server
	sleep 1 # let the server start
	gnome-terminal -- java Client
