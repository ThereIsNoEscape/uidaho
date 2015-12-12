// Jonathan Buch CS270 Assignment #7 client.c

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
void error(const char *);

int main(int argc, char *argv[])
{
   srand(time(NULL));
   int sockfd, servlen, result;
   struct sockaddr_un serv_addr;
   struct sockaddr* serv_addrPtr;
   char buffer[10];
   int score[7];
   
   serv_addrPtr = (struct sockaddr*) &serv_addr;
   servlen = sizeof (serv_addr);
   
   serv_addr.sun_family = PF_LOCAL;
   strcpy(serv_addr.sun_path, "newfile");
   if ((sockfd = socket(PF_LOCAL, SOCK_STREAM,0)) < 0)
       error("Creating socket");
   do {
	result = connect(sockfd, (struct sockaddr *) serv_addrPtr, servlen);
	if(result == -1) sleep (1);
   } while (result == -1);

   printf("Welcome to Rock Paper Scissors\n");
   printf("Inputs:\n \tr = Rock\n\tp = Paper\n\ts = Scissors\n");
   printf("\tq = Quit - Ends the Game\n");
   int computerGuess, rockg, paperg, scissorsg, gamenum;
   int i;
   for(i = 0; i < 7; i++){
	score[i] = 0;
   }
   computerGuess = 0;
   rockg = 0;
   paperg = 0;
   scissorsg = 0;
   gamenum = 0;
   char* tgamemsg = "Tie Game!";
   char* wgamemsg = "Player 1 Wins!";
   char* lgamemsg = "Player 2 Wins!";
   char* quit = "Quit";
   char str[100];
  //rock = 0, paper = 1, s = 2
  // (3+(p1-p2))%3

   while(1){
	gamenum++;
	computerGuess = (rand() % 3 + 1);	// 1 = rock, 2 = paper, 3 = scissors
	printf("Please enter your choice: ");
	bzero(buffer,10);
	fgets(buffer,10,stdin);
	if(buffer[0] == 'r'){
		rockg++;
		if(computerGuess == 1){
			score[1]++;
			sprintf(str, "Game Number %d: %s", gamenum, tgamemsg);
			write(sockfd,str,100);
		}
		else {
			if(computerGuess == 2){
				score[2]++;
				sprintf(str, "Game Number %d: %s", gamenum, lgamemsg);
				write(sockfd,str,100);
			}
			else {
				if(computerGuess == 3){
					score[0]++;
					sprintf(str, "Game Number %d: %s", gamenum, wgamemsg);
					write(sockfd,str,100);
				}
			}
		}
	} 
	if(buffer[0] == 'p'){
		paperg++;
		if(computerGuess == 1){
			score[0]++;
			sprintf(str, "Game Number %d: %s", gamenum, wgamemsg);
			write(sockfd,str,100);
		}
		else {
			if(computerGuess == 2){
				score[1]++;
				sprintf(str, "Game Number %d: %s", gamenum, tgamemsg);
				write(sockfd,str,100);
			}
			else {
				if(computerGuess == 3){
					score[2]++;
					sprintf(str, "Game Number %d: %s", gamenum, lgamemsg);
					write(sockfd,str,100);
				}
			}
		}
	} 
	if(buffer[0] == 's'){
		scissorsg++;
		if(computerGuess == 1){
			score[2]++;
			sprintf(str, "Game Number %d: %s", gamenum, lgamemsg);
			write(sockfd,str,100);
		}
		else {
			if(computerGuess == 2){
				score[0]++;
				sprintf(str, "Game Number %d: %s", gamenum, wgamemsg);
				write(sockfd,str,100);
			}
			else {
				if(computerGuess == 3){
					score[1]++;
					sprintf(str, "Game Number %d: %s", gamenum, tgamemsg);
					write(sockfd,str,100);
				}
			}
		}
	}
	if(buffer[0] == 'q'){
		break;
	}
	score[3] = rockg;
	score[4] = paperg;
	score[5] = scissorsg;
	score[6] = gamenum;
   }

   sprintf(str, "q%d %d %d", score[0], score[1], score[2]);
   write(sockfd,str,100);
   close(sockfd);
   return 0;
}

void error(const char *msg)
{
    perror(msg);
    exit(0);
}
