import requests
from bs4 import BeautifulSoup
import os

# URL da página de pesquisa
url = 'https://exemplo.com/pesquisa?q=gatos'

# Pasta onde as imagens serão salvas
pasta_destino = 'imagens_gatos'

# Certifique-se de que a pasta de destino exista
if not os.path.exists(pasta_destino):
    os.makedirs(pasta_destino)

# Enviar uma solicitação HTTP para a página de pesquisa
response = requests.get(url)

# Verificar se a solicitação foi bem-sucedida
if response.status_code == 200:
    # Parsear o HTML da página
    soup = BeautifulSoup(response.text, 'html.parser')

    # Encontrar todas as tags de imagem
    img_tags = soup.find_all('img')

    # Iterar sobre as tags de imagem e fazer o download das imagens
    for img_tag in img_tags:
        img_url = img_tag.get('src')

        # Certifique-se de que a URL da imagem não é vazia
        if img_url:
            # Obtenha o nome do arquivo da URL da imagem
            img_nome = os.path.join(pasta_destino, os.path.basename(img_url))

            # Faça o download da imagem
            with open(img_nome, 'wb') as img_arquivo:
                img_response = requests.get(img_url)
                img_arquivo.write(img_response.content)

            print(f'Imagem baixada: {img_nome}')
else:
    print('Falha ao acessar a página de pesquisa')
