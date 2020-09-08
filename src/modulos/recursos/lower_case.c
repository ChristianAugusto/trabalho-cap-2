
char* fn_lowerCase(char *_string) {
    int i = 0;
    while(_string[i] != '\0') {

        if (_string[i] >= 65 && _string[i] <= 90){
            _string[i] = _string[i]+32;
        }

        i++;
    }

    return _string;
}