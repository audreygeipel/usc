import javax.swing.*;

public class Mine extends MapObject {

  public Mine(Game g, int loc_x, int loc_y){
    super(g, loc_x, loc_y);
  }

  // This is used to represent Mine in GUi
  public JLabel getLabel(){
    return super.getLabel("imgs/mine.gif");
  }

  // This function is called evertime user moves
  // If it encounter player, it gives bullets to user
  public void tick(){
    if (isPlayerHere()){
      game.player.bullet = game.player.bullet + 10;
    }
  }
}

