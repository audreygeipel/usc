import java.io.*;

public class IO {
  
  public static BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
  
  // This is shorhand function for printing line
  public static void println(String string){
    System.out.println(string);
  }

  // This is shorthand function for printing string
  public static void print(String string){
    System.out.print(string);
  }

  // This function asks question to user and returns users answer
  // This function is very handy so we can get users commands very easily
  public static String ask(String question){
    String answer = "";
    System.out.println(question);

    try {
      answer = input.readLine();
      if (answer.equals("")) {
        System.out.println("Please write something");
        answer = ask(question);
      }
    } catch (IOException ex) {
      System.out.println("**** EOF ****");
    }
    return answer;
  }

  // This function prints the main menu
  // And returns the users command
  // This function is called by Application class
  public static int showMenu(){
    String command = "";
    System.out.println("Welcome to the game");
    System.out.println("This is the best game ever\n");
    System.out.println("Menu");
    System.out.println("----");
    System.out.println("1 - New Game");
    System.out.println("2 - Resume Game");
    System.out.println("3 - Quit");

    command = ask("Please select menu item");

    return Integer.valueOf(command);
  }
}
