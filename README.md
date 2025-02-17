# ft_printf - 42 Cursus Project  

## Descrizione  
**ft_printf** è una reimplementazione della funzione standard `printf()` della libreria C. Questo progetto permette di approfondire la gestione di funzioni con un numero variabile di argomenti e di migliorare la gestione della memoria e la modularità del codice in C.  

## Funzionalità  
La funzione `ft_printf()` offre le seguenti conversioni di formattazione:  

- **%c** → Stampa un singolo carattere  
- **%s** → Stampa una stringa  
- **%p** → Stampa un puntatore in formato esadecimale  
- **%d** → Stampa un numero intero decimale  
- **%i** → Stampa un numero intero  
- **%u** → Stampa un numero intero senza segno  
- **%x** → Stampa un numero in formato esadecimale (minuscolo)  
- **%X** → Stampa un numero in formato esadecimale (maiuscolo)  
- **%%** → Stampa un carattere `%`   
  
## Compilazione e Utilizzo  
Per compilare la libreria, eseguire il seguente comando:  

```sh  
make  
```  

Questo genererà il file `libftprintf.a`. Per utilizzarlo in un programma, compilarlo con:  

```sh  
gcc -Wall -Wextra -Werror your_program.c libftprintf.a -o your_program  
```  

Esempio di utilizzo:  

```c  
#include "ft_printf.h"  

int main() {  
    ft_printf("Hello, %s! You have %d new messages.\n", "Alice", 5);  
    return 0;  
}  
```  

## Requisiti  
- Il codice deve rispettare la Norm di 42  
- Non deve generare memory leaks  
- Non deve usare funzioni non autorizzate (come `printf`, `sprintf`, etc.)  

## Licenza  
Questo progetto è parte del curriculum di 42 e segue le regole della scuola per la condivisione e l'utilizzo del codice.
