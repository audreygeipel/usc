import java.util.Random;

public class Enemy {
  // This is the unique id of bonus item
  public static int ID = 2;

  // This function prints the char of this item
  public static void print(){
    IO.print("@");
  }

  // This is the movement behavior of this item
  // return true if we need to skip 1 pixel so we do not move 1 item twice
  public static boolean move(int[][] map, int x, int y){
    int rint = World.generator.nextInt(3);

    if (rint == 1 && y > 0 && Space.ID == map[x][y-1]){
      map[x][y] = Space.ID;
      map[x][y-1] = Enemy.ID;
    } else if (rint == 2 && y < (World.height-1) && map[x][y+1] == Space.ID){
      map[x][y] = Space.ID;
      map[x][y+1] = Enemy.ID;
      return true;
    }
    return false;
  }
}
