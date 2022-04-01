import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

public class TramwajSwing extends JPanel implements ActionListener {
    File plik;
    Tramwaj tramwaj;
    public JButton zapisz;
    public JTextField marka, model, rokProdukcji, rozstawToru, wysokoscPodlogi, iloscMiejsc;

    //tworzy UI dla pojazdu
    public TramwajSwing(File plik) {
        this.tramwaj = new Tramwaj();
        this.plik = plik;

        if(plik.exists()) {
            tramwaj.Odczyt(plik);
        }

        JLabel markaLabel = new JLabel("Marka");
        JLabel modelLabel = new JLabel("Model");
        JLabel rokProdukcjiLabel = new JLabel("Rok produkcji");
        JLabel rozstawToruLabel = new JLabel("Rozstaw toru");
        JLabel wysokoscPodlogiLabel = new JLabel("Zużycie paliwa");
        JLabel iloscMiejscLabel = new JLabel("Ilość miejsc");

        marka = new JTextField(tramwaj.getMarka());
        model = new JTextField(tramwaj.getModel());
        rokProdukcji = new JTextField(Integer.toString(tramwaj.getRokProdukcji()));
        rozstawToru = new JTextField(Double.toString(tramwaj.getRozstawToru()));
        wysokoscPodlogi = new JTextField(Double.toString(tramwaj.getWysokoscPodlogi()));
        iloscMiejsc = new JTextField(Integer.toString(tramwaj.getIloscMiejsc()));

        zapisz = new JButton("zapisz");
        zapisz.addActionListener(this);
        
        super.add(markaLabel);
        super.add(marka);
        super.add(modelLabel);
        super.add(model);
        super.add(rokProdukcjiLabel);
        super.add(rokProdukcji);
        super.add(rozstawToruLabel);
        super.add(rozstawToru);
        super.add(wysokoscPodlogiLabel);
        super.add(wysokoscPodlogi);
        super.add(iloscMiejscLabel);
        super.add(iloscMiejsc);
        super.add(zapisz);
        super.setLayout(new GridLayout(7,2));
    }
    
    //pobiera dane z pól tekstowych
    public void actionPerformed(ActionEvent e) {
        Object source = e.getSource();
        if (source == zapisz) {
            tramwaj.setMarka(marka.getText());
            tramwaj.setModel(model.getText());
            tramwaj.setRokProdukcji(Integer.parseInt(rokProdukcji.getText()));
            tramwaj.setRozstawToru(Double.parseDouble(rozstawToru.getText()));
            tramwaj.setWysokoscPodlogi(Double.parseDouble(wysokoscPodlogi.getText()));
            tramwaj.setIloscMiejsc(Integer.parseInt(iloscMiejsc.getText()));

            tramwaj.Zapis(plik);
        }
    }


}