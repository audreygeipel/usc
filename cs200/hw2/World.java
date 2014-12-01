import java.util.*;

public class World {
  // This var stores the height of the world
  public static int height = 10;
  // This var stores the width of the world
  public static int width = 0;
  // This is the width of the GUI frame
  public static int frame_width = 20;
  // This is used to generate random numbers
  public static Random generator = new Random(19901004);
  // This stores all the MapObjects on the map
  public ArrayList<MapObject> mapObjects = new ArrayList<MapObject>(); 
  public Game game;

  // This is the main function of world
  // Also extends the map
  public World(Game g){
    game = g;
    extendMap(frame_width + 10);
  }

  // This is called everytime player moves
  // This function calles tick function of every object in the map
  public void tick(){
    if (game.player.x + frame_width > width) extendMap(1);
    clearMap();

    for(int i=0; i < mapObjects.size(); i++){
      if (mapObjects.get(i).isInNow()) {
        mapObjects.get(i).tick();
      }
    }        
  }

  // This extends map
  public void extendMap(int num_columns){
    for (int w = width; w < width + num_columns; w++){
      for (int h = 0; h < height; h++){
        int rint = generator.nextInt(100);

        if (rint < 10){
          mapObjects.add(new Meteor(game, w, h));
        } else if (rint == 10) {
          mapObjects.add(new Enemy(game, w, h));
        } else if (rint == 11) {
          mapObjects.add(new Bonus(game, w, h));
        } else if (rint == 12) {
          mapObjects.add(new Mine(game, w, h));
        } else {
          mapObjects.add(new Space(game, w, h));
        }
      }
    }

    width = width + num_columns;
  }

  // This clears all the objects in the map which are in history
  public void clearMap(){
    for(int i=0; i < mapObjects.size(); i++){
      if (mapObjects.get(i).isInHistory()) {
        mapObjects.remove(mapObjects.get(i));
      }
    }        
  }

  // This function removes the object at x y and places the new object there
  public void placeObjectAt(int x, int y, MapObject newObject){
    mapObjects.remove(getObjectAt(x, y));
    mapObjects.add(newObject);
  }

  // This checks the objects type at the given location
  public boolean isObjectAt(int x, int y, String objectName){
    for(int i=0; i < mapObjects.size() ; i++){
      if (mapObjects.get(i).x == x && mapObjects.get(i).y == y) {
        if (mapObjects.get(i).getClass().getName().equals(objectName)){
          return true;
        } 
      }
    }
    return false;    
  }
  
  // This returns the object at given location
  public MapObject getObjectAt(int x, int y){
    for(int i=0; i < mapObjects.size() ; i++){
      if (mapObjects.get(i).x == x && mapObjects.get(i).y == y) {
        return mapObjects.get(i);
      }
    }        
    return mapObjects.get(0); // TODO
  }

  // This swaps objects at given locations
  public void swapObjects(int x1, int y1, int x2, int y2){
    MapObject object1 = getObjectAt(x1, y1);
    MapObject object2 = getObjectAt(x2, y2);

    object1.x = x2;
    object1.y = y2;
    object2.x = x1;
    object2.y = y1;
  }
}

