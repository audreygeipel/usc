public class Application {

  // This is the main class of this project
  // This function is called everytime program is executed
  // Shows the main menu if game has not been started
  // If game is running, shows info about resuming
  public static void main(String[] argv){
    Game game = new Game();
    boolean cont = true;

    while(cont && !game.player.isDead()){
      if (!game.isRunning()){
        switch (IO.showMenu()) {
          case 1: 
            game.start(); 
            IO.println("Game is running, press ESC to pause");
            break;
          case 2: 
            game.load();
            game.start(); 
            IO.println("Game is running, press ESC to pause");
            break;
          case 3: 
            game.save(); 
            IO.println("Game is saved"); 
            break;
          case 4: 
            game.quit();
            cont = false;
            break;
        }
      } else {
        IO.print("");
      } 
    }
  }
}
