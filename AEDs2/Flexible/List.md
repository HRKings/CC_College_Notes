```c#
public void inserirInicio(int x){
    Celula tmp = new Celula(c);
    tmp.prox = primeiro.prox;
    primeiro.prox = tmp;

    if(primeiro == ultimo)
        ultimo = tmp;
    
    tmp = null;
}
```

- #### Na lista flexivel, assumiremos que a posição 0 corresponde à do primeiro elemento útil

```c#
public void inserir(int x, int pos){
Celula c = primeiro;
for(int I = 0; I < pos && c.prox != null; c = c.prox, i++);

Celula nova = new Celula(x);
nova.prox = c.prox;
c.prox = nova;
}

public void remover(int pos){
Celula c = primeiro;
for(int I = 0; I < pos; i++, c = c.prox);

Celula r = c.prox;
c.prox = r.prox;

int result = r.elemento;
r.prox = null;
c = null;
r = null;

return result;
}
```

- [ ] U5E-P24,27,30

```c#
public void inverter(){
    Celula i = primeiro.prox;
    Celula j = ultimo;

    while(i !=  j; && j.prox != i){
        int tmp = i.elemento;
        i.elemento = j.elemento;
        j.elemento = tmp;

        i = i.prox;
        j = j.ant
    }
}
```

- [x] Leia várias palavras (entrada padrão da questão TP01_1 - Q2) e insira cada uma delas no final de uma lista flexível em C. Em seguida, ordene parcialmente a lista usando o método de ordenação por seleção parcial

```c
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <string.h>
#define bool   short
#define true   1
#define false  0
#define TAM 256

//TIPO CELULA ===================================================================
typedef struct Celula {
    char* elemento;        // Elemento inserido na celula.
    struct Celula* prox; // Aponta a celula prox.
} Celula;
 
Celula* novaCelula(char* elemento) {
   Celula* nova = (Celula*) malloc(sizeof(Celula));

   nova->elemento = (char*) malloc(TAM * sizeof(char));
   strcpy(nova->elemento, elemento);
   
   nova->prox = NULL;

   return nova;
}
 
//LISTA PROPRIAMENTE DITA =======================================================
Celula* primeiro;
Celula* ultimo;
 
 
/*
 * Cria uma lista sem elementos (somente no cabeca).
 */
void start () {
   primeiro = novaCelula("");
   ultimo = primeiro;
}
 
/*
 * Insere um elemento na ultima posicao da lista.
 * @param x int elemento a ser inserido.
 */
void inserirFim(char* x) {
   ultimo->prox = novaCelula(x);
   ultimo = ultimo->prox;
}
 
/*
 * Mostra os elementos da lista separados por espacos.
 */
void mostrar() {
   printf("[ ");
   Celula* i;
   for (i = primeiro->prox; i != NULL; i = i->prox) {
      printf("%s ", i->elemento);
   }
   printf("] \n");
}


// Swap
void swap(Celula* i, Celula* j) 
{
   char* temp = i->elemento; 
   
   i->elemento = j->elemento;
   j->elemento = temp;
   
   free(temp);
}

// Algoritmo de ordenacao
void selectionSort(int kParcial) 
{
   printf("Selection Sortando\n");
	Celula* atual;
	Celula* menor;
	Celula* indice;
   atual = primeiro->prox;

   for (int i = 0; i < kParcial; i++, atual = atual->prox) {      
      menor  = atual;
      
      for (indice = atual; indice != NULL; indice = indice->prox) {
         if (strcmp(menor->elemento, indice->elemento) > 0) {
            menor = indice;
         }
      }
      swap(atual, menor);
   }
}

int main(int argc, char* argv) 
{
   start();
   
   char* tmp = (char*)malloc(TAM * sizeof(char));
   gets(tmp);

   while(strcmp(tmp, "FIM") != 0) {
      inserirFim(tmp);
      gets(tmp);
   }

	mostrar();
	selectionSort(3);
   mostrar();
   
   return 0;
}
```

- [ ] Repita o anterior para as versões parciais dos algoritimos: Inserção, Quicksort, Heapsort