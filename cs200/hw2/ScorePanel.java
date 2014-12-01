import javax.swing.*;
import java.awt.*;
import java.awt.geom.*;

public class ScorePanel extends JPanel{
  public Game game;
  public JLabel score;

  public ScorePanel(Game g){
    game = g;

    setBackground(Color.BLACK);

    score = new JLabel("score");
    score.setForeground(Color.WHITE);
    add(score);
  }

  // This prints the user's information to gui
  public void paintComponent(Graphics g){
    super.paintComponent(g);
    score.setText("Score = " + game.player.getScore() + " | x = " + game.player.x + " | Bullet = " + game.player.bullet);
  } 
}

