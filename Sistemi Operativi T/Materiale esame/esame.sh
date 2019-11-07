#!/bin/bash

#controllo sul numero di parametri
if [ $# -ne 3 ] ; then
	echo -e "Sintassi: $0 gruppo string dir" >&2
	exit 1
fi

#controllo sui parametri
if ! [[ -d "$3" ]] ; then
	echo -e "Il file $1 non esiste o non è una directory" >&2
	exit 1
fi

case "$0" in
	/*)
		dir_name=`dirname "$0"`
		recursive_command="$dir_name/do_esame.sh"
	;;
	*/*)
		dir_name=`dirname "$0"`
		recursive_command="`pwd`/$dir_name/do_esame.sh"
	;;
	*)
		recursive_command="do_esame.sh"
	;;
esac

tmp_file=~/tmp.txt
> "$tmp_file"

#Invoco il comando ricorsivo
"$recursive_command" "$1" "$2" "$3" "$tmp_file"

echo grep "$2" | sort -n | head -n 1 < $tmp_file
rm "$tmp_file"