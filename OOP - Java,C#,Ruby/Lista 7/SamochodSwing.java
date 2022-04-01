import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

public class SamochodUI extends JPanel implements ActionListener {
    File plik;
    Samochod samochod;
    public JButton zapisz;
    public JTextField  marka, model, rokProdukcji, moc, zuzyciePaliwa, przyspieszenie;

    //tworzy UI dla pojazdu
    public SamochodUI(File plik) {
        this.samochod = new Samochod();
        this.plik = plik;

        if(plik.exists()) {
            samochod.Odczyt(plik);
        }

        JLabel markaLabel = new JLabel("Marka");
        JLabel modelLabel = new JLabel("Model");
        JLabel rokProdukcjiLabel = new JLabel("Rok produkcji");
        JLabel mocLabel = new JLabel("Moc");
        JLabel zuzyciePaliwaLabel = new JLabel("Zuzycie paliwa");
        JLabel przyspieszenieLabel = new JLabel("Przyspieszenie");

        marka = new JTextField(samochod.getMarka());
        model = new JTextField(samochod.getModel());
        rokProdukcji = new JTextField(Integer.toString(samochod.getRokProdukcji()));
        moc = new JTextField(Double.toString(samochod.getMoc()));
        zuzyciePaliwa = new JTextField(Double.toString(samochod.getZuzyciePaliwa()));
        przyspieszenie = new JTextField(Double.toString(samochod.getPrzyspieszenie()));

        zapisz = new JButton("zapisz");
        zapisz.addActionListener(this);
        
        super.add(markaLabel);
        super.add(marka);
        super.add(modelLabel);
        super.add(model);
        super.add(rokProdukcjiLabel);
        super.add(rokProdukcji);
        super.add(mocLabel);
        super.add(moc);
        super.add(zuzyciePaliwaLabel);
        super.add(zuzyciePaliwa);
        super.add(przyspieszenieLabel);
        super.add(przyspieszenie);
        super.add(zapisz);
        super.setLayout(new GridLayout(7,2));
    }
    
    //pobiera dane z pól tekstowych
    public void actionPerformed(ActionEvent e) {
        Object source = e.getSource();
        if (source == zapisz) {
            samochod.setMarka(marka.getText());
            samochod.setModel(model.getText());
            samochod.setRokProdukcji(Integer.parseInt(rokProdukcji.getText()));
            samochod.setMoc(Double.parseDouble(moc.getText()));
            samochod.setZuzyciePaliwa(Double.parseDouble(zuzyciePaliwa.getText()));
            samochod.setPrzyspieszenie(Double.parseDouble(przyspieszenie.getText()));

            samochod.Zapis(plik);
        }
    }


}
