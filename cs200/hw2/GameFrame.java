import javax.swing.*;
import java.awt.*;
import java.awt.geom.*;

public class GameFrame extends JFrame{

  public Game game;
  public JPanel worldPanel;
  public JPanel scorePanel;
  public InputHandler inputHandler;

  // This is the maing GUI class of the game
  // It sets the frame and add panels to it
  public GameFrame(Game g){
    game = g;
    inputHandler = new InputHandler(game);
    worldPanel = new WorldPanel(game);
    scorePanel = new ScorePanel(game);

    setSize(700, 500);
    setTitle("Cosmos Hunter - The best game");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setLayout(new BorderLayout(0, 0));

    addMouseListener(inputHandler);
    addKeyListener(inputHandler);

    add(scorePanel, BorderLayout.NORTH);
    add(worldPanel, BorderLayout.CENTER);
  }
}
