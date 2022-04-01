import java.io.*;
/**
 *  Runs the game by accepting input from player and modyfing the gamestate accordingly until the game is finished.
 */
public class GameMaster{

    /**
     * Contains the state of game currently run by GameMaster.
     */
    GameState game;

    /**
     * Creates a new GameMaster which can run the game.
     * @param newstate - gamestate to be run by GameMaster.
     */
    public GameMaster(GameState newstate){
        game=newstate;
    }

    /**
     * Saves gamestate to a file with given path.
     * @param filepath path for save file
     * @return Save report
     */
    public String saveGame(String filepath){
        try{
        FileOutputStream fileOut =
         new FileOutputStream(filepath);
         ObjectOutputStream out = new ObjectOutputStream(fileOut);
         out.writeObject(game);
         out.close();
         fileOut.close();
         return "GameState saves succesfully!";
        }
        catch (IOException i) {
            return "Failed to save GameState!";
         }   
    }

    /**
     * Orders game to register attack on given coordinates.
     * @param x row letter.
     * @param y column number.
     * @return attack report.
     */
    public String makeMove(int x,int y){
       y=y-1;
       x=x-1;
       if(x<0||y<0||x>=10||y>=10)
        return "Invalid coordinates!";
       String res = game.attack(x,y);
       return res;
    }

    /**
     * Returns number of current turn.
     * @return current turn;
     */
    public int getTurn(){
        return game.getTurn();
    }
    /**
     * Returns designated player's hitpoints.
     * @param nr nr of player.
     * @return remaining hitpoints of player with given nr.
     */
    public int getPlayerHealth(int nr){
        return game.getPlayerHealth(nr);
    }
    /**
     * Reveals content of given player's boards (field designated by given coordinates).
     * @param player player number.
     * @param x rows.
     * @param y columns.
     * @return content of designated field.
     */
    public int getField(int player,int x,int y){
        return game.getField(player,x-1,y-1);
    }

}