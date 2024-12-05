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

## 2. Casos de Comparação

### Lista Uniforme:
#### Exemplo:
```text
{10, 20, 30, 40, 50, 60, 70, 80, 90, 100}
```
#### Resultado:
O Interpolation Search pode ser mais rápido, pois a fórmula prevê diretamente a posição com base nos intervalos uniformes.

### Lista Não Uniforme:
#### Exemplo:
```text
{20, 64, 12, 50, 58, 80, 59, 100, 68, 76}
```
#### Resultado:
O Binary Search tende a ser mais consistente, pois o Interpolation Search depende de uma distribuição regular para ser eficiente.

### Casos em que o Interpolation Search é mais eficiente:
- A lista está ordenada com intervalos uniformes.
- O elemento buscado está próximo do início ou do final da lista, pois a fórmula aproxima diretamente o índice correto.

### Casos em que o Binary Search é preferível:
- A lista possui intervalos não uniformes, como valores exponenciais.
- A distribuição dos elementos é aleatória ou imprevisível.

---

## 3. Comparação de Tempo

#### Tempo de execução:
```text
Tempo de execução do Jump Search: 0,00000000 segundos.
Tempo de execução do Binary Search: 0,00000000 segundos.
```

---

## 4. Explicação: Combinação do Jump Search e Binary Search

### Busca Exponencial (Jump Search Modificado):
1. O algoritmo começa verificando se o elemento é o primeiro da lista.
2. Caso contrário, ele salta por potências de 2 (1, 2, 4, 8, etc.) até encontrar um intervalo onde o elemento pode estar ou exceder o tamanho da lista.

### Busca Binária:
1. Uma vez identificado o intervalo, o algoritmo realiza uma busca binária dentro desse intervalo para localizar o elemento.

### Análise de Desempenho:

#### Listas muito grandes:
- O Exponential Search é altamente eficiente para listas grandes, especialmente quando o elemento está próximo do início. Ele combina o salto exponencial para reduzir rapidamente o tamanho da busca e a eficiência da busca binária no intervalo restante.
- **Complexidade no pior caso:** O(log n), semelhante ao Binary Search.

#### Listas pequenas:
- Para listas pequenas, o ganho de desempenho em relação ao Binary Search é insignificante, pois o salto exponencial não reduz significativamente o espaço de busca.

---

## 5. Comparação de Tempo de Execução

#### Array Original:
```text
{28, 73, 31, 76, 70, 68, 85, 1, 87, 43, 9, 67, 12, 20, 47, 78, 4, 44, 57, 67}
```

#### Shell Sort:
```text
--- Shell Sort (Shell) ---
Tempo de execução (Shell): 0,00000000 segundos.
1 4 9 12 20 28 31 43 44 47 57 67 67 68 70 73 76 78 85 87

--- Shell Sort (Knuth) ---
Tempo de execução (Knuth): 0,00000000 segundos.
1 4 9 12 20 28 31 43 44 47 57 67 67 68 70 73 76 78 85 87

--- Shell Sort (Hibbard) ---
Tempo de execução (Hibbard): 0,00000000 segundos.
1 4 9 12 20 28 31 43 44 47 57 67 67 68 70 73 76 78 85 87
```

### Explicação das Sequências de Intervalos:

#### Sequência de Shell (Original):
- Começa com o intervalo n/2 e reduz o intervalo dividindo por 2 a cada iteração. Esse método é simples, mas sua eficiência depende muito da lista e do intervalo inicial.

#### Sequência de Knuth:
- Utiliza a fórmula **intervalo = 3 * intervalo + 1**, o que gera intervalos como 1, 4, 13, 40, 121, .... Esta sequência tende a ter um desempenho melhor que a sequência original de Shell, pois é mais eficiente na redistribuição dos elementos.

#### Sequência de Hibbard:
- Utiliza a fórmula **intervalo = 2 * intervalo + 1**, gerando intervalos como 1, 3, 7, 15, 31, .... É uma das sequências mais eficazes, e o desempenho tende a ser muito bom em listas maiores.

### Análise de Eficiência:

- **Shell:** A sequência mais simples e direta, mas pode ser ineficiente para listas maiores, pois os intervalos diminuem muito rapidamente e a redistribuição dos elementos não é ideal.
- **Knuth:** A sequência de Knuth é mais eficiente que a de Shell porque reduz mais eficientemente os intervalos, resultando em um número menor de trocas.
- **Hibbard:** A sequência de Hibbard é geralmente a mais eficiente. Ela fornece intervalos maiores inicialmente, o que permite uma redistribuição mais eficaz dos elementos em listas maiores.

