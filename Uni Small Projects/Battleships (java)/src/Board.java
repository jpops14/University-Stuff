
import java.io.Serializable;
/** 
Board class contains a matrix of integers which represents player's board.
*/
public class Board implements Serializable{
    /** Matrix - representation of player's board.
     * 0-13 describes a ship by its number.
     * 14 desribes an empty space.
     * 15 desribes a miss.
     * 16 desribes a confirmed hit.
     */
    int[][]map;
    /**
     * Creates new Board filled with empty fields (desribed by int=14).
     */
    public Board(){
        this.map=new int[10][10];
        for(int i = 0 ; i < 10 ; i++)
            for(int j = 0; j <10 ; j++)
                map[i][j] = 14;
    }
    /** Registering an attack on field desribed by given coordinates x and y. 
     *  Returns valuve of attacked field.
    * @param x row
    * @param y column
    */
    public int attack(int x,int y){
        int target = map[x][y];
        if(target>=0 && target <14)
            map[x][y] = 16;
        if(target==14)
            map[x][y] = 15;
        return target;        
    }

    /** Placing a ship (designated with nr) on the board extending from coordinates x and y either
     *  vertically downwards or horizontally rightwards. Returns true if placement was possible,
     *  otherwise returns false.
     * @param x  row
     * @param y  column
     * @param nr ship's number
     * @param length ship's length
     * @param horizontal ship's orientation
     * @return bool: was placement succesful?
     */
    public Boolean placeShip(int x,int y,int nr,int length,Boolean horizontal){

        if(x<0||y<0||x>=10||y>=10)
        return false;

    if(horizontal==true)    //horizontal
    {
        if(y+length-1>=10)
            return false;
        for(int i=0; i<length; i++)
        {
            if(map[x][y+i]!=14)
                return false;
        }
        for(int i=0; i<length; i++)
        {
            map[x][y+i]=nr;
        }

        return true;
    }
    else if (horizontal==false)  //vertical
    {
        if(x+length-1>=10)
            return false;
        for(int i=0; i<length; i++)
        {
            if(map[x+i][y]!=14)
                return false;
        }
        for(int i=0; i<length; i++)
        {
            map[x+i][y]=nr;
        }

        return true;
    }
    else return false;
    
    }
 
    /**
     * Returns value of map's field desribed by given coordinates.
     * @param x row
     * @param y column
     * @return value of map[x][y]
     */
    public int getField(int x,int y){
        return map[x][y];
    }
}
