import pygame
import sys

# --- Constantes ---
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
FPS = 60

# Cores em RGB (Vermelho, Verde, Azul)
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
BLUE = (0, 0, 255)

def main():
    # 1. Inicializa o Pygame (módulos internos, áudio, vídeo, etc.)
    pygame.init()

    # 2. Configura a tela (display)
    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
    pygame.display.set_caption("Exemplo Completo de Pygame")

    # 3. Configura o relógio para controlar o FPS (Frames Por Segundo)
    clock = pygame.time.Clock()

    # 4. Configura fontes para renderização de texto
    font = pygame.font.SysFont(None, 36)

    # 5. Variáveis do Jogo
    # Jogador
    player_size = 50
    player_x = SCREEN_WIDTH // 2
    player_y = SCREEN_HEIGHT // 2
    player_speed = 5

    # Objeto/Inimigo quicando
    bouncing_x = 100
    bouncing_y = 100
    bouncing_speed_x = 4
    bouncing_speed_y = 4
    bouncing_radius = 20

    score = 0

    # --- Loop Principal do Jogo ---
    running = True
    while running:
        # --- A. Tratamento de Eventos ---
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            # Exemplos de outros eventos:
            # if event.type == pygame.KEYDOWN:
            #     if event.key == pygame.K_SPACE:
            #         print("Espaço pressionado!")

        # --- B. Atualização do Estado do Jogo (Lógica) ---
        
        # Pega as teclas que estão pressionadas neste frame
        keys = pygame.key.get_pressed()
        
        # Movimentação do jogador com limites da tela
        if keys[pygame.K_LEFT] and player_x > 0:
            player_x -= player_speed
        if keys[pygame.K_RIGHT] and player_x < SCREEN_WIDTH - player_size:
            player_x += player_speed
        if keys[pygame.K_UP] and player_y > 0:
            player_y -= player_speed
        if keys[pygame.K_DOWN] and player_y < SCREEN_HEIGHT - player_size:
            player_y += player_speed

        # Move o círculo
        bouncing_x += bouncing_speed_x
        bouncing_y += bouncing_speed_y

        # Colisão do círculo com as bordas da tela
        if bouncing_x - bouncing_radius <= 0 or bouncing_x + bouncing_radius >= SCREEN_WIDTH:
            bouncing_speed_x = -bouncing_speed_x
        if bouncing_y - bouncing_radius <= 0 or bouncing_y + bouncing_radius >= SCREEN_HEIGHT:
            bouncing_speed_y = -bouncing_speed_y

        # Aumentar pontuação
        score += 1

        # --- C. Desenho/Renderização ---
        
        # 1. Limpa a tela preenchendo com uma cor de fundo
        screen.fill(BLACK)

        # 2. Desenha o jogador (Retângulo)
        pygame.draw.rect(screen, BLUE, (player_x, player_y, player_size, player_size))

        # 3. Desenha o obstáculo (Círculo)
        pygame.draw.circle(screen, RED, (bouncing_x, bouncing_y), bouncing_radius)

        # 4. Renderiza e desenha texto
        # "True" aqui significa usar antialiasing para deixar o texto suave
        score_text = font.render(f"Pontos: {score // FPS}", True, WHITE)
        screen.blit(score_text, (10, 10))

        instruction_text = font.render("Use as setas para mover. Fuja do vermelho!", True, WHITE)
        screen.blit(instruction_text, (10, 50))

        # --- D. Atualiza o Display ---
        pygame.display.flip()

        # --- E. Controle de Framerate ---
        # Garante que o loop vai rodar na velocidade máxima do FPS
        clock.tick(FPS)

    # Quando sai do loop, precisamos finalizar o Pygame e fechar o programa
    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()