---

## 6. Conceito "Dividir para Conquistar"

O Merge Sort utiliza o paradigma "Dividir para Conquistar", que envolve:

1. **Divisão:** Dividir a lista original em sublistas menores até que cada sublista tenha apenas um elemento.
2. **Conquista:** Ordenar e combinar essas sublistas em uma única lista ordenada durante a fase de mesclagem.
3. **Combinação:** As sublistas menores são gradualmente mescladas para formar a lista completa ordenada.

---
## 7. Comparação de Tempo de Execução

### Array Original (Pequeno):
**Entrada:**
```plaintext
64, 34, 25, 12, 22, 11, 90
```
**Ordenando o Array Pequeno...**
```plaintext
Iteração 1: 11 34 25 12 22 64 90
Iteração 2: 11 12 25 34 22 64 90
Iteração 3: 11 12 22 34 25 64 90
Iteração 4: 11 12 22 25 34 64 90
Iteração 5: 11 12 22 25 34 64 90
Iteração 6: 11 12 22 25 34 64 90
```
**Tempo de Execução:**
```plaintext
0,02900000 segundos.
```

### Array Original (Médio):
**Entrada:**
```plaintext
64, 34, 25, 12, 22, 11, 90, 41, 32, 56, 87, 53
```
**Ordenando o Array Médio...**
```plaintext
Iteração 1: 11 34 25 12 22 64 90 41 32 56 87 53
Iteração 2: 11 12 25 34 22 64 90 41 32 56 87 53
Iteração 3: 11 12 22 34 25 64 90 41 32 56 87 53
Iteração 4: 11 12 22 25 34 64 90 41 32 56 87 53
Iteração 5: 11 12 22 25 32 64 90 41 34 56 87 53
Iteração 6: 11 12 22 25 32 34 90 41 64 56 87 53
Iteração 7: 11 12 22 25 32 34 41 90 64 56 87 53
Iteração 8: 11 12 22 25 32 34 41 53 64 56 87 90
Iteração 9: 11 12 22 25 32 34 41 53 56 64 87 90
Iteração 10: 11 12 22 25 32 34 41 53 56 64 87 90
Iteração 11: 11 12 22 25 32 34 41 53 56 64 87 90
```
**Tempo de Execução:**
```plaintext
0,06300000 segundos.
```

### Array Original (Grande):
**Entrada:**
```plaintext
845, ...
```
**Ordenando o Array Grande...**
```plaintext
Tempo de Execução: 0.02637410 segundos.
```

### Análise do Desempenho

- **Para listas pequenas (n < 10):**
  - O *Selection Sort* é relevante e eficiente, pois o número de comparações é pequeno.

- **Para listas médias (10 < n < 100):**
  - O número de comparações aumenta rapidamente, tornando o algoritmo mais lento conforme o tamanho da lista cresce.

- **Para listas grandes (n > 100):**
  - Não indicado para esse tipo de listas, pois o tempo de execução cresce muito rapidamente. Algoritmos como *Quick Sort* ou *Merge Sort* são mais eficientes.

---

## 8. Explicação de como os Baldes são Preenchidos e Ordenados

No *Bucket Sort*, os "baldes" são uma estrutura útil para organizar os elementos da lista antes de ordená-los:

- **Baldes:**
  - São conjuntos (como arrays ou listas dinâmicas) enquanto os elementos da lista original são distribuídos com base em uma característica específica.

### Preenchimento dos Baldes

- **Para números em ponto flutuante (0 à 1):**
  - Cada elemento é mapeado para um balde com base em sua posição no intervalo.
  - **Exemplo:** Temos o valor `0.32` e `10` baldes:
    ```plaintext
    Posição do balde: floor(0.32 * 10) = 3
    O valor 0.32 vai para o balde 3.
    ```

- **Para números inteiros:**
  - Mapeamento feito considerando o valor máximo e o número de baldes.
  - **Exemplo:** Temos o valor `54`, máximo `99` e `10` baldes:
    ```plaintext
    Posição do balde: floor((54 * 10) / (99 + 1)) = 5
    O valor 54 vai para o balde 5.
    ```

### Ordenação dos Baldes

- Depois que os baldes são preenchidos, cada balde é ordenado individualmente.
- O *Insertion Sort* é frequentemente usado para ordenar os baldes.
- Após ordenar cada balde, os elementos são concatenados na ordem dos baldes para formar a lista ordenada.

