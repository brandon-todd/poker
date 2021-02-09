class GameSettings:
    def __init__(self):
        self.screen_width = 800
        self.screen_height = 600
        self.bg_color = (100,150,230)

        self.ship_speed = 1.5

        self.bullet_speed = 1.5
        self.bullet_width = 3.0
        self.bullet_height = 15
        self.bullet_color = (30,30,30)
        self.bullets_allowed = 10
        
        self.alien_speed = 1.0
        self.fleet_drop_speed = 8
        self.fleet_direction = 0.5

        self.ship_limit = 2