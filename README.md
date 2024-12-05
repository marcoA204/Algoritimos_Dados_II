# Algoritimos_Dados_II
# ola

# Busca e Ordenação

## 1. Busca Binária

A busca binária funciona dividindo a lista em duas metades a cada iteração. Para isso, ela faz comparações com o elemento central da lista. Se o elemento procurado for menor, ela descarta a metade superior, e se for maior, descarta a metade inferior. Esse comportamento só é possível porque a lista está ordenada, permitindo determinar em qual metade o elemento pode estar.

Se a lista não estiver ordenada, o algoritmo não funcionará, pois não será possível garantir que os elementos de uma metade sejam todos menores ou maiores que o elemento procurado.

### Exemplo Prático:

#### Entrada (Lista Ordenada):
```text
Lista: [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
Elemento a buscar: 10
```
#### Saída:
```text
Elemento 10 encontrado no índice 4.
```

#### Entrada (Lista Não Ordenada):
```text
Lista: [10, 2, 18, 4, 14, 8, 6, 12, 20, 16]
Elemento a buscar: 10
```

---