import java.io.*;
import java.nio.*;
import java.net.*;

class UDPServer {
    public static void main(String args[]) throws Exception {
        DatagramSocket serverSocket = new DatagramSocket(9091);
        System.out.println("Server Ready..");
        while (true) {
            DatagramPacket rcvdPkt =
                new DatagramPacket(new byte[128], 128);
            serverSocket.receive(rcvdPkt);
            String sentence = new String(rcvdPkt.getData());
            InetAddress ipAddr = rcvdPkt.getAddress();
            int port = rcvdPkt.getPort();
            System.out.println("RECV from " + ipAddr + ":" + port +
               ":" + sentence);
            // Captalize the received sentence
            String modifiedSentence = sentence.toUpperCase() + '\n';
            System.out.println("MODIFY TO:" + modifiedSentence);
            byte[] sendData = modifiedSentence.getBytes();

            DatagramPacket sendPkt =
               new DatagramPacket(sendData, sendData.length, ipAddr, port);
            serverSocket.send(sendPkt);
        }
    }

}
