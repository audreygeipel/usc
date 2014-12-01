public class Application {

  // This is the function class of this project
  // This function is called everytime program is executed
  public static void main(String[] argv){
    int command = IO.showMenu();
    Game game = new Game();

    switch (command) {
      case 1: 
        game.start(); 
        break;
      case 2: 
        game.readSavedGame();
        game.start(); 
        break;
      case 3: 
        System.out.println("Quit"); 
        break;
    }
  }
}
