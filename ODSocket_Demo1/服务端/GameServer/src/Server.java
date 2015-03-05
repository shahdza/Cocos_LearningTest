import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

	public static void main(String[] args) throws IOException {
		
		// 创建ServerSocket，监听端口号：12345
		ServerSocket ss = new ServerSocket(12345);
		// 创建用于管理客户端的收发数据的子线程类
		ClientThread clientThread = new ClientThread();
		clientThread.start();
		
		System.out.println("服务器开启啦");

		// 监听端口号：12345
		// 等待客户连接 accept()
		while (true) {
			// 开始接收客户端的连接
			Socket socket = ss.accept();
			System.out.println("有新客户连接~");
			clientThread.addClient(socket);
		}
	}
}
