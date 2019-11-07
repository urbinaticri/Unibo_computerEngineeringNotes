#!/bin/bash
gruppo=$1
string=$2
dir=$3
tmp_file=$4

cd "$dir"
for file in *; do
	if [ -f "$file" ]; then
		#prende la stringa del group_id
		group_id=`ls -l | grep "$file" | awk {'print $3'}`
		if [ "$group_id" == "$gruppo" ]; then
			#conta il numero di occorrenze di una stringa $string nel file $file
			occ=`cat "$file" | grep -o "$string" | wc -l`
			if [ "$occ" -ne 0 ]; then 
				echo "$file" "$occ" >> "$tmp_file"
			fi
		fi
	else
		$0 "$gruppo" "$string" "$file"
	fi
done
