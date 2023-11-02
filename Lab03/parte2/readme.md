
## Valor real de pi
```
mutexes
com n = 100000000 termos,
com 5 threads,
pi estimado = 3.141592643589817157590005081147
```

## Sem mutexes
```
com race condition
com n = 100000000 termos,
com 5 threads,
pi estimado = 3.141592643589817157590005081147
```

## Com mutexes
```

mutexes
com n = 100000000 termos,
com 5 threads,
pi estimado = 3.141592643589817157590005081147
```

## Explicações

Uma solução utilizando mutex é apresentada no codigo pi_mutex.c .Nessa solução, um mutex é utilizado para garantir que apenas uma thread por vez possa acessar e atualizar a variável global "sum". Isso elimina as condições de corrida e garante que os cálculos das threads sejam realizados de forma coordenada e segura.

A principal diferença entre os dois códigos é a presença do mutex no primeiro código. Isso faz com que as threads sejam sincronizadas e evita que elas acessem a variável "sum" simultaneamente, o que poderia causar divergências nos valores calculados. No segundo código, não há essa sincronização, o que significa que as threads podem atualizar a variável "sum" concorrentemente, resultando em condições de corrida.

As causas das divergências nos valores codigo sem mutex são devidas às condições de corrida. Várias threads tentam acessar e atualizar a variável "sum" ao mesmo tempo, e a ordem em que essas operações ocorrem não é determinística. Isso significa que o resultado final pode variar de uma execução para outra, dependendo de como as threads concorrentes interagem entre si. Em resumo, as divergências acontecem devido à falta de sincronização adequada entre as threads que acessam a variável compartilhada.
