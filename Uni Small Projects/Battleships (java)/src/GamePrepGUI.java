import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
/**
 * Graphical User Interface for GamePrep class.
 */
public class GamePrepGUI extends JFrame{
  /**
   *  Controlled GamePrep.
   */
  GamePrep setup;
  /**
   * GUI that will control the GameMaster created with encapsulated GameState after preparation.
   */
  GameMasterGUI display_game;
  /**
   * Panel with controls.
   */
  JPanel panel;
  /** 
   * Grid containing board fiels.
  */
  JPanel map_grid;
  /**
   * Array of board fields.
   */
  JLabel[][] field;
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
   * Ship's orientation selector.
   */
  JComboBox<String> orientation_selector;
  /**
   * Text field for inputting name of file containing saved GameState.
   */
  JTextField save_path;
  /**
   * Button for placing ships.
   */
  JButton execute_button;
  /**
   * Button for loading saved GameState.
   */
  JButton load_button;
  /**
   * Placed ships counter.
   */
  int counter;
  /**
   * Array containing ships' lengths.
   */
  int[]length;
  /**
   * Creates Interface and connects it to given GamePrep.
   * @param setup - GamePrep.
   */
    GamePrepGUI(GamePrep controlled_prep){
        super("Battleships: Preparation phase");
        setup=controlled_prep;
        counter=0;
        
        int [] temparr={2,2,3,3,4,4,6};
        length=temparr;
        
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 600);


        report_field=new JLabel("Player 1's turn - Place your ship nr. 1 (Length: 2)",SwingConstants.CENTER);
        report_field.setFont(report_field.getFont().deriveFont(18.0f));
        /*
        report_field.setBackground(Color.black);
        report_field.setOpaque(true);
        report_field.setForeground(Color.blue);
        */

        //Board display
        map_grid=new JPanel();
        field=new JLabel[11][11];
        map_grid.setLayout(new GridLayout(11,11));


       
        for(int i=0;i<11;i++)
            for(int j=0;j<11;j++)
            {
              field[i][j]=new JLabel(" ",SwingConstants.CENTER);
              map_grid.add(field[i][j]);
              field[i][j].setBackground(Color.black);
              field[i][j].setOpaque(true);
              field[i][j].setForeground(Color.green);
            }
            field[0][0].setOpaque(false);
            field[0][0].setForeground(Color.black);

        for(Integer i=1;i <=10;i++)
        {   int temp1=i-1+'A';
            char temp2=(char)temp1;
            Character temp3=Character.valueOf(temp2);
            field[0][i].setText(temp3.toString());
            field[i][0].setText(i.toString());
            field[0][i].setOpaque(false);
            field[i][0].setOpaque(false);
            field[i][0].setForeground(Color.black);
            field[0][i].setForeground(Color.black);
        }

         
        //Controls
        panel = new JPanel();
        String[]row={"1","2","3","4","5","6","7","8","9","10"};
        String[]column={"A","B","C","D","E","F","G","H","I","J"};
        String[]orientation={"Horizontal","Vertical"};
        row_selector=new JComboBox<>(row);
        column_selector=new JComboBox<>(column);
        orientation_selector=new JComboBox<>(orientation);
        execute_button=new JButton("Deploy");
        load_button=new JButton("Load game");
        save_path=new JTextField(10);
        
        panel.add(column_selector);
        panel.add(row_selector);
        panel.add(orientation_selector);
        panel.add(execute_button);
        panel.add(save_path);
        panel.add(load_button);

        //Add action
        load_button.addActionListener(new ActionListener() {
          @Override
          public void actionPerformed(ActionEvent z) {
            String temp=report_field.getText();
            String res=setup.loadGame(save_path.getText());
            report_field.setText(res);
            //add later: Delay 3s
          
            if(res=="GameState loaded succesfully!")
            {
              dispose();
              GameState prepared_game=setup.encapsulate();
              GameMaster launch_game=new GameMaster(prepared_game);
              GameMasterGUI display_game=new GameMasterGUI(launch_game);
            }
            ///start game
            report_field.setText(temp);
          }
       });

       execute_button.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
          String temp=report_field.getText();
          int x=row_selector.getSelectedIndex()+1;
          int y=column_selector.getSelectedIndex()+1;
          int sOr=orientation_selector.getSelectedIndex();
          Boolean horizontal=false;
          if(sOr==0)
            horizontal=true;
          

          String res=setup.makePlacement(x, y ,horizontal);
          report_field.setText(res);
         /// System.out.println(res);	
          //add later: Delay 3s
        
        

          if(res=="Placement successful!"){

            


            counter++;
            Integer player=counter/7+1;
            Integer shipnr=(counter%7+1);
            Integer nlength=length[counter%7];
            Integer clength=length[(counter-1)%7];
            report_field.setText("Player "+player.toString()+"'s turn: Place your ship nr "+shipnr.toString()+"(Length: "+nlength.toString()+")" );
            if(sOr==1)
              for(int i=0; i<clength; i++)
              {
                field[x+i][y].setText("#");
              }
            if(sOr==0)
              for(int i=0; i<clength; i++)
              {
                 field[x][y+i].setText("#");
              }
            if(counter==7)
              for(int i=1;i<11;i++)
                for(int j=1;j<11;j++)
                {
                 field[i][j].setText(" ");
                }
            if(counter==14)
            {
            report_field.setText("Preparations finished!");
           
            dispose();    
            GameState prepared_game=setup.encapsulate();
            GameMaster launch_game=new GameMaster(prepared_game);
            display_game=new GameMasterGUI(launch_game);
              ///start game
            }
          }

          if(res=="Invalid placement request!")
          {
            report_field.setText(temp);
          }
        }
     });

        
        getContentPane().add(BorderLayout.NORTH, report_field);
        getContentPane().add(BorderLayout.CENTER, map_grid);
        getContentPane().add(BorderLayout.SOUTH, panel);
        setVisible(true);
    }

}
