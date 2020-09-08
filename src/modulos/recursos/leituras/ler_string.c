
char* fn_lerString(int _tamanho, int lowerCase) {
    char *string;
    string = (char*)malloc((_tamanho+1) * sizeof(char));
    
    scanf("%s", string);
    setbuf(stdin, NULL);

    if (lowerCase) {
        int i = 0;
        while(string[i] != '\0') {
            tolower(string[i]);
            
            i++;
        }
    }

    return string;
}

// char* fn_lerString(int _tamanho, int tirarQuebraLinha) {
//     char *string;
//     string = (char*)malloc((_tamanho+1) * sizeof(char));
    
//     fgets(string, _tamanho+1, stdin);
    
//     setbuf(stdin, NULL);

//     return string;
// }