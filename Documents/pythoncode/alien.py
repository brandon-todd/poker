import pygame
from pygame.sprite import Sprite
from Settings import GameSettings

class Alien(Sprite):
    def __init__(self, ai_game):
        super().__init__()
        self.screen = ai_game.screen
        self.setting = GameSettings()
        self.image = pygame.image.load('alienship.png')
        self.image = pygame.transform.scale(self.image, (50,50))
        self.rect = self.image.get_rect()
        self.settings = ai_game.settings

        self.rect.x = self.rect.width
        self.rect.y = self.rect.height

        self.x = float(self.rect.x)
    
    def update(self):
        self.x += (self.settings.fleet_direction)
        self.rect.x = self.x
        
    def check_edges(self):
        screen_rect = self.setting.screen_width
        if self.rect.right >= screen_rect or self.rect.left <= 0:
            return True
