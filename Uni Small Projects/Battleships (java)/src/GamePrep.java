import java.io.*;
/**
 * Prepares a new gamestate or loads a saved gamestate.
 */
public class GamePrep {
    /**
     * Number of already placed ships;
     */
    int ships_placed;
    /**
     *  Ships hitpoints registry.
     */
    Ships ships;
    /**
     * Player 1's board.
     */
    Board p1;
    /**
     * Player 2's board.
     */
    Board p2;
    /**
     * GameState in preparation.
     */
    GameState loaded;
    /**
     * Initializes GamePrep.
     */
    public GamePrep(){
        ships_placed=0;
        ships=new Ships();
        p1=new Board();
        p2=new Board();
        loaded=null;
    }
    /**
     * Loads saved GameState.
     * @param filepath path for file with saved GameState.
     * @return loading operation report.
     */
    public String loadGame(String filepath){
        loaded=null;
        try
        {   
            // Reading the object from a file
            FileInputStream file = new FileInputStream(filepath);
            ObjectInputStream in = new ObjectInputStream(file);
              
            // Method for deserialization of object
            loaded = (GameState)in.readObject();
              
            in.close();
            file.close();
            return "GameState loaded succesfully!";
        }
          
        catch(IOException ex)
        {
            return"Loading GameState failed!";
        }
        catch(ClassNotFoundException ex)
        {
            return "Loading GameState failed!";
        }

    }

    /**
     * Processes ship placement request.
     * @param x row.
     * @param y column.
     * @param nr placed ship's number.
     * @param length placed ship's length
     * @param horizontal placed ship's orientation.
     * @return placement report.
     */
    public String makePlacement(int x,int y, Boolean horizontal){
       
       Boolean res;
       
       /// System.out.println(horizontal);	 
       if(ships_placed<7)
             res = p1.placeShip(x-1,y-1,ships_placed,ships.getShipHP(ships_placed),horizontal);
       else res=p2.placeShip(x-1,y-1,ships_placed,ships.getShipHP(ships_placed),horizontal);
       if(res==false)
            return "Invalid placement request!";
       ships_placed++;    
       return "Placement successful!";
    }

    /**
     * Finalizes preparation and creates a GameState using initialized boards and ships.
     * @return GameState prepared for playing.
     */
    public GameState encapsulate(){
        if (loaded==null)
        loaded=new GameState(p1,p2,ships);
        return loaded;
    }
    
    
    
}
