//nesse exemplo do slaide, pagina 21 o vetor é passado por referencia
void preenche(int v[], int n){

    int i;
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
}
int main()
{
    int vetor [5];

    preenche(vetor, 5);

    int i;
    for(i=0; i < 5; i++){
        printf("\n %d", vetor[i]);
    }
    
    return 0;
}
