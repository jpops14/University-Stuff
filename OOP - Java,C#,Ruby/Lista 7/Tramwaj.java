import java.lang.String;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.File;

public class Tramwaj extends Pojazd {
    double rozstawToru; // mm
    double wysokoscPodlogi; // cm
    int iloscMiejsc;

    public Tramwaj() {
        super();
        this.rozstawToru = 0;
        this.wysokoscPodlogi = 0;
        this.iloscMiejsc = 0;
    }

    private String okreslWysokoscPodlogi() {
        if (this.wysokoscPodlogi > 80) {
            return "wysokopodłogowy";
        } else if (this.wysokoscPodlogi > 40) {
            return "średniopodłogowy";
        }
        return "niskopodłogowy";
    }

    public String toString() {
        
        return (super.toString() + "Rozstaw toru: " + this.rozstawToru + "mm\n" +
                "Wysokość podłogi: " + okreslWysokoscPodlogi() + " (" + this.wysokoscPodlogi + "cm)\n" +
                "Ilość miejsc: " + this.iloscMiejsc + "\n");
    }

    // gettery, settery
    public double getRozstawToru() {
        return rozstawToru;
    }

    public double getWysokoscPodlogi() {
        return wysokoscPodlogi;
    }

    public int getIloscMiejsc() {
        return iloscMiejsc;
    }

    public void setRozstawToru(double rozstawToru) {
        this.rozstawToru = rozstawToru;
    }

    public void setWysokoscPodlogi(double wysokoscPodlogi) {
        this.wysokoscPodlogi = wysokoscPodlogi;
    }

    public void setIloscMiejsc(int iloscMiejsc) {
        this.iloscMiejsc = iloscMiejsc;
    }

    public void Odczyt(File plik) {
        Tramwaj odczytPojazd = null;

        try {
            FileInputStream fileIn = new FileInputStream(plik);
            ObjectInputStream in = new ObjectInputStream(fileIn);

            odczytPojazd = (Tramwaj) in.readObject();

            in.close();
            fileIn.close();

        } catch (IOException i) {
            i.printStackTrace();

        } catch (ClassNotFoundException c) {
            System.out.println("Class not found");
            c.printStackTrace();
        }

        if (odczytPojazd != null) {
            System.out.println("Odczytano pojazd:\n");
            System.out.println(odczytPojazd.toString());

            marka = odczytPojazd.marka;
            model = odczytPojazd.model;
            rokProdukcji = odczytPojazd.rokProdukcji;
            rozstawToru = odczytPojazd.rozstawToru;
            wysokoscPodlogi = odczytPojazd.wysokoscPodlogi;
            iloscMiejsc = odczytPojazd.iloscMiejsc;
        }

    }

}