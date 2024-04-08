import pygame
import random
import sys

# Initialize Pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 800, 600
FPS = 60

# Colors
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GRAY = (169, 169, 169)

# Create the game window
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Car Racing Game")

clock = pygame.time.Clock()

# Load car image
car_image = pygame.image.load("car.png")  # Replace "car.png" with your car image file path
car_width, car_height = car_image.get_rect().size
car_x = (WIDTH - car_width) // 2
car_y = HEIGHT - car_height - 30
car_speed = 5

# Other car properties
other_car_width = 60
other_car_height = 100
other_car_speed = 7
other_cars = []

# Font
font = pygame.font.Font(None, 36)

# Functions
def draw_other_cars():
    for car in other_cars:
        pygame.draw.rect(screen, WHITE, car)

def display_score(score):
    score_text = font.render("Score: " + str(score), True, WHITE)
    screen.blit(score_text, (10, 10))

def game_over(score):
    game_over_text = font.render("Game Over. Final Score: " + str(score), True, WHITE)
    screen.blit(game_over_text, (WIDTH // 2 - 200, HEIGHT // 2 - 50))

# Game loop
running = True
score = 0
while running:
    screen.fill(GRAY)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT] and car_x > 0:
        car_x -= car_speed
    if keys[pygame.K_RIGHT] and car_x < WIDTH - car_width:
        car_x += car_speed

    # Generate other cars
    if len(other_cars) < 3:
        x = random.randint(0, WIDTH - other_car_width)
        y = random.randint(-HEIGHT, 0)
        other_cars.append(pygame.Rect(x, y, other_car_width, other_car_height))

    # Move other cars and check collision
    for car in other_cars:
        car.y += other_car_speed
        if car.colliderect(pygame.Rect(car_x, car_y, car_width, car_height)):
            running = False

        if car.y > HEIGHT:
            score += 1
            other_cars.remove(car)

    screen.blit(car_image, (car_x, car_y))
    draw_other_cars()
    display_score(score)

    if not running:
        game_over(score)
        pygame.display.flip()
        pygame.time.wait(2000)  # Display the final score for 2 seconds before closing
        break

    pygame.display.flip()
    clock.tick(FPS)

pygame.quit()
sys.exit()


