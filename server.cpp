#include "server.h"
#include <iostream>

#include <WinSock2.h>

#include <string>
#include <QDebug>
#include <QFileInfo>
#include <QDir>

#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

#include <WS2tcpip.h>


#include "winsock2.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"


#pragma comment (lib,"wsock32")///所需的库文件
#pragma comment(lib, "ws2_32.lib")

// server thread variables
using namespace std;
DWORD WINAPI run(LPVOID lpParameter);
void send(string file_name);




WSADATA wsaData;
int wsaret;
struct sockaddr_in server_ipaddr, client_ipaddr;//用来获得服务器和客户端的地址信息
char buff[4096];
string buff_str;
string url; //用户请求url
string file_name;
string file_path;
int nbuff;
string hdrFmt;/////////头部格式
char headers[1000];//////////保存头部
//读取文件
string CustomHtml;//////要传送的网页内容
QFile *Qfile; ///qt要读取的文件
QString QcustomHtml; ///qt读取的文件内容
QByteArray QbyteArray;
//遍历目录
QDir *Qdir;
QFileInfoList Qlist;
int dir_i;
QFileInfo Qfile_i;
//图片
QString Qimage_str;
FILE *fp;
//线程
HANDLE hThread = NULL;
#define BUFFER_SIZE 1024
static int csock, length;//sock是服务器端侦听套接字，csock是客户端连接套接字
int sock = NULL;




Server::Server(){

}


void Server::start(string ip_,int port_,string dir_){
    qDebug()<<"start in server file ...";
    ip = ip_;
    port = port_;
    dir = dir_;
    if(hThread==NULL&&sock==NULL){
        hThread = CreateThread(NULL, 0, run, NULL, 0, NULL);
    }
    return ;

}

void Server::restart(){
    qDebug()<<"restart in server file ...";
    if(hThread!=NULL&&sock!=NULL){
        Server::stop();
        Server::start(ip,port,dir);
    }
    return ;
}

void Server::stop(){
    qDebug()<<"stop in server file ...";
    //CloseHandle(hThread);
    if(hThread!=NULL&&sock!=NULL){
        closesocket(sock);
        TerminateThread(hThread,0);
        CloseHandle(hThread);
        hThread = NULL;
        sock = NULL;
    }
    return ;
}


DWORD WINAPI run(LPVOID lpParameter){
    /////////////初始化winsock环境

    // 对wsaData进行填充
    wsaret = WSAStartup(0x101, &wsaData);// 第一个参数指定了程序允许使用的WinSock规范的最高版本
    if (wsaret != 0)// 返回值为0则成功,否则失败
    {
        printf("initalize failed!/n");
        WSACleanup();
        return 0;
    }

    length = sizeof(struct sockaddr);

    memset(&server_ipaddr, 0, length);
    server_ipaddr.sin_family = AF_INET;
    //port
    server_ipaddr.sin_port = htons(port);
    //ip
    //qDebug()<<QString::fromStdString(ip);
    server_ipaddr.sin_addr.s_addr = inet_addr(ip.data());
    //server_ipaddr.sin_addr.s_addr = INADDR_ANY; // 网际IP地址


    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    ///绑定
    if (bind(sock, (struct sockaddr *)&server_ipaddr, length) == SOCKET_ERROR)
    {
        printf("Bind error/n");
        WSACleanup();
        exit(1);
    }
    ////侦听
    if (listen(sock, 5) == SOCKET_ERROR)
    {
        printf("Listen error/n");
        WSACleanup();
        exit(1);
    }



    while (1)
    {
        //////////侦听到连接后，产生新的套接字
        ///
        ///////////用来和客户端传递消息
        qDebug()<<"\n----------------request---------------------\n";
        /////
        csock = accept(sock, (struct sockaddr *)&client_ipaddr, &length);
        if (csock == SOCKET_ERROR)
        {
            printf("Listen error/n");
            WSACleanup();
            exit(1);
        }
        nbuff = recv(csock, buff, 4095, 0);
        buff[nbuff] = '\0';
        //printf("%s", buff);

        buff_str = buff;
        file_name = buff_str.substr(5,buff_str.find("HTTP/1.1")-6);
        //std::cout<<file_name;
        /////发送返回网页内容
        send(file_name);
        /////////关闭本次连接
        closesocket(csock);
    }
    system("pause");
    return 0;
}



