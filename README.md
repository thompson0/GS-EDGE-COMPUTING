# 🌧️ Sistema de Monitoramento de Bueiros com Arduino

Este projeto simula um sistema de monitoramento de enchentes em bueiros, utilizando sensores e componentes eletrônicos básicos, ideal para testes no simulador [Wokwi](https://wokwi.com/) ou para uso em protótipos reais.

## Integrantes



## Objetivo

Detectar o nível da água em um bueiro e emitir alertas por meio de:  
- LEDs de status (verde, amarelo e vermelho)  
- Buzzer (alarme sonoro)  
- Display LCD (exibição do nível da água em tempo real)

## Componentes Utilizados

| Componente         | Função                                   |
|--------------------|-----------------------------------------|
| Arduino Uno        | Microcontrolador principal               |
| Potenciômetro      | Simula o sensor de nível de água         |
| LEDs (3 cores)     | Indicação visual dos níveis de alerta    |
| Buzzer             | Emite alerta sonoro no nível crítico     |
| LCD I2C 16x2       | Exibe mensagens sobre o nível da água   |
| HC-SR04 (simulado) | Sensor ultrassônico de distância (incluso para futuras melhorias) |

## Funcionamento

- O **potenciômetro** simula o nível de água, convertendo seu valor para uma distância entre **2 e 100 cm** usando `map()`.  
- Conforme a distância simulada, o sistema define o nível do bueiro:  
  - **Bom (baixo)**: distância maior que 80 cm — LED verde aceso.  
  - **Médio**: entre 60 e 80 cm — LED amarelo aceso.  
  - **Alto (crítico)**: menor ou igual a 60 cm — LED vermelho aceso e buzzer acionado.  
- O **LCD** mostra mensagens como “Nível de água bom”, “médio” ou “alto”, acompanhadas do valor da distância.

## Projeto no Wokwi

[Acesse o simulador aqui](https://wokwi.com/projects/432241203851159553)
