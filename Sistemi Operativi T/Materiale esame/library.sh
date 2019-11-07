#!/bin/bash

#############################################
#   CONTROLLO DEI PARAMETRI DI INGRESSO     #
#############################################

if [ $# -ne 3 ]
then
    echo "Numero parametri errato"
    echo -e "Usage:\n\t$0 dirin word N dirout" 
    exit 1
fi

if [[ $1 = *[!0-9]* ]]
then
    echo "Deve essere un numero intero positivo" > &2
    exit 1
fi

if [[ $1 = *[0-9]* ]]; then
    echo "Deve essere una stringa di caratteri"
    exit 1
fi

if ! [ -d "$1" ]; then
    echo "Deve essere una directory esistente"
    exit 1
fi

if ! [ -f "$1" ]; then
    echo "Deve essere una file esistente"
    exit 1
fi


#########################################
#   SISTEMAZIONE PATH PER RICORSIONE    #
#########################################

case "$0" in
    /*)  # Path assoluto
    dir_name=`dirname $0`
    recursive_command="$dir_name"/rec_search.sh
    ;;
    */*) # Path relativo
    dir_name=`dirname $0`
    recursive_command="`pwd`/$dir_name/rec_search.sh"
    ;;
    *) #Comando nel path
    recursive_command=rec_search.sh
    ;;
esac


#########################################
#   RICERCA RICORSIVA TRA SUBDIRECTORY  #
#########################################

cd "$dir"
for file in *; do
    if [[ -f "$file" ]] ; then
        #In questo caso è file, fa qualcosa
    elif [[ -d "$file" ]] ; then
        #Directory e quindi chiamata ricorsiva
        echo "Ricorsione nella directory `pwd`/$file"
        "$0" "$file" "$2" "$3" "$4"
    fi
done


#####################
#   COMANDI UTILI   #
#####################

shift <n>   #Butta via i primi n parametri passati
> <file>    #Pulisco il <file> prima di usarlo


grep <parola> <file>    #Cerca la parola all'interno di un file
cut -d "<del>" -f<n>    #Prende la n-esima colonna separata con il delimiatore <del>
cat <file> | sort -n    #Ordina le righe del <file>
cat <file> | grep -o <parola> | wc -w   #Conta il numero di <parola> che compaiono nel <file>
stat --format="<>" <file>    #Stampa l'informazione chiesta relativa a quel <file>

top -b > "./processi.out" &
#mostra la lista dei processi correnti, filtra quelli del comando top
#e per ognuno prendi il primo argomento  usando come delimitatore ' '
pidP1=`ps | grep top | awk '{ print $1 }'`
echo "Esecuzione del comando top da parte del processo con id: $pidP1"
kill $(expr "$pidP1")


#################################
#   LISTA COMANDI UTILIZZATI    #
#################################

cat     #Mostra a video file o stringhe
cut     #Prende solo una sezione di linea da un file
grep    #Cerca le occorrenze di una parola in un file
sort    #Ordina le linee di un file
stat    #Visualizza informazioni relative a un file o filesystem
rev     #Stampa di ordine inverso ogni linea di un file
tee     #Legge da stdin e lo stampa su file
ls      #Visualizza il contenuto di una directory
echo    #Stampa a video/file una parola
who     #Visualizza chi è loggato
wc      #Stampa il numero di occorrenze di newline/parole
rm      #Rimuove un file o una directory
test    #Controlla il tipo di file 
cd      #Cambia directory
head    #Stampa la prima parte di un file
pwd     #Mostra il percorso assoluto
cp      #Copia un file/directory
mkdir   #Crea una nuova directory
awk     #
which   #Stampa dove è locato un comando
find    #Cerca un file in una directory
date    #Stampa la data e l'ora del sistema
tail    #Stampa l'ultima parte di un file
top     #Stampa i processi di Linux
ps      #Stampa i processi in esecuzione