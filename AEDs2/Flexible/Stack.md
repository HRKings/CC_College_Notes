- [x] Crie uma função clone

```c#
public Cliente clone(){
    Cliente novo = new Cliente();

    novo.id = this.id;
    novo.nome = this.nome;

    return novo;
}
```

- [x] Crie uma classe Celula

```c#
public class Celula{
    public int Valor = 0;
    public Celula Prox = null;

    public Celula(){
        this(0);
    }

    public Celula(int valor){
        this.Valor = valor;
        this.Prox = null;
    }

    public Celula(int valor, Celula prox){
        this.Valor = valor;
        this.Prox = prox;
    }
}
```

```c
typedef struct Celula {
    int elemento;
    struct Celula *prox;
}

Celula *novaCelula(int elemento){
    Celula *nova = (Celula*) malloc(sizeof(Celula));

    nova->elemento = elemento;
    nova->prox = NULL;

    return nova;
}
```

- [x] Implemente um método *int soma* que retorna a soma dos elementos da pilha
- [x] Implemente um método *int getMaior* que retorna o valor do maior do elemento

```c#
public static int soma(){
    int resultado = 0;
    for(Celula i = topo; i != null; i = i.prox){
        resultado += i.elemento;
    }

    return resultado;
}

public static int getMaior(){
    int resultado = 0;
    resultado = topo.elemento;

    for(Celula i = topo.prox; i != null; i = i.prox){
        if(i.elemento > resultado)
            resultado = i.elemento;
    }

    return resultado;
}
```

```c#
public static int soma() => somaEngine(topo);

public static int somaEngine(Celula c){
    if(c != null)
        return c.elemento + somaEngine(c.next);

    return c.elemento;
}

public static getMaior() => getMaiorEngine(topo);

public static getMaiorEngine(Celula c){
    if(c == null)
        return 0;
    
    int maior = getMaiorEngine(c.prox);
    if(c.elemento > maior)
        maior = c.elemento;

    return maior;
}
```

- [ ] Implemente um método iterativo para mostrar os elementos da pilha na forma em que os mesmos foram inseridos

```c#
public void mostrarInsercao(){
    for(Celula i = topo; i.prox != null; i = i.prox){
        for(Celula j = topo; j.prox != i; j = j.prox){
            Console.Print($"{i.elemento}, ");
            i = j;
        }
    }
}
```