# Anotações de AED II
## 05-08-2019

#### Obs. Em um comando de repetição ao i começando em 0, repetindo emquanto i menor que n e i

#### incrementando de 1 em 1, a lista de comandos sera executada n vezes. 

- [x] Exe. Quantas execuções serão execultadas em um loop se tivermos i recebe k, emquanto i menor n i andando de 1 em 1? 
  - R. (n-k) vezes 

#### Obs. O operador O(x) pode ser lido como mais ou menos, aproximadamente 'x'

#### Obs. O limite inferior para o problema de ordenação é O(n*lg(n)). Variosalgoritimos alcanção esse limite. Por exemplo, quick sort, merge sort e heapsort

## 07-08-2019
- [x] Exe. Execute o programa disponivel na pasta fonte/U2_analiseAlgoritmos, obs tambem converter para c

- [x] Exe. Explique como funciona os comandos de shift right e shift left nas linguagens java e c
	- Move os bits da variavel para esquerda ou para direita uma quantidade especificada.
	
- [x] Exe. Apresente a funcao de complexdade para o exercicio da unidade 2 pg 85. Em sua resposta, utilize os operadores de piso ou teto
  - R. floor(lg(n)) + 1

#### OBS. sempre que um problema for sistematicamente dividido pela metade temos uma complexdade logaritimical

- [x] Ex. Qual e a funcao de complexidade para o pior e o melhor caso da ps. quando cada um deles acontece?

   - R. Melhor 1, pior n. Quando o item desejado esta na primeira posição, quando esta na ultima ou nao esta no array.

- [x] Ex. Repita o anterior para a pesquisa binaria.

- [x] Ex. no codigo da pb dentro do loop, realisamos duas comparações entre elementos do array. Altere o codigo para que acontaca somente uma dessas comparações.

```java
	boolean resp = false;
	int dir = n - 1, esq = 0, meio;
	while (esq <= dir) {
		meio = (esq + dir) / 2;
		
		if (x > vet[meio]) {
			esq = meio + 1;
		} else if (x < vet[meio]) {
			dir = meio - 1;
		} else {
			resp = true;
			esq = n;
		}

	}
```
## 14-08-2019
### TAD
#### Lista

#### Obs. Na lista, os metodos de inserir recebem um elemento e esse é adicionado no vetor. Nos de remover, retornamos o elemento removido.

- [ ] Ex. Implemente o metodo mostrar da lista de forma recursiva.

## 19-08-2019

#### Obs. A fila circular tem duas variaveis de gerenciamenro a **primeiro** gerencia as remocoes. a **ultimo**, as incercoes. 

#### Obs. Na fila circular fizemos uma *robadinha* acrecentando 1 no tamanho do vetor para evitar um if no metodo de inserir. Altere nossa fila, removendo essa *robadinha*


## 21-08-2019

- [ ] Ex. No codigo de celecao contabilize o numero de comparacoes e movimentacoes. Em seguida comapare os resultados praticos com os teoricos

- [ ] Ex. Suponha que n e igual a 6 e resolva os somatorios abaixo letra a(i=0; n-2; i) e letra b(i=1;n-1;i-1)

#### Obs. Os atributos na linguagem java podem ser public, private ou protected.

#### Obs. O protected pode ser acessado dentro da propria classe ou nas classes filhas.

- [ ] Ex. Liste todas as comparacoes executadas pelo incerssao para os vetores disponiveis na unidade 4c pagina 115

## 28-08/2019

#### Obs. O algoritimo de inscercao é a bala de prata para ordenamos um vetor ordenado ou praticamente ordenado. Nesse caso, realisamos (n-1) comparações.

- [ ] Ex. Unidade 4i pg-6

#### No loop interno do incerção a primeira condicao serve apenas para eliminar a posibilidade de uma excessao por acesso a posicao negativa.

#### No loop externo o valor inicial de i é 1 pois a primeira posicao nao precisa ser comparada com ela mesma.

#### Obs. O looping interno tem dias funcoes. Primeiro, pagando comparações, ele procura a posicao de incerssao do novo elemento. Segundo, ele desloca os elementos em uma unidade.

#### Dica. Utilise 2 loops. no primeiro aplique a pb para procurar a posicao de incerssao. No segundo apenas desloque os elementos em uma unidade

## 02/09/2019

**Representação de heap em um array**
 - [ ] Ex. Mostre que se i é maior que (n/2), array[i] é uma folha
 ---
 - [x] Faça um método que recebe um numeri inteiro i e mostra na tela o elemento localizado na posicao i do heap e todos os ancestrais daquele

```c#
void Mostrar (int i) {
	for (;i >= 1; i /= 2) {
		System.out.println(array[i]);
	}
}

void OrdenarPos(int tam) {
	for (int i = tam; array[i] > array[i/2]; i /=2) {
		swap(i,i/2);
	}
}
```
---


- #### Obs. No heap quando tivermos i - 1 elementos e desejarmos inseris mais um valor (posição i), pagaremos $\theta$log(i) comparações no pior caso.
- #### Obs. O heap sort acontece em 2 etapas. A primeira consiste na criação no heap. Nesse caso, inserimos elemento a elemento no heap a partir da segunda posicao. O numero de comparacoes nessa etapa é $\sum _{i=2}^{n}lg(i) = \theta(n \sdot lg(n))$. A segunda etapa consiste em remover todos os elementos do heap, nesse caso efetuamos   $\sum _{i=2}^{n}lg(i) = \theta(n \sdot lg(n))$

- #### Obs. O melhor caso para a construção do heap acontece quando todos os elementos inseridos no mesmo forem menores que o pai. Nesse caso, faremos $\theta n$ comparações. 
  
- #### Obs. O custo da segunda etapa sempre sera $O(n \sdot lg(n))$, pois o elemeto que colocamos na raiz é "Pequeno" e percorrerá um caminho proporcional ao tamanho da arvore

- [ ] Ex. Faça um metodo que receba 2 heaps e os unifique em um unico heap.

- [ ] Ex. Implemente o metodo getMaiorFilho que recebe um numero inteiro i e o tamanho do heap e retorna o maior filho do nó localizado na posição i

- [ ] Ex. Dado o codigo da inserção, implemente o shell sorting