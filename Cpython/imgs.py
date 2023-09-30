import os
import requests
import xml.etree.ElementTree as ET
from urllib.parse import urlparse

# URL do arquivo XML
xml_url = "https://api.rule34.xxx/index.php?page=dapi&s=post&q=index&tags=firolian+ahri"

# Pasta de destino para salvar as imagens
pasta_destino = "/workspaces/UFT.cs/Cpython/img/"

# Crie a pasta de destino se ela não existir
if not os.path.exists(pasta_destino):
    os.makedirs(pasta_destino)

# Faça o download do arquivo XML
response = requests.get(xml_url)

# Verifique se a solicitação foi bem-sucedida
if response.status_code == 200:
    # Analise o XML
    root = ET.fromstring(response.text)
    
    # Itere sobre as tags que contêm os URLs das imagens
    for elemento in root.findall(".//file_url"):
        url_imagem = elemento.text
        
        # Parse a URL para obter o nome do arquivo
        nome_arquivo = os.path.basename(urlparse(url_imagem).path)
        
        # Defina o caminho completo para salvar a imagem
        caminho_imagem = os.path.join(pasta_destino, nome_arquivo)
        
        # Faça o download da imagem e salve-a na pasta de destino
        response_imagem = requests.get(url_imagem)
        if response_imagem.status_code == 200:
            with open(caminho_imagem, "wb") as arquivo:
                arquivo.write(response_imagem.content)
            print(f"Imagem {nome_arquivo} salva com sucesso.")
        else:
            print(f"Falha ao baixar a imagem {nome_arquivo}. Status code: {response_imagem.status_code}")
else:
    print(f"Falha ao baixar o arquivo XML. Status code: {response.status_code}")
