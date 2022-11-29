for FILE in x*;
    do tail -n +2 "$FILE" > "$FILE.tmp" && mv "$FILE.tmp" "$FILE";
done;