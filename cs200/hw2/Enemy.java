import javax.swing.*;

public class Enemy extends MapObject {

  public Enemy(Game g, int loc_x, int loc_y){
    super(g, loc_x, loc_y);
  }

  // This is used to represent Enemy in GUI
  public JLabel getLabel(){
    return super.getLabel("imgs/enemy.gif");
  }

  // This function is called everytime player moves
  // It moves up or down
  // If it moves it gets closer to player
  // If encounters player, it kills him
  public void tick(){
    int rint = World.generator.nextInt(100);

    if (game.player.y == y || rint < 50) {
    
    } else if (game.player.y < y && game.world.isObjectAt(x, y-1, "Space")){
      game.world.swapObjects(x, y, x, y-1);
    } else if (game.player.y > y && game.world.isObjectAt(x, y+1, "Space")){
      game.world.swapObjects(x, y, x, y+1);
    }

    if (isPlayerHere()){
      game.player.kill();
    }
  }
}

