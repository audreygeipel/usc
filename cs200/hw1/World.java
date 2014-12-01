import java.util.Random;

public class World {
  // This var stores the height of the world
  public static int height = 10;
  // This var stores the width of the world
  public static int width = 3;
  // This var stores the window width
  public static int window_width = 70;
  // This is the array that stores items and location
  public int map[][] = new int[10000][height];
  // This is used to generate random numbers
  public static Random generator = new Random(19911004);
 
  // This is the main function of world
  // Also extends the map
  public World(){
    extendMap(100);
  }

  // This function is used to extend map
  // So every time user reaches the end of the map we extend the map
  public void extendMap(int num_columns){

    for (int w = width; w < width + num_columns; w++){
      for (int h = 0; h < height; h++){
        int rint = generator.nextInt(100);

        if (rint < 10){
          map[w][h] = Meteor.ID;
        } else if (rint == 10) {
          map[w][h] = Enemy.ID;
        } else if (rint == 11) {
          map[w][h] = Bonus.ID;
        } else {
          map[w][h] = Space.ID;
        }
      }
    }

    width = width + num_columns;
  }

  // This function updates the items location based on their behavior
  // Every object has its own moving behavior
  // So we call their function to make their move
  // If one of the items moves down we skip 1 pixel so we do not move 1 item twice
  public void moveObjects(int player_x){
    for (int w = player_x; w < (player_x + window_width); w++){
      for (int h = 0; h < height; h++){
        if (Bonus.ID == map[w][h]) {
          if (Bonus.move(map, w, h)) h++;
        } else if (Enemy.ID == map[w][h]){
          if (Enemy.move(map, w, h)) h++;
        } 
      }
    }
  }

  // This function prints the current world
  // Also if necessary it extends the map
  // Every item has it's own print function
  public void print(int x, int y, int score){
    if (width < x + window_width) {
      extendMap(200);
    }

    printDivider(); 
    IO.println("| Score = " + score + " | x = " + x); 
    printDivider(); 

    for (int h = 0; h < height; h++){
      for (int w = x; w < (x + window_width); w++){
        if (w == x && h == y) {
          IO.print(">");
        } else if (Meteor.ID == map[w][h]) {
          Meteor.print();
        } else if (Bonus.ID == map[w][h]) {
          Bonus.print();
        } else if (Enemy.ID == map[w][h]) {
          Enemy.print();
        } else if (Space.ID == map[w][h]){
          Space.print();
        }
      }
      IO.print("\n");
    }

    printDivider();
  }

  // This is the helper function for printing maps
  // Just prints horizontal line
  public void printDivider(){
    IO.print("+");
    for(int i = 0; i < window_width-2; i++){
      IO.print("-");
    }
    IO.print("+\n");
  }
}
