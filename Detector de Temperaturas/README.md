# 🌊 Sistema de Controle de Temperatura para Piscina
![Detector de Temperatura (1)](https://github.com/user-attachments/assets/3e5ae330-0c15-40f8-a121-408f6cd6048a)

## 📜 Descrição do Projeto

Este projeto visa desenvolver um **sistema de controle de temperatura** para uma piscina utilizando componentes eletrônicos no **Tinkercad**. O sistema simula o controle manual da temperatura da água através de um **potenciômetro**, monitorando e ajustando a temperatura com **LEDs indicadores** e um **buzzer** para alertas.

## 🛠️ Componentes Utilizados

- **Potenciômetro**: Ajusta manualmente a temperatura da piscina.
- **Resistor LDR**: Simula o elemento de aquecimento da piscina, cuja resistência varia conforme a intensidade luminosa.
- **LEDs**:
  - 🟢 **Verde**: Indica que a temperatura está dentro da faixa ideal.
  - 🟡 **Amarelo**: Sinaliza que a temperatura está no limite superior da faixa ideal.
  - 🔴 **Vermelho**: Acende quando a temperatura ultrapassa o limite seguro, indicando sobreaquecimento.
- **Buzzer**: Emite um alerta sonoro em caso de sobreaquecimento (opcional).
- **Botão de Ligar/Desligar**: Controla o estado do sistema de aquecimento.
- 💡 **LED Transparente**: Indica quando o sistema está ligado.

## ⚙️ Funcionamento do Sistema

1. **Controle de Temperatura**:
   - O potenciômetro permite ajustar a temperatura da piscina. A variação do potenciômetro representa a mudança na temperatura da água.

2. **Aquecimento da Piscina**:
   - O LDR simula o aquecimento da piscina, ajustando sua resistência conforme a intensidade luminosa.

3. **Indicadores de Temperatura**:
   - **LED Verde**: Temperatura ideal (20°C a 30°C).
   - **LED Amarelo**: Temperatura no limite superior (31°C a 35°C).
   - **LED Vermelho**: Temperatura crítica (acima de 35°C).

4. **Controle do Sistema de Aquecimento**:
   - O botão liga/desliga controla o sistema. Um LED transparente indica quando o sistema está ativo.

## 🌡️ Limites de Temperatura

- **Temperatura Ideal**: 20°C a 30°C (LED Verde)
- **Temperatura Limite**: 31°C a 35°C (LED Amarelo)
- **Temperatura Crítica**: Acima de 35°C (LED Vermelho)

## 📌 Observações

- É necessário mapear os valores lidos do LDR e do potenciômetro para os valores correspondentes da faixa de temperatura.

## 🚀 Como Executar

1. Clone este repositório.
2. Abra o projeto no Tinkercad.
3. Conecte os componentes conforme o diagrama fornecido.
4. Ajuste o potenciômetro e observe os LEDs e o buzzer em ação.

## 🤝 Contribuições

Sinta-se à vontade para contribuir com melhorias ou sugestões!

## 📄 Licença

Este projeto está licenciado sob a Licença MIT.
