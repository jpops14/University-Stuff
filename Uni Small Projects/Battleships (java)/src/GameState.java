import java.io.Serializable;

/**
 * Represents state of a single game of Battleships.
 */
public class GameState implements Serializable {
    /**
     * number of current turn
     */
    int turn;
    /**
     * Contains two boards - one for each player.
     */
    Board[] maps;
    /**
     * Contains players' sum of remaining hitpoins.
     */
    int[]playerhp;
    /**
     * Contains ship's hitpoints.
     */
    Ships ships;
    /**
     * Creates a new default gamestate with empty Boards.
     */
    public GameState(){
        turn=1;
        maps=new Board[2];
        maps[0]=new Board();
        maps[1]=new Board();
        playerhp=new int[2];
        playerhp[0]=24;
        playerhp[1]=24;
        ships=new Ships();
    }
    /**
     * Creates a new default game-ready gamestate with given prepared boards.
     * @param p1 player 1's board.
     * @param p2 player 2's board.
     */
    public GameState(Board p1,Board p2){
        turn=1;
        maps=new Board[2];
        maps[0]=p1;
        maps[1]=p2;
        playerhp=new int[2];
        playerhp[0]=24;
        playerhp[1]=24;
        ships=new Ships();
    }

    /**
     * Creates a new default game-ready gamestate with given prepared boards and ships registry.
     * @param p1 player 1's board.
     * @param p2 player 2's board.
     * @param ready_ships ships registry
     */
    public GameState(Board p1,Board p2,Ships ready_ships){
        turn=1;
        maps=new Board[2];
        maps[0]=p1;
        maps[1]=p2;
        playerhp=new int[2];
        playerhp[0]=24;
        playerhp[1]=24;
        ships=ready_ships;
    }

    /**
     * Increments number of turns.*
     * Performs attack on board (adequate to turn number) using given coordinates.
     * @param x row 
     * @param y column
     * @return attack report
     */
    public void turnInc(){
        turn++;
    }
    /**
     * Reads turn number.
     * @return turn number
     */
    public int getTurn(){
        int res=turn;
        return res;
    }
    /**
     * Performs attack on board (adequate to turn number) using given coordinates.
     * @param x row.
     * @param y column.
     * @return attack report.
     */
    public String attack(int x, int y){
        int enemy=turn%2;
        int target=maps[enemy].attack(x,y);

        if(target>=0 && target <7)
           playerhp[0]--;
        else if(target>=7 && target <14)
           playerhp[1]--;
        if(target!=15 && target !=16)
            this.turnInc();   
        if(playerhp[0]==0)
            return "Player 2 has achieved victory!";

        if(playerhp[1]==0)
            return "Player 1 has achieved victory!";
       
        String res=ships.hit(target);
        return res;
    }
    /**
     * Returns number of designated player's remaining hitpoints.
     * @param nr player number.
     * @return player's remaining hitpoints.
     */
    public int getPlayerHealth(int nr)
    {
        return playerhp[nr];
    }
    /**
     * Returns content of field (desribed by given coordinates) on designated player's board.
     * @param nr player number.
     * @return content of board's field.
     */
    public int getField(int player,int x,int y)
    {
        return maps[player].getField(x, y);
    }
    
}
