import javax.swing.*;

public class Bullet extends MapObject {

  public Bullet(Game g, int loc_x, int loc_y){
    super(g, loc_x, loc_y);
  }

  // This is used to represent Bullet in GUI
  public JLabel getLabel(){
    return super.getLabel("imgs/bullet.gif");
  }

  // This function called everytime player moves
  // Goes forward faster than other objects
  public void tick(){
    forward();
    forward();
  }

  // It moves if there is nothing front of it
  // If there is another object, it destroys both objects
  public void forward(){
    if (game.world.isObjectAt(x+1, y, "Space")){
      game.world.swapObjects(x, y, x+1, y);
    } else {
      game.world.placeObjectAt(x, y, new Space(game, x, y));
      game.world.placeObjectAt(x+1, y, new Space(game, x+1, y));
    }
  }
}

