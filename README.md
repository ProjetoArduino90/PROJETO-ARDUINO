# PROJETO-ARDUINO

Este projeto utiliza um Arduino para controlar um robô seguidor de linha simples com dois sensores (direito e esquerdo) e dois motores DC controlados por ponte H.

Componentes Utilizados
Arduino UNO (ou compatível)
2 Sensores infravermelhos (IR) para detecção de linha
2 Motores DC com driver ponte H (L298N, por exemplo)
Potenciômetro (opcional, simulado com valor fixo no código)
Fios de conexão e fonte de alimentação adequada

Funcionamento
O robô segue uma linha no chão com base nos sensores IR:
Ambos sensores detectam linha (branco): robô para
Sensor esquerdo detecta linha (branco), direito detecta faixa (preto): vira para a direita
Sensor direito detecta linha (branco), esquerdo detecta faixa (preto): vira para a esquerda
Ambos detectam faixa (preto): segue em frente

Explicação do Código
Define os pinos de controle dos motores (IN1 a IN4, ENA, ENB)

Define os pinos dos sensores (SensorE e SensorD)

Inicializa os motores parados e configura os pinos no setup()

No loop(), chama a função modoSeguidorLinha() continuamente

A função modoSeguidorLinha() lê os sensores e decide a movimentação:

moverFrente()
moverEsquerda()
moverDireita()
pararMotores()

Observações

O valor definido em `#define POT 180` controla a velocidade dos motores (PWM).
Os sensores IR devem estar configurados para:
Retornar `LOW` ao detectar **preto (linha)
Retornar `HIGH` ao detectar **branco (fundo)
