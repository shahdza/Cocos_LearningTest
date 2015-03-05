import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.ArrayList;

// 继承Thread线程类
public class ClientThread extends Thread {
	// 客户列表
	private ArrayList<Socket> clients = new ArrayList<Socket>();

	// 添加客户
	public void addClient(Socket socket) {
		clients.add(socket);
	}
	// 删除客户
	public void removeClient(Socket socket) {
		clients.remove(socket);
	}
	// 向客户发送数据
	public void sendMessage(Socket socket, String data) throws IOException {
		// 给玩家发送数据
		OutputStream os = socket.getOutputStream();
		os.write(data.getBytes("UTF-8"));
	}

	@Override
	public void run() {
		while (true) {
			try {
				for (Socket socket : clients) {
					// 获取客户端发来的数据
					InputStream is = socket.getInputStream();
					int len = is.available() + 1;
					byte[] buff = new byte[len];
					int flag = is.read(buff);

					// read()返回-1，说明客户端的socket已断开
					if (flag == -1) {
						System.out.println("有客户断开连接~");
						this.removeClient(socket);
						break;
					}

					// 输出接收到的数据
					String read = new String(buff);
					System.out.println("收到数据：" + read);

					// 给玩家发送数据
					String data = "恭喜你，连接成功啦~~";
					sendMessage(socket, data);
				}
				sleep(10);
			} catch (IOException e) {
				e.printStackTrace();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
