import java.lang.String;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.File;

public class Samochod extends Pojazd {
    double moc; // KM
    double zuzyciePaliwa; // l/100km
    double przyspieszenie; // km/h

    public Samochod() {
        super();
        this.moc = 0;
        this.zuzyciePaliwa = 0;
        this.przyspieszenie = 0;
    }

    /*
     * public Samochod(String marka, String model, int rokProdukcji, double moc,
     * double zuzyciePaliwa, double przyspieszenie) { super(marka, model,
     * rokProdukcji); this.moc = moc; this.zuzyciePaliwa = zuzyciePaliwa;
     * this.przyspieszenie = przyspieszenie; }
     */

    public String toString() {
        return (super.toString() + 
                "Moc: " + this.moc + "KM\n" + 
                "Zużycie paliwa: " + this.zuzyciePaliwa + "l/100km\n" + 
                "Przyspieszenie: " + this.przyspieszenie + "km/h\n");
    }

    // gettery, settery
    public double getMoc() {
        return moc;
    }

    public double getZuzyciePaliwa() {
        return zuzyciePaliwa;
    }

    public double getPrzyspieszenie() {
        return przyspieszenie;
    }

    public void setMoc(double moc) {
        this.moc = moc;
    }

    public void setZuzyciePaliwa(double zuzyciePaliwa) {
        this.zuzyciePaliwa = zuzyciePaliwa;
    }

    public void setPrzyspieszenie(double przyspieszenie) {
        this.przyspieszenie = przyspieszenie;
    }

    public void Odczyt(File plik) {
        Samochod odczytPojazd = null;

        try {
            FileInputStream fileIn = new FileInputStream(plik);
            ObjectInputStream in = new ObjectInputStream(fileIn);

            odczytPojazd = (Samochod) in.readObject();

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
            moc = odczytPojazd.moc;
            zuzyciePaliwa = odczytPojazd.zuzyciePaliwa;
            przyspieszenie = odczytPojazd.przyspieszenie;
        }

    }
}