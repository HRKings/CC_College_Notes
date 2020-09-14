- #### Na pilha temos apenas o ponteiro topo porque as operações de inserção e remoção acontecem na mesma extremidade. Por outro lado, na fila, é indicado o uso de dois ponteiros. O ponteiro primeiro gerencia as remoções e inserimos elementos em ultimo.prox 
- #### O valor do nó cabeça sempre será desconsiderado.

- [ ] Implemente a pilha com nó cabeça. Em seguida implemente a fila sem nó cabeça. Justifique porque esses dois códigos são menos interessantes do que os apresentados na aula

```c#
public void inserir(int x){
    ultimo.prox = new Celula(x);
    ultimo = ultimo.prox;
}
```

---

- [x] Suponha a não existência do ponteiro ultimo e implemente o método inserir

```c#
public void inserir(int x){
    Celula i;
    for(i = primeiro; i.prox != null; i = i.prox);
    i.prox = new Celula(x);
    i = null;
}
```
- [x] Implemente 

```c#
public int remover(){
    if(ultimo == primeiro)
        throw new Exception("FACK!");

    Celula tmp = primeiro;
    primeiro.prox = primeiro.prox.prox;

    int elemento = tmp.elemento;

    tmp.prox = null;
    tmp = null;
}
```

- [ ] 

```c#
public void mostrarTerceiro() => c.prox.prox.prox.elemento;
```

```c#
public void mostrar(int x){
    Celula c = c.prox;

    for(int i = 0; i < x; i++) 
    {
        if(c.prox != null)
            c = c.prox
    }

    return c.elemento;
}
```

```c#
public void inverter() =>;

public void inverterEngine(Celula c){
    Celula c = 
}
```

- [ ] Execute o código da U.5C-P.34