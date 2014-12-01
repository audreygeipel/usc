import javax.swing.*;

public class Player extends MapObject{
  // This var stores players score
  public int score = 0;
  // This is the remaining bullets of user
  public int bullet = 3;
  // This stores if user is alive
  public boolean alive = true;

  public Player(Game g, int loc_x, int loc_y){
    super(g, loc_x, loc_y);
  }

  // This is used to represent Player in GUI
  public JLabel getLabel(){
    return super.getLabel("imgs/spaceship.gif");
  }

  // This is called everytime user presses a key
  // Player moves based on the key
  public void tick(String direction){
    if (direction.equals("u")){
      up();
      forward();
    } else if (direction.equals("d")) {
      down();
      forward();
    } else if (direction.equals("r")) {
      forward();
    } else if (direction.equals("space")) {
      shoot();
      forward();
    }
  }

  // This returns the score of the user
  public int getScore(){
    return score + (x*10);
  }

  // This fires a bullet
  public boolean shoot(){
    if (bullet < 1) return false;
    Bullet newBullet = new Bullet(game, x, y);
    game.world.placeObjectAt(x, y, newBullet);
    newBullet.forward();
    bullet--;
    return true;
  }

  // This function moves player down
  public void down(){
    if (y < (World.height-1)) y++;
  }

  // This function moves player up
  public void up(){
    if (y != 0) y--;
  }

  // This function moves player forward
  public void forward(){
    if (x != World.width) x++;
  }

  // This checks if the player is dead
  public boolean isDead(){
    return !alive;
  }

  // This kills the player
  public void kill(){
    alive = false;  
  }
}