void send(string file_name){
    ///
    std::cout<<"file name is "<<file_name;
    if(file_name.find("?")==-1){
        ////printf("no ? exists...\n");
    }else{
        file_name = file_name.substr(0,file_name.find("?"));
    }
    std::cout<<"\nthe last url is :"<<file_name<<"\n";
    ///生成合法的文件路径
    char last_char;
    last_char = dir[dir.length()-1];
    std::cout<<"\n"<<last_char<<"\n";
    if(last_char=='/'||last_char=='\\'){
        file_path = dir+file_name;
        std::cout<<"\na\n";
    }else{
        file_path = dir+"/"+file_name;
        std::cout<<"\nb\n";
    }

    std::cout<<"file path is "<<file_path;
    ///QFileInfo fi("C:/123");
    QFileInfo fi(QString::fromStdString(file_path));
    if(fi.isFile()){
        qDebug()<<"file exists ...";
        if(fi.suffix()=="jpg"||fi.suffix()=="png"||fi.suffix()=="gif"||fi.suffix()=="bmp"){
            QFileInfo my_fi(QString::fromStdString(file_path));
            hdrFmt =
            "HTTP/1.0 200 OK\r\n"
            "Server: MySocket Server\r\n"
            "Content-Type: image/png\r\n"
            "cahrset: utf-8\r\n"
            "Accept-Ranges: bytes\r\n"
            "Content-Length: %d\r\n\r\n";
            sprintf(headers, hdrFmt.data(),my_fi.size());
            send(csock, headers, strlen(headers), 0);
            fstream rfile;
            ///fstream wfile;
            char databuf[102400];
            rfile.open(file_path, ios::out  | ios::in  | ios::binary);
            ///wfile.open ("wfile.jpg", ios::out  | ios::binary | ios::trunc);
            while(rfile.is_open())
            {
                memset(databuf,0,sizeof(databuf));
                rfile.read(databuf,sizeof(databuf)-1);
                int readLen = rfile.gcount();
                ///wfile.write(databuf, readLen);
                send(csock, databuf, readLen, 0);
                if(rfile.eof())
                    break;
            }
            rfile.close();
            ///wfile.close();
            return ;
        }
        /////////头部格式
        hdrFmt =
        "HTTP/1.0 200 OK\r\n"
        "Server: MySocket Server\r\n"
        "Content-Type: text/html\r\n"
        "cahrset: utf-8\r\n"
        "Accept-Ranges: bytes\r\n"
        "Content-Length: %d\r\n\r\n\0";
        //
        ///html
        //"Content-Type: text/html\r\n"
        ///jpg
        //"Content-Type: image/jpeg\r\n"

        //////////要传送的网页内容
        CustomHtml =
        "<html>\r\n"
        "<head>\r\n"
        "<title></title>\r\n"
        "<meta http-equiv='content-type' content='text/html;charset=utf-8'>\r\n"
        "</head><center>\r\n"
        "<body>\r\n"
        "<p align=\"center\">welcome to web server ...</p>\r\n"
        "<p align=\"center\">file exists ...</p>\r\n"
        "<h3 align=\"center\"><a href=\"https://github.com/kompasim\">github.com</a></h3>\r\n"
        "<p>over!</p>\r\n"
        "</center></body></html>\r\n\r\n\0";

        //send html
        Qfile = new QFile(QString::fromStdString(file_path));
        if(!Qfile->open(QIODevice::ReadOnly|QIODevice::Text)){
            qDebug()<<"cant open file ...";
        }
        QcustomHtml = "";
        while(!Qfile->atEnd()){
            QbyteArray = Qfile->readLine();
            QcustomHtml = QcustomHtml + QbyteArray;
        }
        CustomHtml = QcustomHtml.toStdString();
        sprintf(headers, hdrFmt.data(), CustomHtml.length());
        /////发送响应头部
        send(csock, headers, strlen(headers), 0);
        ////根据请求地址打开静态文件
        //CustomHtml
        /////发送内容
        send(csock, CustomHtml.data(), CustomHtml.length(), 0);
    }else if(fi.isDir()){
        qDebug()<<"is dir ...";
        Qdir = new QDir(QString::fromStdString(file_path));
        Qdir->setFilter(QDir::Dirs|QDir::Files);
        Qlist = Qdir->entryInfoList();
        dir_i = 0;
        QcustomHtml = "";
        CustomHtml = "<html><head><meta http-equiv='content-type' content='text/html;charset=utf-8'><title></title></head><body><center>";
        do{
            Qfile_i = Qlist.at(dir_i);
            if(Qfile_i.fileName()=="."|Qfile_i.fileName()==".."){
                dir_i++;
                continue;
            }
            QcustomHtml += "<a href='"+Qfile_i.filePath().mid(dir.length())+"'>";
            QcustomHtml += Qfile_i.filePath().mid(dir.length()); ///.mid(file_path.length())
            QcustomHtml += "</a></br>";
            dir_i++;

        }while(dir_i<Qlist.size());
        CustomHtml += QcustomHtml.toStdString();
        CustomHtml += "</center><body></html>";

        /////////头部格式
        hdrFmt =
        "HTTP/1.0 200 OK\r\n"
        "Server: MySocket Server\r\n"
        "Content-Type: text/html\r\n"
        "Content-Type: text/html\r\n"
        "cahrset: utf-8\r\n"
        "Accept-Ranges: bytes\r\n"
        "Content-Length: %d\r\n\r\n\0";
        //

        sprintf(headers, hdrFmt.data(), CustomHtml.length());
        /////发送响应头部
        send(csock, headers, strlen(headers), 0);
        ////根据请求地址打开静态文件
        //CustomHtml
        /////发送内容
        send(csock, CustomHtml.data(), CustomHtml.length(), 0);
    }

}



