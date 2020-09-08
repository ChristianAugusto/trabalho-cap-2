
void fn_removerCaracter(char *string, char _target, char _replace) {
  int i;
  for (i = 0; string[i] != '\0'; i++) {
    if (string[i] == _target) {
      string[i] = _replace;
    }
  }
}