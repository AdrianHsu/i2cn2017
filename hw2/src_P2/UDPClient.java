import java.io.*;
import java.nio.*;
import java.net.*;

class UDPClient {
    public static void main(String args[]) throws Exception {
        DatagramSocket clientSocket = new DatagramSocket();

        // Send the sentence to Server 1000 times continuously
        InetAddress serverIP = InetAddress.getByName("127.0.0.1");

        for(int i = 1; i <= 10000; ++i) {
            String sentence = "Hello from Client\n";
            byte[] bytes = sentence.getBytes();
            DatagramPacket sendPkt =
                new DatagramPacket(bytes, bytes.length, serverIP, 9091);
            clientSocket.send(sendPkt);

            /* Suspend for 1us */
            // Thread.sleep(1); /*Prevent client side buffer overflow. */
        }

        clientSocket.close();
    }
}
