import javax.swing.*;

abstract class MapObject {
  int x;
  int y;

  JLabel label;
  ImageIcon imageIcon;

  Game game;

  // This is the constructor of this class
  // It assigns common class variables
  public MapObject(Game g, int loc_x, int loc_y){
    game = g;
    x = loc_x;
    y = loc_y;
  }
  
  // This is called everytime player moves
  public void tick(){
  
  }

  // This function returns Jlabel to be used in GUI
  public JLabel getLabel(){
    return new JLabel();  
  }

  // This function return JLabel with image in it
  public JLabel getLabel(String imgPath){
    imageIcon = (imageIcon == null) ? new ImageIcon(imgPath) : imageIcon; 
    label = (label == null)? new JLabel(imageIcon) : label;
    return label;
  }

  // This function returns object's x relative to players's x
  public int getRelativeX(){
    return (x - game.player.x);
  }

  // This function checks if user and object are at the same location
  public boolean isPlayerHere(){
    return game.player.x == x && game.player.y == y;
  }

  // This function checks if the object is in current frame
  public boolean isInNow(){
    return !isInHistory() && !isInFuture();
  }
  
  // This function checks if object is behinf
  public boolean isInHistory(){
    return x < game.player.x; 
  }
  
  // This function checks if the objects is not in the frame and is in future
  public boolean isInFuture(){
    return x > (game.player.x + game.world.frame_width - 1);  
  }
}