---

## 9. Explicação de como o Algoritmo Lida com Bases Diferentes

O *Radix Sort* classifica os números processando um dígito por vez, da menor unidade (dígito menos significativo) para a maior unidade (dígito mais significativo).

### Escolha da Base

- **Base 10:**
  - O algoritmo processa cada dígito decimal (0-9).

- **Base 2:**
  - O algoritmo processa cada bit individual (0 ou 1).

### Exemplo de Processamento

1. **Dígito Menos Significativo (Base 10):**
   - Os números são agrupados e reordenados com base no primeiro dígito.

2. **Dígito Mais Significativo (Base 10):**
   - O processo se repete até que todos os dígitos sejam processados.

Essa abordagem garante que o algoritmo seja estável, ou seja, os elementos com o mesmo valor mantêm a ordem relativa original.

### Análise de Desempenho do Quick Sort

**Listas Quase Ordenadas:**
- Quando a lista está quase ordenada, o Quick Sort pode ter desempenho eficiente, especialmente com a escolha correta do pivô. Escolher o pivô como o elemento central pode ajudar a evitar subarrays desbalanceados.

**Listas Completamente Desordenadas:**
- Para listas completamente desordenadas, a escolha do pivô é crucial. Usar o primeiro ou último elemento como pivô pode resultar em subarrays desbalanceados e complexidade O(n²). Escolher o pivô como o elemento do meio é uma estratégia mais robusta.

Exemplos de arrays:
- **Array quase ordenado:** 6, 7, 10, 13, 17, 26, 27, 29, 42, 97, 78, 77, 75, 46
- **Array desordenado:** 26, 10, 78, 17, 77, 46, 29, 7, 27, 97, 6, 42, 13, 75

**Resultados em tempos de execução:**
- **Lista quase ordenada:**
  - Primeiro elemento como pivô: 0,000000 segundos
  - Último elemento como pivô: 0,000000 segundos
  - Elemento do meio como pivô: 0,000000 segundos
- **Lista desordenada:**
  - Primeiro elemento como pivô: 0,000000 segundos
  - Último elemento como pivô: 0,000000 segundos
  - Elemento do meio como pivô: 0,000000 segundos

---

### Comparação: Ternary Search x Binary Search

**Array ordenado:** 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47

**Chave a ser encontrada:** 29

- **Ternary Search:**
  - Resultado: Chave encontrada no índice 9
  - Tempo de execução: 0,000000 segundos

- **Binary Search:**
  - Resultado: Chave encontrada no índice 9
  - Tempo de execução: 0,000000 segundos

**Situações em que o Ternary Search é mais eficiente:**
- Em distribuições de dados que permitem que a busca em três partes resulte em uma redução mais rápida do espaço de busca.

---

### Comparação de Algoritmos de Busca

**Tabelas de desempenho:**

| Tamanho da Lista | Algoritmo              | Tempo de Execução (segundos) |
|-------------------|-----------------------|-----------------------------|
| **999**           | Binary Search         | 0,000000                   |
|                   | Interpolation Search  | 0,000000                   |
|                   | Jump Search           | 0,000000                   |
|                   | Exponential Search    | 0,000000                   |
| **4999**          | Binary Search         | 0,000000                   |
|                   | Interpolation Search  | 0,000000                   |
|                   | Jump Search           | 0,000000                   |
|                   | Exponential Search    | 0,000000                   |
| **9999**          | Binary Search         | 0,000000                   |
|                   | Interpolation Search  | 0,000000                   |
|                   | Jump Search           | 0,000000                   |
|                   | Exponential Search    | 0,000000                   |

---

### Comparação de Algoritmos de Ordenação

| Algoritmo       | Tempo de Execução (segundos) | Número de Comparações |
|------------------|-----------------------------|-----------------------|
| Shell Sort      | 0,000018                    | 14722                 |
| Merge Sort      | 0,000000                    | 8668                  |
| Selection Sort  | 0,004141                    | 499500                |
| Quick Sort      | 0,000000                    | 10699                 |
| Bucket Sort     | 0,000997                    | 51876                 |
| Radix Sort      | 0,000000                    | 999                   |

---

### Descrição de Algoritmos e Complexidades

#### **1. Binary Search**
- **Complexidade de Tempo:** O(logn)
- **Complexidade de Espaço:** O(1) para versão iterativa, O(logn) para versão recursiva
- **Requisitos:** Lista ordenada.

