O_RDONLY O_WRONLY O_RDWR O_CREAT O_TRUNK

// Lettura/Scrittura semplice 
	char read_char;
    int n_read, n_write;
    while((n_read = read(fd_Fin, &read_char, sizeof(char))) != 0){
        if(n_read < 0){
            sprintf(buf,"Errore nella lettura da file in input\n");
            perror(buf);
            exit(EXIT_FAILURE);
        }

		n_write = write(fd_out, &read_char, sizeof(char));
		if(n_write < 0){
			sprintf(buf,"Errore nella scrittura su file di output\n");
            perror(buf);
            exit(EXIT_FAILURE);
		}        
    }
	close(fd_Fin);
	close(fd_out);
	return;

// Lettura/Scrittura per linee '\n'
	char read_char;
    int nread, nwrite, word_counter = 0, i = 0;
    char buf[MAX_STRING_LEN], word[MAX_STRING_LEN];

    while(i < MAX_STRING_LEN && (nread = read(fd_pipeIN, &read_char, sizeof(char)))){
        if(nread < 0){
            sprintf(buf,"Errore nella lettura da file in input\n");
            perror(buf);
            exit(EXIT_FAILURE);
        }

        if(read_char == '\n'){
            word[i] = '\0';
            word_counter++;
            i = 0;

            sprintf(buf,"parola %d: %s\n", word_counter, word);
            nwrite = write(fd_out, &buf, strlen(buf)*sizeof(char));
			if(n_write < 0){
				sprintf(buf,"Errore nella scrittura su file di output\n");
	            perror(buf);
	            exit(EXIT_FAILURE);
			}
        }else{
            word[i] = read_char;
            i++;
        }
    }
    close(fd_pipeIN);

// Lettura/Scrittua inverita
    char read_char;
    int nread, nwrite, lseek_return;
    char buf[MAX_STRING_LENGTH];

    //Posiziono il puntatore a file alla fine (usare SEEK_SET per riportarlo all'inizio)
    lseek_return = lseek(fd_In, -2, SEEK_END);

    while((nread = read(fd_In, &read_char, sizeof(char)) != 0) && lseek_return >= 0) {
    	if (nread < 0){
	        sprintf(buf,"Errore lettra da file in input");
	        perror(buf);
	        exit(EXIT_FAILURE);
	    }

        nwrite = write(fd_Out, &read_char, sizeof(char));
        if (nwrite < 0){
        	sprintf(buf,"Errore nella scrittura su file di output\n");
            perror(buf);
            exit(EXIT_FAILURE);
        }

        //Posiziono il puntatore a file sul carattere precedente
        lseek_return = lseek(fd_In, -2, SEEK_CUR);
    }

    close(fd_In);
    close(fd_Out);

// Lettura/Scrittura file binario muovendosi con lseek *esempio tratto da esercizio*
    int M, C, nread;
    if(fd_In > 0){
        //Leggo dalla pipe il valore        
        while((nread = read(in_pipe, &M, sizeof(int))) != 0){
            if(nread < 0){
                sprintf(buf,"Errore lettra da file in input");
	            perror(buf);
                exit(EXIT_FAILURE);
            }
            //Leggo il valore del terzo intero
            lseek(fd_In, 2*sizeof(int), SEEK_CUR);
            read(fd_In, &C, sizeof(int));
            printf("M: %d C: %d\n", M, C);

            if(M != C){
                C = M > C ? M : C;
                lseek(fd_In, -1*sizeof(int), SEEK_CUR);
                write(fd_In, &C, sizeof(int));         //correggo il file
            }
        }
        close(fd_In);
    }