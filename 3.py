import pygame
import sys

# Initialize Pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 800, 600
FPS = 60

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GREEN = (34, 139, 34)
RED = (255, 0, 0)

# Create the game window
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Hill Climbing Car Game")

clock = pygame.time.Clock()

# Load car image
car_image = pygame.image.load("C:\Users\Aditi\Downloads\5TH sem\images.jpeg")
car_width, car_height = car_image.get_rect().size
car_x = (WIDTH - car_width) // 2
car_y = HEIGHT - car_height - 30
car_speed = 5
car_acceleration = 0.2
car_friction = 0.1
car_dx = 0

# Physics
gravity = 0.6
slope = 0.5

# Font
font = pygame.font.Font(None, 36)

# Functions
def draw_background():
    screen.fill(GREEN)
    pygame.draw.rect(screen, BLACK, (0, HEIGHT // 2, WIDTH, HEIGHT // 2))

def draw_car(x, y):
    screen.blit(car_image, (x, y))

def show_score(score):
    score_text = font.render("Score: " + str(score), True, WHITE)
    screen.blit(score_text, (10, 10))

def show_game_over():
    game_over_text = font.render("Game Over", True, WHITE)
    screen.blit(game_over_text, (WIDTH // 2 - 100, HEIGHT // 2 - 50))
    retry_text = font.render("Press 'R' to play again or 'Q' to quit", True, WHITE)
    screen.blit(retry_text, (WIDTH // 2 - 220, HEIGHT // 2 + 20))

# Game loop
score = 0
game_over = False
running = True
while running:
    screen.fill(WHITE)

    if not game_over:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    car_dx -= car_acceleration
                elif event.key == pygame.K_RIGHT:
                    car_dx += car_acceleration

        car_x += car_dx

        # Simulate hill climbing physics
        if car_y < HEIGHT - car_height - 30:
            car_y += gravity
            car_x += slope * car_dx

        if car_x > WIDTH - car_width:
            car_x = WIDTH - car_width
        elif car_x < 0:
            car_x = 0

        # Calculate score (example: based on distance traveled)
        score += 1

    draw_background()
    draw_car(car_x, car_y)
    show_score(score)

    if game_over:
        show_game_over()

    pygame.display.flip()
    clock.tick(FPS)

    # Game over condition
    if car_y >= HEIGHT - car_height - 30:
        game_over = True

    # Game over handling
    while game_over:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
                game_over = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_r:  # Retry
                    score = 0
                    car_x = (WIDTH - car_width) // 2
                    car_y = HEIGHT - car_height - 30
                    car_dx = 0
                    game_over = False
                elif event.key == pygame.K_q:  # Quit
                    running = False
                    game_over = False

pygame.quit()
sys.exit()
