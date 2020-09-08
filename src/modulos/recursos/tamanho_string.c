
int fn_tamanhoString(char *_string) {
    int tamanho = 0;
    
    while (1) {
        if (_string[tamanho] == '\0') {
            break;
        } else if (_string[tamanho] == '\n') {
            _string[tamanho] = '\0';
            break;
        }

        tamanho++;
    }
    
    return tamanho;
}