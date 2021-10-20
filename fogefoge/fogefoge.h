void liberamapa();
void lemapa();
void alocamapa();
void imprimemapa();
int acabou();
void move(char direcao);

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};