
import java.io.Serializable;
/**
 * Represents ships' statuses.
 */
public class Ships implements Serializable{
   /**
    * Number of ships' remaining hitpoints.
    */
   int []HP;
   /**
    * Builds a new ship hitpoints registry, gives every ship default number of hitpoints.
    */
   public Ships(){
        HP=new int[14];
    HP[0]=2;
    HP[1]=2;
    HP[2]=3;
    HP[3]=3;
    HP[4]=4;
    HP[5]=4;
    HP[6]=6;
    HP[7]=2;
    HP[8]=2;
    HP[9]=3;
    HP[10]=3;
    HP[11]=4;
    HP[12]=4;
    HP[13]=6;
   }

   /**
    * Registers hit on the ship and returns attack report.
    * @param id id of attacked ship
    * @return attack report.
    */
   public String hit(int id){
       if(id == 14) return "Miss!";
       if(id == 15 || id == 16) return "Invalid call for fire";
       HP[id]--;
       if(HP[id]==0){
            return "Target has been sunk";
       }
       else if(HP[id]==1)
            return "Target has sustained heavy damage";  
       else return"Confirmed hit on target!";
   }
   /**
    * Read's hitpoints of ship desribed by given id.
    * @param id ship's id.
    * @return remaining HitPoints of ship with given id.
    */
   public int getShipHP(int id){
        int res=HP[id];
        return res;
   }
}
