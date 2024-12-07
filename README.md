# Plataforma de Manutenção Preditiva para Equipamentos

## Descrição  
Uma solução IoT para monitoramento de máquinas industriais. Sensores capturam dados de vibração e temperatura, enviados para um servidor que utiliza algoritmos de aprendizado de máquina para prever falhas e emitir alertas preditivos.

## Funcionalidades  
- Coleta de dados em tempo real.  
- Detecção de anomalias com machine learning.  
- Interface web para visualização de relatórios.  

## Arquitetura  
1. **Dispositivos IoT**: Sensores conectados ao ESP32.  
2. **Transmissão MQTT**: Comunicação entre dispositivos e servidor.  
3. **Análise no Servidor**: Processamento de dados e predição de falhas.  

## Materiais Utilizados  
- ESP32, ADXL345, DS18B20.  
- Servidor MQTT (Mosquitto).  
- Python com bibliotecas: `scikit-learn`, `pandas`, `numpy`.  

## Como Usar  
1. Configure as credenciais de Wi-Fi no código do ESP32.  
2. Suba o código no ESP32 e conecte os sensores.  
3. Configure o servidor MQTT e execute o código de análise.  

## Contribuição  
Contribuições são bem-vindas! Envie um pull request ou abra uma issue.  
