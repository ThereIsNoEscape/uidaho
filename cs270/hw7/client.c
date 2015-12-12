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
                check[0] = 0;
        }
        score[3] = rockg;
        score[4] = paperg;
        score[5] = scissorsg;
        score[6] = gamenum;
   }

   write(sockfd,str,100);
   close(sockfd);
   return 0;
}

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

