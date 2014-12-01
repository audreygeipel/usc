import javax.swing.*;

public class Meteor extends MapObject{

  public Meteor(Game g, int loc_x, int loc_y){
    super(g, loc_x, loc_y);
  }

  // This is used to represent Meteor in GUI
  public JLabel getLabel(){
    return super.getLabel("imgs/meteor.gif");
  }

  // This function is called everytime user moves
  // If it encounters player, it kill him
  public void tick(){
    if (isPlayerHere()){
      game.player.kill();
    }
  }
}

