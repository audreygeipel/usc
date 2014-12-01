import java.io.*;

public class Game {
  // Game class has world variable
  // This world class includes all the information about the map
  public World world = new World();
  // Game class has player variable
  // This player class includes all information about player
  public Player player = new Player();

  // This is the main function of this class
  // This function is called to run the game
  // There is an infitine loop inside so game can continue
  // For every round it print world
  // Then it asks for players next step
  // Based on the command player moves
  // Then it tells world to relocate objects of the map
  // So based on the position of player function finishes the rounf
  public void start(){
    while (true){
      world.print(player.x, player.y, player.score);

      String command =  IO.ask("(s)tay, (u)p, (d)own or (q)uit?");

      if (command.equals("u")){
        player.up();
        player.forward(); 
      } else if (command.equals("d")) {
        player.down();
        player.forward(); 
      } else if (command.equals("s")) {
        player.forward(); 
      } else { 
        save();
        break;
      }

      world.moveObjects(player.x);

      if (world.map[player.x][player.y] == Space.ID){
        player.score = player.score + 10;
      } else if (world.map[player.x][player.y] == Bonus.ID){
        player.score = player.score + 150;
      } else if (world.map[player.x][player.y] == Meteor.ID){
        IO.println("You hit meteor! next time...");
          break;
      } else if (world.map[player.x][player.y] == Enemy.ID){
        IO.println("Enemy killed you! next time...");
          break;
      } 
    }
  }

  // This function reads the game data from save file
  public void readSavedGame(){
    try {
      FileInputStream fis = new FileInputStream("game.dat");
      ObjectInputStream ois = new ObjectInputStream(fis);
      try {

        player.x = (Integer)ois.readObject();
        player.y = (Integer)ois.readObject();
        player.score = (Integer)ois.readObject();
        world.map = (int[][])ois.readObject();

      } catch (ClassNotFoundException ex) {
        System.out.println("Class not found");
      }
    } catch (IOException ex) {
      System.out.println("IO Exception");
    }
  }

  // This function saves the current state of the game to a file
  // This function is called when user wants to exit
  // We store map and players info on game.dat file
  public void save(){
    try {
      FileOutputStream fos = new FileOutputStream("game.dat");
      try {
        ObjectOutputStream oos = new ObjectOutputStream(fos);

        oos.writeObject(player.x);
        oos.writeObject(player.y);
        oos.writeObject(player.score);
        oos.writeObject(world.map);

      } catch (IOException ex) {
        System.out.println("IO Exception");
      }
    } catch (FileNotFoundException ex) {
      System.out.println("There is no saved game data.");
    }
  }
}
