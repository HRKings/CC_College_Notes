```
8, n(3)
n(3).dir = 8, n(5)
n(5).dir = 8, null
n(5).dir = n(8)
```

- [x] Faça um método que retorna a soma dos elementos contidos na Árvore Binária (AB)
- [x] Faça um método que retorna a quantidade de elementos divisíveis por 3 contidos na AB
- [x] Faça um método *No ToAB(Celula P1, CelulaDupla P2)* que recebe o nó cabeça de uma lista simples e o de uma lista dupla. Em seguida, crie uma árvore binária inserindo os elementos intercalados das duas listas na AB. Retorne a raiz dessa AB

```c#
public int somarCentral(No i){
    int resp = 0;
    if(i != null){
        resp += i.elemento + somarCentral(i.esq) + somarCentral(i.dir);
    }
    return resp;
}

public int divisiveis (No i, int fator){
    int resp = 0;
    if(i != null){
        if(i.elemento % fator == 0){
            resp = 1;
        }
        resp += divisiveis(i.esq, fator) + divisiveis(i.dir, fator);
    }
    return resp;
}

public No toArvoreBinaria(Celula simples, Celula dupla){
    No resp = null;
    simples = simples.prox;
    dupla = dupla.prox;
    while(simples != null && dupla != null){
        inserirArvore(resp, simples.elemento);
        inserirArvore(resp, dupla.elemento);
        simples = simples.prox;
        dupla = dupla.prox;
    }

    while(simples != null){
        inserirArvore(resp, simples.elemento);
        simples = simples.prox;
    }

    while(dupla != null){
        inseirArvore(resp, dupla.elemento);
        dupla = dupla.prox;
    }

    return resp;
}
```

```c#
public static bool Equals(No i, No j){
    bool resp;
    if(i != null && j != null){
        resp = (i.elemento == j.elemento) && igual(i.esq, j.esq) && igual(i.dir, j.dir);
    }else if(i == null && j == null){
        resp = true;
    }else{
        resp = false;
    }
}

public bool existe(No i, int x){
    bool resp = false;
    if(i != null){
        resp = (i.elemento % x == 0) || existe(i.esq, x) || existe(i.dir, x);
    }
    return resp;
}
```

```c#
public void inserir(int x){
    if(raiz == null){
        raiz = new No(x);
    }else if(x < raiz.elemento){
        inserir(x, raiz.esq, raiz);
    }else if(x > raiz.elemento){
        inserir(x, raiz.dir, raiz);
    }
}

private void inserir(int x, No i, No pai){
    if(i == null){
        if(x < pai.elemento){
            pai.esq = new No(x);
        }else{
            pai.dir = new No(x);
        }
    }else if(x < i.elemento){
        inserir(x, i.esq, i);
    }else if(x > i.elemento){
        inserir(x, i.dir, i)
    }
}

public void remover(int x){
    if(raiz == null){
        return;
    } else if(x < raiz.elemento){
        remover(x, raiz.esq, raiz);
    }else if(x > raiz.elemento){
        remover(x, raiz.dir, raiz);
    }else if(raiz.dir == null){
        raiz = raiz.esq;
    }else if(raiz.esq == null){
        raiz = raiz.dir.
    }else{
        raiz = menorEsq();
    }
}

private void remover(int x, No i, No pai){
    else if(x < i.elemento){
        remover(x, i.esq, i);
    }else if(x > i.elemento){
        remover(x, i.dir, i);
    }else if(i.dir == null){
        if(x < pai.elemento){
            pai.esq = i.esq;
        }else{
            pai.dir = i.esq;
        }
    }else if(i.esq == null){
        if(x < pai.elemento){
            pai.esq = i.dir;
        }else{
            pai.dir = i.dir;
        }
    }
}
```

- #### No método remover, quando chegamos no 4º If temos certeza que o ponteiro i aponta para o nó contendo o elemento a ser removido. Entramos no quarto If para remover um nó folha ou com um filho à esquerda. Entramos no quinto If quando o nó tem apenas um filho à direita. Entramos no else final quando o nó a ser removido tem dois filhos

- [ ] 23/10 - U6A.P299,300
- [ ] 21/10 - U6A.P301-304

- ### As rotações acontecem sempre na direção oposta ao desbalanceamento
- ### As rotações sempre acontecem no avo

```c#
public No rotacionarDireita(No no){
    No pai = no.esq;
    No filho = pai.esq;

    no.esq = filho;
    pai.esq = no;

    return pai;
}
```

- #### A rotação dupla acontece quando o alinhamento entre avó, pai e filho causar um 'V'. A segunda rotação é a mais importante que acontece no avó. A primeira rotação (na direção contrária da segunda) alinha os três nós e acontece no pai

- [ ] No código da árvore binária insira os números 5 10 15 de formas distintas. Em seguida execute os 4 tipos de rotação. Antes e depois da rotação faça o mostrar pré

- #### Na AVL após uma inserção ou remoção devemos verificar todo o caminho (galho) entre a raiz e o elemento inserido/removido. Essa verificação é feita de baixo para cima

- [ ] Estude e execute o código da árvore AVL

- [ ] Insira os números de 1 a 20 em uma 2-3-4 usando fragmentação por ascensão
- [ ] Repita o anterior para os número de 20 a 1
- [ ] Repita a primeira usando fragmentação na descida
- [ ] Repita a segunda usando fragmentação na descida

- [ ] Implemente em Java e em C++ a 2-3-4 usando conceitos de herança **(FÉRIAS)**
 
- #### Na inserção da alvinegra, quando chegamos em um nó, verificamos se esse é do tipo 4. Se sim, fragmentamos o nó, invertendo as cores do nó e dos filhos. Em seguida, verificamos se a cor do pai é preta, se sim, rotacionamos o avó, considerando o alinhamento entre avó, pai e filho. Após a rotação, o elemento do meio fica branco e os filhos, pretos
- #### Na inserção na AB, toda folha será preta, exceto na raiz que sempre será branca
- #### Quando iserimos uma folha também temos que verificar se seu pai tem a cor preta

- [X] Implemente o método *bool isType4(Node i)* na árvore alvinegra

```C#
public bool isType4(Node i){
    if(i == null)
        return false;

    if(i.esq == null || i.dir == null)
        return false;

    if(i.esq.isColor && i.dir.isColor)
        return true;

    return false;
}

public bool isType4(Node i?) => ?i.esq.isColor && ?i.dir.isColor;
```

- [ ] U6E.P61