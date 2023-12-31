# Projeto Tartaruga
### Grupo ONE
- Bruno Castro Tomaz | TIA: 32150989
- Gustavo Saad Maluhy Andrade | TIA: 32173091
- Tomás Fiorelli Barbosa | TIA: 42122791

? COMO COMPILAR O PROGRAMA ?

Para compilar o programa, primeiramente é necessário instalar a biblioteca que ultilizamos para gerar valores com alta precisão (no caso, a biblioteca GMP), se já não estiver intalado em sua máquina.

```sudo dnf install gmp-devel```

A outra biblioteca utilizada foi a OpenMP, comumente usada em projetos que envolvem processamento paralelo em C. Ela costuma estar instalada por padrão nos sistemas operacionais, mas caso não esteja, segue abaixo o código que deve ser colocado no terminal:

```sudo dnf install libgomp```

Em seguida, deve-se inserir o código de compilação do arquivo C com o gcc:

```gcc codigo.c -o arquivo_de_saida -lgmp -fopenmp```

? COMO EXECUTAR O PROGRAMA ?

Para executar o programa é necessário inserir o comando abaixo:

```./nome_do_arquivo_compilado```

As variáveis que podem ser alteradas para aumentar a precisão do valor gerado são alteráveis apenas na edição do código

? COMO COMPROVAR O RESULTADO ?

Além do código principal, foi desenvolvido um pequeno algoritmo em Python para realizar a comparação do número que geramos com o valor apresentado no site <https://apod.nasa.gov/htmltest/gifcity/e.1mil>, com 1 milhão de digitos. O nosso número gerado será escrito num arquivo ```output.txt```, e ele será comparado com o arquivo ```nasa.txt```.

Para executar esse código, basta inserir no terminal o comando abaixo:

```python "check.py"```

## Resultados

Foram obtidos dois resultados que serão apresentados abaixo. O primeiro foi gerado a partir do ambiente da AWS, enquanto que o segundo foi executado na máquina pessoal do integrante Gustavo (que possui uma CPU Ryzen 7 Serie 5000 | 8 CORE 16 THREADS).

### AWS
![](Capturas/TempoAWS.png)

N = 1,000 (mil)

PRECISION = 1,000,000 (um milhão)

Primeira casa decimal diferente encontrada: 90,317

Tempo: aprox. 44 segundos

### Máquina pessoal

![](Capturas/TempoPessoal.png)

N = 100,000 (cem mil)

PRECISION = 2,000,000 (dois milhões)

Primeira casa decimal diferente encontrada: 456,981

Tempo: aprox. 264 segundos (4 minutos e 26 segundos)
