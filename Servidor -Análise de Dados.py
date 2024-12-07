import paho.mqtt.client as mqtt
import pandas as pd
from sklearn.ensemble import IsolationForest
import json

# Configuração do MQTT
BROKER = "BROKER_IP"
TOPIC = "machine/data"

# Função para processamento
def on_message(client, userdata, message):
    data = json.loads(message.payload)
    df = pd.DataFrame([data])
    anomalies = model.predict(df[['temperature', 'vibration_x', 'vibration_y', 'vibration_z']])
    if -1 in anomalies:
        print("Anomalia detectada!")

# Configurando modelo
model = IsolationForest(contamination=0.1)
# Dados históricos para treinamento (exemplo)
historical_data = pd.DataFrame([...])
model.fit(historical_data)

client = mqtt.Client()
client.on_message = on_message
client.connect(BROKER, 1883, 60)
client.subscribe(TOPIC)
client.loop_forever()
