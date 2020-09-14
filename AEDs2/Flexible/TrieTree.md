```c#
public class Node{
    char Data {get;set;}
    Node[] Children {get;set;}
    int HashCode {get;set;}
    bool isLeaf {get;set;}

    
    public Node(char data, int maxChildren, int hashCode){
        this.Data = data;
        this.Children = new Node[maxChildren];
        this.HashCode = hashCode;
        this.isLeaf = false;
    }

    public Node(){
        this('', 26, 45);
    }

    public Node(char data){
        this(data, 26, 45);
    }

    public Node GetNode(char character){
        return Children[character.toLower() - hashCode];
    }
}

public bool Search(string data){
    Node _current = Root;
    for(int i = 0; i < data.length; i++){
        if(_current?.GetNode(data[i]) != null){
            _current = _current?.GetNode(data[i]);
        }else{
            i = data.length;
            return false;
        }
    }

    return _current?.isLeaf;
}

public void Inserir(String s){

}

public void Show(String s, Node n){
    if(n != null){
        if(n.isLeaf){
            Console.WriteLine(s);
        }else{
            for(int i = 0; i < n.Children.Length; i++){
                if(n.GetNode(n.Children[i]) != null){
                    Show(s + n.Data, n.GetNode(n.Children[i]));
                }
            }
        }
}
```

- [ ] Implemente um método que retorne o número de caracteres A contidos na árvore

```C#
public int Quantity(char c) => Quantity(0, c, Root);

public int Quantity(char c, Node n){
    int i = 0;
    if(n != null && !n.IsLeaf){
        for(int i = 0; i < n.Children.length; i++){
            if(n.GetNode(n.Children[i]) != null){
                if(n.GetNode(n.Children[i]).Data == c)
                    i++;

                i += Quantity(i, c, n.GetNode(n.Children[i]));
            }
        }
    }

    return i;
}
```

- [ ] Na árvore Trie conte o número de Nodes
- [ ] Na árvore Trie imprima a coleção de forma decrescente
- [ ] Execute o código da árvore Trie
- [ ] Implemente o pesquisar na TriePatricia
- [ ] Implemente o inserir na TriePatricia