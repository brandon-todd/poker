import sys
import pygame
from Settings import GameSettings
from ship import Ship
from bullet import Bullet
from alien import Alien
from pygame.sprite import Sprite
from time import sleep
from game_stats import GameStats 
#from stars import Stars

class AlienInvasion:
    def __init__(self):
        pygame.init()
        pygame.display.set_caption("Alien Invasion")
        self.settings = GameSettings()
        self.screen = pygame.display.set_mode((self.settings.screen_width, self.settings.screen_height))
        self.ship = Ship(self)
        self.aliens = pygame.sprite.Group()
        self.bullet = pygame.sprite.Group()
        #self.stars = pygame.sprite.Group()
        #self.create_stars()
        self.create_fleet()
        self.stats = GameStats(self)

    def ship_hit(self):
        if self.stats.ships_left > 0:
            self.stats.ships_left -=1
            self.aliens.empty()
            self.bullet.empty()

            self.create_fleet()
            self.ship.center_ship()
            sleep(0.5)
        else:
            self.stats.game_active = False

    def update_screen(self):
        self.screen.fill(self.settings.bg_color)
        #self.stars.draw(self.screen)     
        self.aliens.draw(self.screen)
        self.ship.blitme()
        for bullets in self.bullet.sprites():
            bullets.draw_bullet()    
        
        pygame.display.flip()
        
    def check_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                self.check_keydown_events(event)
            elif event.type == pygame.KEYUP:
                self.check_keyup_events(event)
    def create_fleet(self):
        alien = Alien(self)
        alien_width, alien_height = alien.rect.size
        ship_height = self.ship.rect.height
        available_space_y = (self.settings.screen_height-(3*alien_height)-ship_height)
        number_rows = available_space_y //(2*alien_height)
        available_space_x = self.settings.screen_width - (2*alien_width)
        number_aliens_x = available_space_x // (2*alien_width)
        for row_number in range(number_rows):
            for alien_number in range(number_aliens_x):
                self.create_alien(alien_number, row_number)
    """def create_stars(self):
        star = Stars(self)
        star_width, star_height = star.rect.size
        available_space_y = self.settings.screen_height-2*star_height
        available_space_x = self.settings.screen_width-2*star_width
        number_rows = available_space_y // (star_height)
        number_collumns = available_space_x // (star_width)
        for row_number in range(number_rows):
            for collumn_number in range(number_collumns):
                self.create_star(collumn_number, row_number)"""
    
    """def create_star(self, collumn_number, row_number):
        star = Stars(self)
        star_width, star_height = star.rect.size
        star.rect.x = star.rect.width + 2*star_width*collumn_number
        star.rect.y = star.rect.height +2*star_height*row_number
        self.stars.add(star)"""


    def check_aliens_bottom(self):
        screen_rect = self.screen.get_rect()
        for alien in self.aliens.sprites():
            if alien.rect.bottom >= screen_rect.bottom:
                self.ship_hit()
                break
    

    def create_alien(self, alien_number, row_number):
        alien = Alien(self)
        alien_width, alien_height = alien.rect.size
        alien.x = alien_width + 2 * alien_width * alien_number
        alien.rect.y = alien.rect.height + 2 * alien.rect.height * row_number
        alien.rect.x = alien.x
        self.aliens.add(alien)

    def check_fleet_edges(self):
        for alien in self.aliens.sprites():
            if alien.check_edges():
                self.change_fleet_direction()
                break


    def change_fleet_direction(self):
        for alien in self.aliens.sprites():
            alien.rect.y += self.settings.fleet_drop_speed
        self.settings.fleet_direction *= (-1) 
    
    def update_aliens(self):
        self.check_fleet_edges()
        self.aliens.update()
        if pygame.sprite.spritecollideany(self.ship, self.aliens):
            self.ship_hit()
            print("Ship hit!!")    

        self.check_aliens_bottom()    

    def check_keyup_events(self, event):
        if event.key == pygame.K_RIGHT:
            self.ship.moving_right = False
        elif event.key == pygame.K_LEFT:
            self.ship.moving_left = False
        elif event.key == pygame.K_p:
            self.powerup = True
    
    def fire_bullet(self):
        if len(self.bullet) < self.settings.bullets_allowed:
            new_bullet = Bullet(self)
            self.bullet.add(new_bullet)

    def update_bullet(self):
        self.bullet.update()
        for bullets in self.bullet.copy():
            #self.check_events()
            if bullets.rect.bottom <= 0:
                self.bullet.remove(bullets)
            #collisions = pygame.sprite.groupcollide(
            #self.bullet, self.aliens, self.powerup, True)
        self.check_events()
        self.check_bullet_alien_collisions()

    def check_bullet_alien_collisions(self):
        self.powerup = True
        collisions = pygame.sprite.groupcollide(
           self.bullet, self.aliens, self.powerup, True)
        if not self.aliens:
            self.bullet.empty()
            self.create_fleet()
    def check_keydown_events(self, event):
        if event.key == pygame.K_RIGHT:
                self.ship.moving_right = True
        elif event.key == pygame.K_LEFT:
                self.ship.moving_left = True
        elif event.key == pygame.K_q:
            sys.exit()
        elif event.key == pygame.K_SPACE:
            self.fire_bullet()
        elif event.key == pygame.K_p:
            self.powerup = False
    
    def run_game(self):
        while True:
            self.check_events()
            if self.stats.game_active:
                self.ship.update()
                self.update_bullet()
                self.update_aliens()
            self.update_screen()
if __name__ == '__main__': 
    ai = AlienInvasion()
    ai.run_game()


