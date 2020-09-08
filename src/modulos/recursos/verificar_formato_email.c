
int fn_emailContemPontoAposArroba(char *_email, int _posicaoAtual, int _tamanhoEmail) {
    while (_posicaoAtual < _tamanhoEmail) {
        if (_email[_posicaoAtual] == '.') {
            return 1;
        }

        _posicaoAtual++;
    }

    return 0;
}

int fn_emailContemArroba(char *_email) {
    int i, tamanhoEmail = fn_tamanhoString(_email);
    for (i = 0; i < tamanhoEmail; i++) {
        if (_email[i] == '@') {
            if (fn_emailContemPontoAposArroba(_email, i, tamanhoEmail)) {
                return 1;
            }
        }
    }

    return 0;
}

int fn_formatoEmailCorreto(char *_email) {
    if (fn_emailContemArroba(_email)) {
        return 1;
    }

    return 0;
}