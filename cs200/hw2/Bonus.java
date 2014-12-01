import javax.swing.*;

public class Bonus extends MapObject {

  public Bonus(Game g, int loc_x, int loc_y){
    super(g, loc_x, loc_y);
  }

  // This is used to represent Bonus in GUI
  public JLabel getLabel(){
    return super.getLabel("imgs/bonus.gif");
  }

  // This function is called everytime player moves
  // It moves randomly up or down
  // If it encounters player, it increases player's score
  public void tick(){
    int rint = World.generator.nextInt(3);

    if (rint == 1 && y > 0 && game.world.isObjectAt(x, y-1, "Space")){
      game.world.swapObjects(x, y, x, y-1);
    } else if (rint == 2 && y < (World.height-1) && game.world.isObjectAt(x, y+1, "Space")){
      game.world.swapObjects(x, y, x, y+1);
    }

    if (isPlayerHere()){
      game.player.score = game.player.score + 150;
    }
  }
}

