import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * Player interface.
 */
public class GameMasterGUI extends JFrame{ 
  /**
   * Currently run game.
   */
  GameMaster game;
  /**
   * Grids containing board fields
   */
  JPanel []map_grid;
  /**
   * Array of board fields.
   */
  JLabel[][][] field;
  /**
   * Game reaction displayer.
   */
  JLabel report_field;
  /**
   * Coordinate selector - rows.
   */
  JComboBox<String> row_selector;
  /**
   * Coordinate selector - columns.
   */
  JComboBox<String> column_selector;
  /**
   * Text field for naming file which current GameState will be saved into.
   */
  JTextField save_path;
  /**
   * Buttong for attacking enemy's board.
   */
  JButton execute_button;
  /**
   * Button for saving current GameState.
   */
  JButton save_button;
  /**
   * Panel containing players' maps and status panel.
   */
  JPanel center;
  /**
   * Panel with controls
   */
  JPanel panel;
  /**
   * Panel displaying game status.
   */
  JPanel status;
  /**
   * Label displaying player 1's reamining hitpoints.
   */
  JLabel hp1;
  /**
   * Label displaying player 2's reamining hitpoints.
   */
  JLabel hp2;
  /**
   * Label displaying current turn's number.
   */
  JLabel turn_display;
  /**
   * Player 1's health.
   */
  Integer health1;
  /**
   * Player 2's health.
   */
  Integer health2;
  /**
   * Current turn's number.
   */
  Integer turn;

