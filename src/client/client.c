

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <resolv.h>
#include <sys/socket.h>

#define PORT_TIME       13              /* "time" (not available on RedHat) */
#define PORT_FTP        3306              /* FTP connection port */
#define SERVER_ADDR     "127.0.0.1"     /* localhost */
#define MAXBUF          1024

int main()
{   int sockfd;
    struct sockaddr_in dest;
    char buffer[MAXBUF];

	#ifdef HAVE_SYS_SOCKET_H
    	printf("系统检查到socket头文件");
	#endif

    /*---Open socket for streaming---*/
    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    {
        perror("Socket");
        exit(errno);
    }

    /*---Initialize server address/port struct---*/
    bzero(&dest, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(PORT_FTP);
    if ( inet_aton(SERVER_ADDR, &dest.sin_addr.s_addr) == 0 )
    {
        perror(SERVER_ADDR);
        exit(errno);
    }

    /*---Connect to server---*/
    if ( connect(sockfd, (struct sockaddr*)&dest, sizeof(dest)) != 0 )
    {
        perror("Connect ");
        exit(errno);
    }

    /*---Get "Hello?"---*/
    bzero(buffer, MAXBUF);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    /*---Clean up---*/
    close(sockfd);
    return 0;
}
