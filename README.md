# 🌧️ Projeto de Monitoramento de Bueiros com Arduino

Este projeto utiliza sensores e um display LCD para monitorar o **nível de água em bueiros**, com o objetivo de prevenir enchentes. Um **potenciômetro** simula o nível de chuva, influenciando o tempo de leitura do sistema.

## Integrantes

-Gabriel Thompson Freitas RM563126\
-João Pedro Sassarão De Carvalho RM562499\
-Juan Pablo Molina Molina RM564445

##  Objetivo

Detectar o nível da água em um bueiro e alertar com:
- LEDs de status (verde, amarelo, vermelho)
- Buzzer (alarme sonoro)
- Display LCD (exibição do nível da água)

## ⚙️ Componentes Utilizados

| Componente         | Função                                   |
|--------------------|-----------------------------------------|
| Arduino Uno        | Microcontrolador principal               |
| Potenciômetro      | Simula intesidade da chuva               |
| LEDs (3 cores)     | Indicação visual dos níveis de alerta    |
| Buzzer             | Emite alerta sonoro no nível crítico     |
| LCD I2C 16x2       | Exibe mensagens sobre o nível da água    |
| HC-SR04            | Sensor ultrassônico de distância         |


## 🧠 Lógica de Funcionamento

1. O **potenciômetro** simula a intensidade da chuva:
   - Baixa chuva → leituras mais espaçadas
   - Alta chuva → leituras mais frequentes

2. O **sensor ultrassônico** mede a distância da água até a tampa do bueiro:
   - **Distância ≤ 40 cm** → Nível crítico (LED vermelho + buzzer)
   - **Distância ≤ 100 cm** → Nível médio (LED amarelo)
   - **Distância > 100 cm** → Nível seguro (LED verde)

3. As informações são exibidas no **LCD** em tempo real.

## Projeto no Wokwi

[-Acesso o simulador](https://wokwi.com/projects/432241203851159553)


![](https://github.com/user-attachments/assets/7d17bb03-6934-4bf6-8996-030ad9f3194c)
