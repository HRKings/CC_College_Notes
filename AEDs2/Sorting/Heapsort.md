# Heapsort

## 02/08/2019

- [ ] Mostre que se i > (n/2), array[i] é uma folha

```c#
void mostrar(int i){
    for(; i > 1; i /= 2){
        Console.println(array[i]);
    }
}

void construir(int tam){
    for(int i = tam;i > 1 && array[i] > array[i/2]; i /= 2){
        swap(i, i/2);
    }
}
```

- #### Obs.: No Heap, quando tivermos ```i - 1``` elementos e desejarmos inserir mais um valor (posição *i*), pagaremos $\theta(log[i])$ comparações no pior caso
- #### Obs.: O Heapsort acontece em duas etapas. A primeira consiste na criação do Heap. Nesse caso, inserimos elemento a elemento no Heap a partir da posição 2. O número de comparações nessa etapa é igual a $\sum_{i=2}^{N}log(i) = \theta(n*log(n))$. A segunda etapa consiste em remover todos os elementos do Heap. Nesse caso efetuamos $\sum_{i=2}^{N}log(i) = \theta(n*log(n))$ comparações

- [ ] Faça um método que receba dois Heaps e retorne um terceiro Heap que unifique os dois

- #### Obs.: O melhor caso para a construção do Heap acontece quando todos os elementos inseridos no mesmo forem menores que o pai. Nesse caso, faremos, $\theta(n)$ comparações
- O custo da segunda etapa sempre será $O(n*log(n))$, pois o elemento que colocamos na raiz é "pequeno" e percorrerá um caminho proporcional ao tamanho da árvore

- [ ] Implemente o método *getMaiorFilho(int i, int tamHeap)* e retorna o maior filho do nó localizado na posição *i*