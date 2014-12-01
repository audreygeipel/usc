public class Player {
  // This var stores players score
  public int score = 0;
  // This var stores players current position on the map
  public int x = 0;
  // This var stores players current position on the map
  public int y = 5;
  
  // This function moves player down
  public void down(){
    if (y != World.height) y++;
  }

  // This function moves player up
  public void up(){
    if (y != 0) y--;
  }

  // This function moves player forward
  public void forward(){
    if (x != World.width) x++;
  }
}
