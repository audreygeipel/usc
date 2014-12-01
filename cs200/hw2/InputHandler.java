import java.awt.event.*;

class InputHandler implements MouseListener, KeyListener{
  Game game;

  // This is the constructor function of this class
  public InputHandler(Game g){
    game = g; 
  }

  public void mousePressed(MouseEvent e){ }
  public void mouseExited(MouseEvent e){ }
  public void mouseEntered(MouseEvent e){ }
  public void mouseReleased(MouseEvent e){ }
  public void mouseClicked(MouseEvent e){ }

  // This function is called everytime user presses a key
  // If the key is used in the program it calls game.tick
  public void keyPressed(KeyEvent e) {
    switch (e.getKeyCode()) {
      case KeyEvent.VK_DOWN: game.tick("d"); break;
      case KeyEvent.VK_UP: game.tick("u"); break;
      case KeyEvent.VK_LEFT: game.tick("l"); break;
      case KeyEvent.VK_RIGHT: game.tick("r"); break;
      case KeyEvent.VK_ESCAPE: game.tick("esc"); break;
      case KeyEvent.VK_SPACE: game.tick("space"); break;
    }
  }

  public void keyReleased(KeyEvent e) { }
  public void keyTyped(KeyEvent e) { }
}