#### **2. Interpolation Search**
- **Complexidade de Tempo:** Melhor caso O(loglogn); Pior caso O(n)
- **Complexidade de Espaço:** O(1)
- **Eficiência:** Ideal para dados uniformemente distribuídos.

#### **3. Jump Search**
- **Complexidade de Tempo:** O(√n)
- **Complexidade de Espaço:** O(1)
- **Tamanho ideal do salto:** √n.

#### **4. Exponential Search**
- **Complexidade de Tempo:** O(logn)
- **Complexidade de Espaço:** O(1)
- **Eficiência:** Ótimo para listas grandes.

#### **5. Shell Sort**
- **Complexidade de Tempo:** Melhor caso O(nlogn); Pior caso O(n²)
- **Complexidade de Espaço:** O(1)
- **Destaque:** Escolha da sequência de intervalos é crucial.

#### **6. Merge Sort**
- **Complexidade de Tempo:** O(nlogn)
- **Complexidade de Espaço:** O(n)
- **Destaque:** Estratégia de "dividir para conquistar".

#### **7. Selection Sort**
- **Complexidade de Tempo:** O(n²)
- **Complexidade de Espaço:** O(1)

#### **8. Quick Sort**
- **Complexidade de Tempo:** Melhor caso O(nlogn); Pior caso O(n²)
- **Complexidade de Espaço:** O(logn)
- **Destaque:** Escolha do pivô afeta o desempenho.

#### **9. Bucket Sort**
- **Complexidade de Tempo:** Melhor caso O(n+k); Pior caso O(n²)
- **Complexidade de Espaço:** O(n+k)

#### **10. Radix Sort**
- **Complexidade de Tempo:** O(nk)
- **Complexidade de Espaço:** O(n+k)

```markdown
# Algoritmos de Busca e Ordenação

## 11. Ternary Search

- **Descrição**: Desenvolva o algoritmo Ternary Search para localizar um elemento em uma lista ordenada. Compare seu desempenho com o Binary Search.
- **Situações de Uso**: Identifique situações em que o Ternary Search seria mais eficiente que o Binary Search.

## 12. Comparação de Algoritmos de Busca

- **Descrição**: Construa uma tabela comparativa dos tempos de execução de Binary Search, Interpolation Search, Jump Search e Exponential Search em listas de tamanhos diferentes.

## 13. Comparação de Algoritmos de Ordenação

- **Descrição**: Ordene a mesma lista utilizando Shell Sort, Merge Sort, Selection Sort, Quick Sort, Bucket Sort e Radix Sort. Registre os tempos de execução e número de comparações realizadas.

## 14. Análise de Complexidade

- **Descrição**: Analise a complexidade de tempo e espaço de cada algoritmo de busca e ordenação listados.

### 1. Algoritmos de Busca

#### Binary Search

- **Complexidade de Tempo**: 
  - Melhor, pior e caso médio: O(log n), pois a busca é dividida pela metade a cada iteração.
- **Complexidade de Espaço**: 
  - O(1) para a versão iterativa; O(log n) para a versão recursiva devido à pilha de chamadas recursivas.
- **Requisitos**: A lista deve estar ordenada.

#### Interpolation Search

- **Complexidade de Tempo**: 
  - Melhor caso: O(log log n), quando os dados estão distribuídos uniformemente.
  - Pior caso: O(n), quando os dados estão desordenados ou mal distribuídos.
- **Complexidade de Espaço**: O(1), é um algoritmo in-place.
- **Eficiência**: Mais eficiente que o Binary Search quando os dados estão distribuídos uniformemente.

#### Jump Search

- **Complexidade de Tempo**: 
  - Melhor, pior e caso médio: O(√n).
- **Complexidade de Espaço**: O(1), é um algoritmo in-place.
- **Tamanho do salto**: O tamanho ideal do salto é √n.

#### Exponential Search

- **Complexidade de Tempo**: 
  - Melhor e pior caso: O(log n).
- **Complexidade de Espaço**: O(1), é um algoritmo in-place.
- **Eficiência**: Muito eficiente para listas grandes quando a posição do elemento é desconhecida.

### 2. Algoritmos de Ordenação

#### Shell Sort

- **Complexidade de Tempo**: 
  - Melhor caso: O(n log n), dependendo da sequência de intervalos.
  - Pior caso: O(n²), com uma sequência de intervalos ruim.
  - Caso médio: O(n³/2), em muitas sequências.
- **Complexidade de Espaço**: O(1), é um algoritmo in-place.
- **Observação**: A escolha da sequência de intervalos é fundamental.

#### Merge Sort

- **Complexidade de Tempo**: O(n log n) em todos os casos.
- **Complexidade de Espaço**: O(n), devido ao uso de espaço adicional para as sublistas durante a mesclagem.

#### Selection Sort

- **Complexidade de Tempo**: 
  - Melhor, pior e caso médio: O(n²).
- **Complexidade de Espaço**: O(1), é um algoritmo in-place.

#### Quick Sort

- **Complexidade de Tempo**: 
  - Melhor e caso médio: O(n log n).
  - Pior caso: O(n²), quando o pivô é escolhido inadequadamente.
- **Complexidade de Espaço**: O(log n), devido à pilha de chamadas recursivas.

#### Bucket Sort

- **Complexidade de Tempo**: 
  - Melhor caso: O(n + k), onde n é o número de elementos e k é o número de baldes.
  - Pior caso: O(n²), quando os elementos não são uniformemente distribuídos.
- **Complexidade de Espaço**: O(n + k).

#### Radix Sort

- **Complexidade de Tempo**: O(nk), onde n é o número de elementos e k é o número de dígitos.
- **Complexidade de Espaço**: O(n + k).

### Comparação Geral

- **Melhor Desempenho em Tempo de Busca**: Binary Search e Exponential Search para listas ordenadas.
- **Melhor Desempenho em Tempo de Ordenação**: Merge Sort e Quick Sort com O(n log n).
- **Melhor Desempenho em Espaço**: Shell Sort, Selection Sort, Jump Search, e Binary Search com O(1).
```
## 15. Busca e Ordenação em Strings

