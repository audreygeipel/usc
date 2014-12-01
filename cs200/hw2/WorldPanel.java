import javax.swing.*;
import java.awt.*;
import java.awt.geom.*;

public class WorldPanel extends JPanel{
  public Game game;
  ImageIcon background = new ImageIcon("imgs/stars.gif");

  public WorldPanel(Game g){
    game = g;

    setBackground(Color.BLACK);
    setLayout(new GridLayout(game.world.height, game.world.frame_width));
  }

  // This prints the objects in the map
  public void paintComponent(Graphics g){
    super.paintComponent(g);
    removeAll();

    g.drawImage(background.getImage(), -2*game.player.x, 0, null);

    for(int y=0; y < game.world.height; y++){
      for(int x=game.player.x; x < game.player.x + game.world.frame_width; x++){
        if (x == game.player.x && y ==game.player.y){
          add(game.player.getLabel());
        } else {
          add(game.world.getObjectAt(x, y).getLabel());
        }
      }
    }
  } 
}