  GameMasterGUI(GameMaster controlled_game){
    super("Battleships");
      game=controlled_game;
      turn=game.getTurn();
      health1=game.getPlayerHealth(0);
      health2=game.getPlayerHealth(1);
      
      ///load data
      



      ///report field
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      setSize(600, 300);

      if(turn%2==0)
      report_field=new JLabel("Player 2's turn - please choose attack coordinates",SwingConstants.CENTER);
      else report_field=new JLabel("Player 1's turn - please choose attack coordinates",SwingConstants.CENTER);
      report_field.setFont(report_field.getFont().deriveFont(18.0f));
      ///map grids init
      map_grid=new JPanel[2];
      map_grid[0]=new JPanel();
      map_grid[1]=new JPanel();
      map_grid[0].setLayout(new GridLayout(11,11));
      map_grid[1].setLayout(new GridLayout(11,11));
      field=new JLabel[2][11][11];
      for(int i=0;i<11;i++)
            for(int j=0;j<11;j++)
            {
              field[0][i][j]=new JLabel(" ",SwingConstants.CENTER);
              map_grid[0].add(field[0][i][j]);
              field[0][i][j].setBackground(Color.black);
              field[0][i][j].setOpaque(true);
              field[0][i][j].setForeground(Color.green);

              field[1][i][j]=new JLabel(" ",SwingConstants.CENTER);
              map_grid[1].add(field[1][i][j]);
              field[1][i][j].setBackground(Color.black);
              field[1][i][j].setOpaque(true);
              field[1][i][j].setForeground(Color.green);
            }
            field[0][0][0].setOpaque(false);
            field[0][0][0].setForeground(Color.black);
            field[1][0][0].setOpaque(false);
            field[1][0][0].setForeground(Color.black);

        for(Integer i=1;i <=10;i++)
        {   int temp1=i-1+'A';
            char temp2=(char)temp1;
            Character temp3=Character.valueOf(temp2);
            field[0][0][i].setText(temp3.toString());
            field[0][i][0].setText(i.toString());
            field[0][0][i].setOpaque(false);
            field[0][i][0].setOpaque(false);
            field[0][i][0].setForeground(Color.black);
            field[0][0][i].setForeground(Color.black);
            field[1][0][i].setText(temp3.toString());
            field[1][i][0].setText(i.toString());
            field[1][0][i].setOpaque(false);
            field[1][i][0].setOpaque(false);
            field[1][i][0].setForeground(Color.black);
            field[1][0][i].setForeground(Color.black);
            
        }
        /// controls
        panel = new JPanel();
        String[]row={"1","2","3","4","5","6","7","8","9","10"};
        String[]column={"A","B","C","D","E","F","G","H","I","J"};
        row_selector=new JComboBox<>(row);
        column_selector=new JComboBox<>(column);
        execute_button=new JButton("Attack");
        save_button=new JButton("Save game");
        save_path=new JTextField(10);
        
        panel.add(column_selector);
        panel.add(row_selector);
        panel.add(execute_button);
        panel.add(save_path);
        panel.add(save_button);
        ///mid
        status=new JPanel();
        JLabel hp1=new JLabel("P1 HP: "+health1.toString(),SwingConstants.CENTER);
        JLabel hp2=new JLabel("P2 HP: "+health2.toString(),SwingConstants.CENTER);
        JLabel turn_display=new JLabel("Turn: "+turn.toString(),SwingConstants.CENTER);
        status.setLayout(new BoxLayout(status, BoxLayout.Y_AXIS));
        status.add(turn_display);
        status.add(hp1);
        status.add(hp2);


        ///adding actions
    
         save_button.addActionListener(new ActionListener() {
          @Override
          public void actionPerformed(ActionEvent e) {
            String temp=report_field.getText();
            String res=game.saveGame(save_path.getText());
            report_field.setText(res);
            ///wait 3 secs
            
            ///continue
            report_field.setText(temp);
          }
       });


       execute_button.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
          String temp=report_field.getText();
          int x=row_selector.getSelectedIndex()+1;
          int y=column_selector.getSelectedIndex()+1;
          String res=game.makeMove(x, y);
          report_field.setText(res);
          //add later: Delay 3s
          if(res!="Invalid call for fire"){
            displayMaps(field,2,game);
              turn=game.getTurn();
              turn_display.setText("Turn: "+turn.toString());
              if(turn%2==0){
                health2--;
                hp2.setText("P2 HP: "+health2.toString());
                report_field.setText("Switching players: Player 2's turn");
              }
              else{
                health1--;
                hp1.setText("P1 HP: "+health1.toString());
                report_field.setText("Switching players: Player 1's turn");
              }
              //add later: Delay 5s
              displayMaps(field,turn%2,game);
              if(turn%2==0)
              report_field.setText("Player 2's turn - please choose attack coordinates");
              else report_field.setText("Player 1's turn - please choose attack coordinates");

          }
          else if(res=="Player 1 has achieved victory!"||res=="Player 2 has achieved victory!")
          {
            dispose();
          }
          else report_field.setText(temp);

        }
     });

        
        ///finish
        center=new JPanel();
        center.setSize(1200, 400);
        center.add(map_grid[0]);
        center.add(status);
        center.add(map_grid[1]);

        getContentPane().add(BorderLayout.PAGE_START, report_field);
        getContentPane().add(BorderLayout.CENTER ,center);
        getContentPane().add(BorderLayout.PAGE_END, panel);
        displayMaps(field,turn%2,game);
        setVisible(true);


  }


  /**
   * Displays players' boards using given label grids
   * @param fields grids of labels used for displaying boards.
   * @param option 1 for player 1's view, 2 for player 2's view, other for "switching players" view.
   * @param controller GameMaster containing displayed boards.
   */
  private void displayMaps(JLabel[][][]fields,int option,GameMaster controller)
  {
    int temp;
    String znak;

    if(option==1)
    {
        ///reveal 1
        for(int i=1;i<11;i++)
          for(int j=1;j<11;j++)
          {
            temp=controller.getField(0,i,j);
            if(temp==14)
            znak=" ";
            else if(temp==15)
            znak="O";
            else if(temp==16)
            znak="X";
            else znak="#";
            fields[0][i][j].setText(znak);
          }

        ///hide 2
        for(int i=1;i<11;i++)
          for(int j=1;j<11;j++)
          {
            temp=controller.getField(1,i,j);
            if(temp==15)
            znak="O";
            else if(temp==16)
            znak="X";
            else znak=" ";
            fields[1][i][j].setText(znak);
          }
    }
    else if(option==0){
      
       ///hide 1
       for(int i=1;i<11;i++)
          for(int j=1;j<11;j++)
          {
            temp=controller.getField(0,i,j);
            if(temp==15)
            znak="O";
            else if(temp==16)
            znak="X";
            else znak=" ";
            fields[0][i][j].setText(znak);
          }
  
        ///reveal 2
        for(int i=1;i<11;i++)
        for(int j=1;j<11;j++)
        {
          temp=controller.getField(1,i,j);
          if(temp==14)
          znak=" ";
          else if(temp==15)
          znak="O";
          else if(temp==16)
          znak="X";
          else znak="#";
          fields[1][i][j].setText(znak);
        }
      
    }
    else{
      ///hide 1
      for(int i=1;i<11;i++)
        for(int j=1;j<11;j++)
        {
          temp=controller.getField(0,i,j);
          if(temp==15)
            znak="O";
          else if(temp==16)
            znak="X";
          else znak=" ";
          fields[0][i][j].setText(znak);
      }

      ///hide 2
      for(int i=1;i<11;i++)
        for(int j=1;j<11;j++)
        {
          temp=controller.getField(1,i,j);
          if(temp==15)
            znak="O";
          else if(temp==16)
            znak="X";
          else znak=" ";
        fields[1][i][j].setText(znak);
      }
      

    }
  }
    
}
