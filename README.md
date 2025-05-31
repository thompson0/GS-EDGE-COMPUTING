# 🌧️ Sistema de Monitoramento de Bueiros com Arduino

Este projeto simula um sistema de monitoramento de enchentes em bueiros, utilizando sensores e componentes eletrônicos comuns, ideal para testes no simulador [Wokwi](https://wokwi.com/) ou para uso em protótipos reais.

##  Objetivo

Detectar o nível da água em um bueiro e alertar com:
- LEDs de status (verde, amarelo, vermelho)
- Buzzer (alarme sonoro)
- Display LCD (exibição do nível da água)

## Componentes Utilizados

| Componente         | Função                                  |
|--------------------|------------------------------------------|
| Arduino Uno        | Microcontrolador principal               |
| Potenciômetro      | Simulação do sensor de nível de água     |
| LEDs (3 cores)     | Indicação visual de nível (baixo, médio, alto) |
| Buzzer             | Alarme sonoro em caso crítico            |
| LCD I2C 16x2       | Exibição em tempo real do nível da água  |
| HC-SR04 (simulado) | Sensor ultrassônico de distância (não usado no cálculo neste projeto, mas incluído) |

## Funcionamento

- **Potenciômetro** simula a altura da água, convertida para uma distância entre **2 e 100 cm** com `map()`.
- De acordo com a distância, o sistema classifica o nível da água:
  - **Bom (baixo)**: distância < 60 cm → LED verde aceso.
  - **Médio**: entre 60 e 80 cm → LED amarelo aceso.
  - **Crítico**: ≥ 80 cm → LED vermelho e buzzer ativados.
- O **LCD** mostra mensagens como “Nível de água bom”, “médio” ou “alto”, com a distância.


## Projeto no Wokwi

[-Acesso o simulador](https://wokwi.com/projects/432241203851159553)


![](https://github.com/user-attachments/assets/7d17bb03-6934-4bf6-8996-030ad9f3194c)



