import java.io.*;
import javax.swing.*;

public class Game {
  public World world;
  public Player player;
  public JFrame frame;
  public boolean isRunning = false;

  // Constructor class of Game class
  // Creates player, world and frame
  public Game(){
    player = new Player(this, 0, 5);
    world = new World(this);
    frame = new GameFrame(this);
  }

  // This function starts or resumes the game
  public void start(){
    if (player.isDead()){
      stop();
    } else {
      frame.setVisible(true);
      isRunning = true;
    }
  }

  // This function is called by InputHandler
  // This function is called everytime user presses a key
  // This is basically 1 round of the game
  // It moves player
  // It tells world class to move all the objects
  // and prints the world
  public boolean tick(String cmd){
    if (player.isDead()){
      quit();
      return true;
    }

    if (cmd.equals("esc")) {
      stop();
      return true;
    }

    player.tick(cmd);
    world.tick();
    
    if(player.isDead()){
      quit();
      return true;
    } else {
      frame.repaint();
      return true;
    }
  }

  // This pauses the game
  public void stop(){
    frame.setVisible(false);
    isRunning = false;
  }

  // This function quits the game and destroys the frame
  public void quit(){
    IO.println("GAME OVER, Your score was " + player.getScore() + ". Quiting..."); 
    stop();
    frame.dispose();
    frame = null;
  }

  // This function returns true if game is running
  public boolean isRunning(){
    return isRunning;
  }

  // This function reads the game data from save file
  public void load(){
    try {
      FileInputStream fis = new FileInputStream("game.dat");
      ObjectInputStream ois = new ObjectInputStream(fis);
      try {

        player.x = (Integer)ois.readObject();
        player.y = (Integer)ois.readObject();
        player.score = (Integer)ois.readObject();
        player.bullet = (Integer)ois.readObject();
        world.extendMap(player.x + world.frame_width);

      } catch (ClassNotFoundException ex) {
        System.out.println("Class not found");
      }
    } catch (IOException ex) {
      System.out.println("IO Exception");
    }
  }

  // This function saves the current state of the game to a file
  // We store map and players info on game.dat file
  public void save(){
    try {
      FileOutputStream fos = new FileOutputStream("game.dat");
      try {
        ObjectOutputStream oos = new ObjectOutputStream(fos);

        oos.writeObject(player.x);
        oos.writeObject(player.y);
        oos.writeObject(player.score);
        oos.writeObject(player.bullet);

      } catch (IOException ex) {
        System.out.println("IO Exception");
      }
    } catch (FileNotFoundException ex) {
      System.out.println("There is no saved game data.");
    }
  }
}
