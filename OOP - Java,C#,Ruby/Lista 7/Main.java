import javax.swing.*;
import java.io.File;

public class Main {
    public static void main(String[] args) {

        if(args.length != 2) {
            System.err.println("Zakończono działanie: Niewłaściwa liczba argumentów");
            System.exit(1);
        }

        static JFrame ui;
        File obiekt = new File(args[0]);
        String typ = args[1];
        
        switch(typ) {

            case "samochod":
                SamochodSwing interfejsSamochod = new SamochodUI(obiekt);
                ui = new JFrame("Edytowanie: "+ typ);
                ui.add(interfejsSamochod);    
                break;

            case "tramwaj":
                TramwajSwing interfejsTramwaj = new TramwajUI(obiekt);
                ui = new JFrame("Edytowanie: " + typ);
                ui(interfejsTramwaj);
                break;

            default: 
                System.err.println("Zakończono działanie: Nie rozpoznano typu >"+typ+"<");
                System.exit(1);
        }
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}