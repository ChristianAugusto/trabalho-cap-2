
int fn_stringsIguais(char *_string1, char *_string2) {
    if (fn_tamanhoString(_string1) != fn_tamanhoString(_string2)) {
        return 0;
    }

    int i = 0;
    while(1) {
        if (_string1[i] != _string2[i]){
            return 0;
        }

        i++;
    }

    return 1;
}