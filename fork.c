#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>


int main(void){
        int     pipe1[2],pipe2[2], nbytes, numero=109;
        pid_t   childpid;
        char    readbuffer[80];

        pipe(pipe1);
        pipe(pipe2);

        printf("Main program:\n"); 

        if((childpid = fork()) == -1){
                perror("fork");
                exit(1);
        }
 
        if(childpid == 0) {     //HIJO
                for(int i =0;i<10;i++){
                    close(pipe1[1]);
                    nbytes = read(pipe1[0], readbuffer, sizeof(readbuffer));

                    //readbuffer[nbytes] = '\0';                  //METODO 1 explicado abajo

                    printf("Hijo: %s", readbuffer);
                    
                    numero = atoi(readbuffer);
                    numero = numero +3;

                    sprintf(readbuffer, "%d\0\n",numero);       // METODO 2
                                                                // SE LE AGREGA \0 al sprintf(readbuffer, "%d\0\n",numero) para limitar el buffer



                    close(pipe2[0]);
                    write(pipe2[1], readbuffer, (strlen(readbuffer)));
                    }
                exit(0);
        }
        else  {                 //PAPA

                for(int i =0;i<10;i++){
                    close(pipe1[0]);
                    sprintf(readbuffer, "%d\n",numero);
                    write(pipe1[1], readbuffer, (strlen(readbuffer)+1));

                    close(pipe2[1]);
                    nbytes = read(pipe2[0], readbuffer, sizeof(readbuffer));

                    readbuffer[nbytes] = '\0'; //METODO 1
                                               //Nos aseguramos de que acabe la cadena con '\0', osea dependerá del tamaño del buffer
                                               // numero 1; nbytes = 1;         [ 1, \0, *, *, *]
                                               // numero 54; nbytes = 2;         [ 5, 4, \0, *, *]
                                               // Si no puede imprimir todo el buffer  

                    printf("Padre: %s\n\n", readbuffer);
                    
                    numero = atoi(readbuffer);
                    numero = numero +7;
                }
        }
    

        return(0);
}