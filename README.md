# StreamDeck
**Introdução**
Você já deve ter notado que alguns streamers tornam suas transmissões mais dinâmicas e impactantes do que outros, certo? É provável que por trás disso esteja um gadget de grande impacto: o Stream Deck.
---
Um stream-deck feito com arduino leonardo
---
**O que é um Stream Deck e o que Faz?**
Stream Deck é um pequeno painel de controle com botões personalizáveis, Usando este dispositivo, você pode inserir efeitos visuais e sonoros durante a transmissão, acessar atalhos e comandos no jogo, controlar funções da plataforma como silenciar ou ligar o microfone no Discord ou programar mensagens a serem enviadas em bate-papos do Twitch. Neste projeto o foco vai ser a adição de atalhos pré-programados.
---
**Materiais Necessários para o Projeto Stream Deck com Arduino leonardo**
- Arduino Leonardo
- 6 Chaves Botão R13-507
- Protoboard
- Jumpers
- Resistores pull-up (opcional)
---
***Montagem***
- Cada botão deve ser conectado a um dos pinos digitais do Arduino (pinos 2, 3, 4, 5 e 6) de acordo com o código.

- O outro terminal de cada botão deve ser conectado ao GND (terra), pois o código utiliza resistores pull-up internos, então, quando o botão é pressionado, ele força o pino a ir para LOW (0V).

1. Conecte um terminal de cada botão aos pinos 2, 3, 4, 5 e 6 no Arduino.

2. Exemplo: conecte o pino de saída de um botão ao pino 2 do Arduino, outro botão ao pino 3, e assim por diante até o pino 6.
Conecte o outro terminal de cada botão ao GND (terra).

3. Todos os botões terão um terminal comum que se conectará ao pino GND do Arduino.