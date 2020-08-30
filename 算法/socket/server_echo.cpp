#include <sys/socket.h> // PF_INET IP地址类型 SOCK_STREAM socket流格式
#include <netinet/in.h> // IPPROTO_TCP tcp协议
#include <cstdlib>
#include <arpa/inet.h> // inet_addr
#include <cstdio>
#include <unistd.h>
#include <cstring>

int main(){
    //获取套接字标识符
    int tcp_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    // int udp_socket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    // socket(int, int, 0); 自动推断协议
    
    //创建套接字地址
    sockaddr_in serv_addr;
    //给前三位赋值，sin_zero自然默认为0
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = PF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //32位地址，inet_addr 字符串转unsigned int
    serv_addr.sin_port = htons(1234); //16 位端口
    //绑定ip端口
    // sockaddr和sockaddr_in大小差不多相同 ，sockaddr="127.0.0.1:80"，但是没有将这种字符串转为int
    bind(tcp_socket, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    //进入被动监听状态
    listen(tcp_socket, SOMAXCONN);// SOMAXCONN由系统决定最大请求队列长度

    while(1){
        //等待接收客户端连接
        sockaddr_in clnt_addr;
        socklen_t clnt_addr_size = sizeof(clnt_addr);
        int out_tcp_socket = accept(tcp_socket, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

        char str[100]={0};
        size_t re_size = recv(out_tcp_socket, str, sizeof(str), 0);//接收
        send(out_tcp_socket, str, re_size, 0);//发送

        close(out_tcp_socket);
        memset(str, 0, sizeof(str));
    }
    close(tcp_socket);
    return 0;
}