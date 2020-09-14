```c#
public class CelulaM{
    public CelulaM dir;
    public CelulaM esq;
    public CelulaM sup;
    public CelulaM inf;

    public int elemento;

    public CelulaM(int x){
        CelulaM(x, null, null, null, null);
        
    }

    public CelulaM(){
        CelulaM(0, null, null, null, null);
    }

    public CelulaM(int elemento, CelulaM inf, CelulaM sup, CelulaM esq, CelulaM dir){
        this.elemento = elemento;
        this.dir = dir;
        this.esq = esq;
        this.sup = sup;
        this.inf = inf;
    }
}
```

- [x] Na classe MatrixF declare os atributos e implemente os métodos mostrar, somar e getDiagonalPrincipal

```c#
public class MatrixF{
    int linha;
    int coluna;
    CelulaM inicio;

    public MatrixF(){
        this(3, 3);
    }

    public MatrixF(int linha, int coluna){
        this.linha = linha;
        this.coluna = linha;

        this.inicio = new CelulaM();
        
        CelulaM cur = inicio;
        for(int i = 0; i < linha; cur = cur.inf){
            CelulaM cur2 = cur;
            for(int j = 0; j < coluna; cur2 = cur2.dir){
                cur2.dir = new CelulaM();
                cur2.dir.esq = cur2;

                if(cur2.sup != null){
                    cur2.dir.sup = cur2.sup.dir;
                    cur2.sup.dir.inf = cur2.dir;
                }
            }
            cur.inf = new CelulaM();
            cur.inf.sup = cur;
        }
    }

    public void mostrar(){
        for(CelulaM i = inicio; i != null; i = i.inf){
            for(CelulaM j = i; j != null; j = j.dir){
                Console.Write(" " + j.elemento);
            }
            Console.WriteLine("");
        }
    }

    public MatrixF somar(MatrixF outra){
        MatrixF resultado;

        if(this.linha == outra.linha && this.coluna == outra.coluna){
            resultado = new MatrixF(this.linha, outra.coluna);

            for(CelulaM i = inicio, CelulaM i2 = outra.inicio, CelulaM r = resultado.inicio; i != null && i2 = null; i = i.inf, i2 = i2.inf, r = r.inf){
                for(CelulaM j = i, CelulaM j2 = i2, CelulaM rc = r; j != null && j2 != null; j = j.dir, j2 = j2.dir){
                    rc.elemento = j.elemento + j2.elemento;
            }
        }
        }

        return resultado;
    }

    public void getDiagonalPrincipal(){
        if(this.linha == this.coluna){
            for(CelulaM i = inicio; i != null; i = i.dir){
                i = i.inf;
                Console.WriteLine($"{i.elemento} ");
            }
        }
    }
}
```