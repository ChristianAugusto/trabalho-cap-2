
void fn_imprimirString(char *_string) {
    int i;
    for (i = 0; _string[i] != '\0'; i++) {
        printf("%c", _string[i]);
    }
}