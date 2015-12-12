// Jonathan Buch CS270 Assignment #7 server.c

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/un.h>
#include <signal.h>
#include <stdio.h>
void error(const char *);
int main(int argc, char* argv[])
{
   int sockfd, newsockfd, servlen, n;
   socklen_t clilen;
   struct sockaddr_un  cli_addr, serv_addr;
   struct sockaddr* cli_addrPtr;
   struct sockaddr* serv_addrPtr;
   char clientmsg[200];
   int score[7];
   serv_addrPtr = (struct sockaddr*) &serv_addr;
   servlen = sizeof(serv_addr);

   if ((sockfd = socket(PF_LOCAL,SOCK_STREAM,0)) < 0)
       error("creating socket");
   serv_addr.sun_family = PF_LOCAL;
   strcpy(serv_addr.sun_path, "newfile");
   unlink("newfile");
   bind(sockfd,(struct sockaddr *) serv_addrPtr,servlen);
   listen(sockfd,5);

   while(1){
   	clilen = sizeof(cli_addr);
   	newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
   	if (newsockfd < 0) 
       		error("accepting");
   	while((n=read(newsockfd,clientmsg,200)) > 0){
		if(clientmsg[0] == 'q'){
			printf("Number of Wins: %d\nNumber of Ties: %d\nNumber of Losses: %d\n", atoi(&clientmsg[1]), atoi(&clientmsg[2]), atoi(&clientmsg[4])); 
		}
		else {
			printf("\n%s\n", clientmsg);
		}
   	}
   }
   close(newsockfd);
   close(sockfd);
   return 0;
}

void error(const char *msg)
{
    perror(msg);
    exit(0);
}
