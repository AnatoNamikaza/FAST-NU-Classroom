import java.io.*;
import java.net.*;

// Server class
class Server {
    static int clientCount = 0;
    private static ServerSocket server_socket;
    public static void main(String[] args)
        {
            ServerSocket server = null;

            try {

                // server is listening on port 8080
                int port_num = 8080;
                Socket socket = new Socket("localhost", port_num);
                server = new ServerSocket(port_num, socket);
                server.setReuseAddress(true);
                server_socket = server;

                // running infinite loop for getting
                // client request
                while (true) {

                    // socket object to receive incoming client
                    // requests
                    System.out.println("===========================");
                    System.out.println("Waiting for clients on port {"+port_num+"}");
                    Socket client = server.accept();
                    clientCount++;
                    
                    System.out.println("Active Connections = {"+clientCount+"}");
                    
                    // Displaying that new client is connected                    
                    System.out.println("Got connection from {"+client.getInetAddress()
                                       .getHostAddress()+"}:{"+port_num +"}");

                    // create a new thread object
                    ClientHandler clientSock
                        = new ClientHandler(client);

                    // This thread will handle the client
                    // separately
                    new Thread(clientSock).start();
                }
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            finally {
                if (server != null) {
                    try {
                        server.close();
                    }
                    catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
        }

    // ClientHandler class
    private static class ClientHandler implements Runnable {
        private final Socket clientSocket;

        // Constructor
        public ClientHandler(Socket socket)
            {
                this.clientSocket = socket;
            }

        public void run()
            {
                PrintWriter out = null;
                BufferedReader in = null;
                try {
					
                    // get the outputstream of client
                    out = new PrintWriter(
                        clientSocket.getOutputStream(), true);

                    // get the inputstream of client
                    in = new BufferedReader(
                        new InputStreamReader(
                            clientSocket.getInputStream()));

                    String line = "Welcome to the this.server_socket {"+
                        server_socket.getInetAddress()+
                        "}:{"+
                        server_socket.getLocalPort()+ "}";
                    out.println(line);
                    while ((line = in.readLine()) != null) {

                        // writing the received message from
                        // client
                        System.out.printf(
                            " Sent from the client: %s\n",
                            line);
                        out.println(line);
                    }
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
                finally {
                    try {
                        if (out != null) {
                            out.close();
                        }
                        if (in != null) {
                            in.close();
                            clientSocket.close();
                            clientCount--;
                            System.out.println("Active Connections = {"+clientCount+"}");
                        }
                    }
                    catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
    }
}
