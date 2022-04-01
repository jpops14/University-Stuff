import java.lang.String;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.io.File;

public class Pojazd implements Serializable {

    String marka;
    String model;
    int rocznik;

    public Pojazd() {
        this.marka = "nie określono";
        this.model = "nie określono";
        this.rocznik = 0;
    }
    public Pojazd(String marka, String model, int rocznik) {
        this.marka = marka;
        this.model = model;
        this.rocznik = rocznik;
    }
    public String getMarka() {return marka;}
    public void setMarka(String marka) {this.marka = marka;}
    public String getModel() {return model;}
    public void setModel(String model) {this.model = model;}
    public int getRocznik() {return rocznik;}
    public void setRocznik(int rocznik) {this.rocznik = rocznik;}

    public String toString() {
        return ("Marka: " + marka + "\n"
                "Model: " + model + "\n"
                "Rok produkcji: " + rocznik + "\n");
    }
    ///zapis i odczyt
    public void Zapis(File plik) {
        try {
            FileOutputStream fileOut = new FileOutputStream(plik);
            ObjectOutputStream out = new ObjectOutputStream(fileOut);

            out.writeObject(this);
            out.close();
            
            fileOut.close();
        } catch (IOException i) {
            i.printStackTrace();
        }

    }

    public void Odczyt(File plik) {
        Pojazd wczytanyobiekt = null;

        try {
            FileInputStream fileIn = new FileInputStream(plik);
            ObjectInputStream in = new ObjectInputStream(fileIn);

            wczytanyobiekt = (Pojazd) in.readObject();
            
            in.close();
            fileIn.close();

        }  
        catch (ClassNotFoundException c) {
            System.out.println("Class not found");
            c.printStackTrace();
        }

        if(wczytanyobiekt != null) {
            marka = wczytanyobiekt.marka;
            model = wczytanyobiekt.model;
            rocznik = wczytanyobiekt.rocznik;
        }

    }

    


}