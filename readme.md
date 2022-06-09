<h1 align="center"><strong>FT_PRINTF - @42SP</strong></h1>
    
<p align="center">Esse projeto é sobre desenvolver uma versão da função Printf da biblioteca stdio do C</p>
     
<p align="center"><a href="https://www.42sp.org.br/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=SP& color=000&style=for-the-badge&logo=42"></a></p>

<p align="center"><img src="https://game.42sp.org.br/static/assets/achievements/ft_printfe.png"> </p>

<p align="center">Nota: <strong>100/100</strong> ✔️ </p>
       
<h2 align="center"><strong>Oque é a FT_PRINTF?</strong></h2>
      
> Esse é o terceiro projeto do curriculo da [42SP](https://www.42sp.org.br/). Consiste em criar uma versão propria da função printf do C.

### **Como funciona a FT_PRINTF_F**

A função printf trabalha com formatação de textos e os imprime no stdout (saida padrão). Ela recebe como argumentos um texto para formatar e uma lista com os argumentos que serão usados nessa formatação.

Para saber como formatar é preciso usar alguns caracteres especiais no texto, a função trabalha substituindo esses caracteres pelos argumentos.

Exemplo:

```c
    printf("%s %s %s %s %d", "Qual a resposta para a vida", "a verdade", "e o universo?", "\nResposta: ", 42);

    // Resultado:
    // Qual a resposta para a vida a verdade e o universo?
    // Resposta: 42
```

### **Oque são os caracteres especiais da FT_PRINTF?**

Os caracteres especiais definem o que será impresso no stdout. Eles são os seguintes:

- **%c** -> Imprime um caractere
- **%s** -> Imprime uma string
- **%d** -> Imprime um inteiro
- **%u** -> Imprime um inteiro sem sinal
- **%x** -> Imprime um inteiro em formato hexadecimal
- **%X** -> Imprime um inteiro em formato hexadecimal com letras maiusculas
- **%p** -> Imprime um ponteiro em formato hexadecimal
- **%%** -> Imprime um caractere %

Existe tambem o caractere **%f** que imprime um float, mas ele não foi implementado aqui.

### **Oque são argumentos variadicos?**

Como a função FT_PRINTF pode receber uma lista de argumentos variados é neessario uma maneira de conseguir lidar com eles, passando 1 ou 100 argumentos a função precisa saber converter um por um.

Para isso é utilizado um conceito chamado de **argumentos variadicos**. Eles são especificados como **"..."**. Para se poder usar esse argumentos é necessario que a função tenha pelo menos uma variavel definida antes deles em sua assinatura e eles sejam sempre os ultimos.

A manipulação desses argumentos é feita atraves de algumas funções da biblioteca **stdarg.h**.

## Funções da biblioteca stdarg.h

- **va_list** -> Estrutura que representa uma lista de argumentos variados. 

```c
  va_list arguments
```
- **va_start()** -> É a função que inicializa a estrutura **va_list**. Ela deve receber como parametro a variavel do tipo **va_list** e a variavel que vem imediamente antes da lista de argumentos variados (nesse caso o texto).

```c
  va_start(arguments, format)
```
- **va_arg()** -> É a função que retorna o proximo argumento da lista de argumentos variados. Ela deve receber como parametro a variavel do tipo **va_list** e o tipo do argumento que se deseja retornar.

```c
  va_arg(arguments, type)
```
- **va_end()** -> É a função que finaliza a estrutura **va_list**. Limpando ela corretamente na memoria. Ela deve receber como parametro a variavel do tipo **va_list**.

```c
  va_end(arguments)
```

### **Como utilizar**

Baixe o repositorio e execute o seguinte comando no diretorio:

```
$ make
```

Sera gerado um arquivo chamado **libftprintf.a**. Agora você pode utilizar as funções em seus programas.

Para compilar adicione o seguinte header no seu programa:

```c
    #include "libftprintf.h"
```

E depois compile da seguinte forma.

```
$ gcc -Wall -Wextra -Werror libftprintf.a main.c - nomeDoPrograma
```

Para limpar os arquivo objetos gerados ao compilar a biblioteca só utiliar o comando

```
$ make clean
```