**Palavras ordenadas com Merge Sort:**
- aguia
- cachorro
- corvo
- gato
- gorila
- lula
- porco
- tatu

**Palavra 'porco' encontrada no índice 6.**

**Palavras ordenadas com Quick Sort:**
- aguia
- cachorro
- corvo
- gato
- gorila
- lula
- porco
- tatu

**Palavra 'porco' encontrada no índice 6.**

---

## 16. Aplicação Prática de Busca

**Livro encontrado:**
- **Título:** To Kill a Mockingbird
- **Autor:** Harper Lee
- **ISBN:** 9780061120084

---

## 17. Busca e Ordenação em Dados Reais

**Alunos ordenados por nota:**
- **Nome:** Pedro.M, **Nota:** 55
- **Nome:** JoÒo.P, **Nota:** 65
- **Nome:** Carlos.A, **Nota:** 70
- **Nome:** Maria.B, **Nota:** 75
- **Nome:** Ana.L, **Nota:** 82
- **Nome:** Juliana.B, **Nota:** 90
- **Nome:** Lucas.S, **Nota:** 95
- **Nome:** Fernanda.C, **Nota:** 99

**Aluno com nota 99 encontrado:**
- **Nome:** Fernanda.C, **Nota:** 99

---

## 18. Ordenação Estável e Instável

### Ordenação Estável
Um algoritmo de ordenação é **estável** se, quando dois elementos têm o mesmo valor, eles permanecem na mesma ordem relativa em que estavam originalmente. Ou seja, se um elemento A aparece antes de um elemento B na lista e ambos têm o mesmo valor, A ainda deve aparecer antes de B após a ordenação.

### Ordenação Instável
Um algoritmo de ordenação é **instável** se a ordem relativa dos elementos com valores iguais não for garantida.

### Exemplo de Implementação e Demonstração de Estabilidade em C

Vamos implementar alguns algoritmos de ordenação (estável e instável) e verificar a estabilidade:

#### **Bubble Sort (Estável)**
**Antes da ordenação:**
- Alice - 85
- Bob - 75
- Charlie - 85
- David - 90
- Eva - 75

**Após a ordenação (Bubble Sort - Estável):**
- Bob - 75
- Eva - 75
- Alice - 85
- Charlie - 85
- David - 90

---

#### **Selection Sort (Instável)**
**Antes da ordenação:**
- Alice - 85
- Bob - 75
- Charlie - 85
- David - 90
- Eva - 75

**Após a ordenação (Selection Sort - Instável):**
- Bob - 75
- Eva - 75
- Charlie - 85
- Alice - 85
- David - 90

## 19. Análise Visual dos Algoritmos  

Professor, eu não tenho muito conhecimento em Python, então eu tentei fazer em C, mas essa não é uma linguagem boa para fazer um gráfico, então não saiu como o senhor pediu. Mais eu tentei. Desculpa se não está como o senhor pediu.
