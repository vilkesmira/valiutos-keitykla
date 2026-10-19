#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Valiutu kursu konstantos
    const double GBP_Bendras = 0.8729;
    const double GBP_Pirkti  = 0.8600;
    const double GBP_Parduoti = 0.9220;

    const double USD_Bendras = 1.1793;
    const double USD_Pirkti  = 1.1460;
    const double USD_Parduoti = 1.2340;

    const double INR_Bendras = 104.6918;
    const double INR_Pirkti  = 101.3862;
    const double INR_Parduoti = 107.8546;

    int meniuPasirinkimas;

    do {
        // Pagrindinis MENIU
        cout << "\n===============================" << endl;
        cout << "    VALIUTOS KEITYKLOS MENIU   " << endl;
        cout << "===============================" << endl;
        cout << "1. Valiutos kurso palyginimas su euru" << endl;
        cout << "2. Valiutos pirkimas (EUR -> pasirinkta valiuta)" << endl;
        cout << "3. Valiutos pardavimas (pasirinkta valiuta -> EUR)" << endl;
        cout << "4. Išeiti" << endl;
        cout << "Pasirinkite veiksma (1-4): ";
        cin >> meniuPasirinkimas;

        // Tikrinama, ar ivestas skaicius ir ar pasirinkimas teisingas
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Klaida: ivestas ne skaicius. Bandykite dar karta." << endl;
            continue;
        }

        if (meniuPasirinkimas == 4) {
            cout << "Programa baigia darba. Viso gero!" << endl;
            break;
        }

        if (meniuPasirinkimas < 1 || meniuPasirinkimas > 4) {
            cout << "Klaida: neteisingas meniu pasirinkimas. Pasirinkite nuo 1 iki 4." << endl;
            continue;
        }

        // Valiutos pasirinkimas
        int valiutosPasirinkimas;
        cout << "\nPasirinkite valiuta:" << endl;
        cout << "1. GBP (Didžiosios Britanijos svaras)" << endl;
        cout << "2. USD (Jungtiniu Amerikos Valstiju doleris)" << endl;
        cout << "3. INR (Indijos rupija)" << endl;
        cout << "Pasirinkite valiuta (1-3): ";
        cin >> valiutosPasirinkimas;

        if (cin.fail() || valiutosPasirinkimas < 1 || valiutosPasirinkimas > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Klaida: neteisingas valiutos pasirinkimas. Bandykite iš naujo." << endl;
            continue;
        }

        string valiutosPavadinimas = "";
        double bendrasKursas = 0.0;
        double pirktiKursas = 0.0;
        double parduotiKursas = 0.0;

        if (valiutosPasirinkimas == 1) {
            valiutosPavadinimas = "GBP";
            bendrasKursas = GBP_Bendras;
            pirktiKursas = GBP_Pirkti;
            parduotiKursas = GBP_Parduoti;
        } else if (valiutosPasirinkimas == 2) {
            valiutosPavadinimas = "USD";
            bendrasKursas = USD_Bendras;
            pirktiKursas = USD_Pirkti;
            parduotiKursas = USD_Parduoti;
        } else if (valiutosPasirinkimas == 3) {
            valiutosPavadinimas = "INR";
            bendrasKursas = INR_Bendras;
            pirktiKursas = INR_Pirkti;
            parduotiKursas = INR_Parduoti;
        }

        // Veiksmo vykdymas pagal pasirinkima
        if (meniuPasirinkimas == 1) {
            // 1. Valiutos kurso palyginimas (rodomos abi kryptys)
            cout << fixed << setprecision(4);
            cout << "\n--- VALIUTOS KURSAS (" << valiutosPavadinimas << " / EUR) ---" << endl;
            cout << "Bendras kursas (1 EUR = " << bendrasKursas << " " << valiutosPavadinimas << ")" << endl;
            cout << "Atvirkštinis kursas (1 " << valiutosPavadinimas << " = " << (1.0 / bendrasKursas) << " EUR)" << endl;
            cout << "Pirkimo kursas (EUR -> " << valiutosPavadinimas << "): " << pirktiKursas << endl;
            cout << "Pardavimo kursas (" << valiutosPavadinimas << " -> EUR): " << parduotiKursas << endl;
        } 
        else if (meniuPasirinkimas == 2) {
            // 2. Valiutos pirkimas (EUR -> pasirinkta valiuta)
            double sumaEur;
            cout << "Iveskite suma EUR, už kuria norite pirkti " << valiutosPavadinimas << ": ";
            cin >> sumaEur;

            if (cin.fail() || sumaEur <= 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Klaida: suma turi buti teigiama skaitmenine reikšme." << endl;
                continue;
            }

            double gaunamaSuma = sumaEur * pirktiKursas;
            
            cout << fixed << setprecision(2);
            cout << "\n--- PIRKIMO REZULTATAS ---" << endl;
            cout << "Pradine suma: " << sumaEur << " EUR" << endl;
            cout << "Pasirinkta valiuta: " << valiutosPavadinimas << endl;
            cout << "Gaunama suma: " << gaunamaSuma << " " << valiutosPavadinimas << endl;
        } 
        else if (meniuPasirinkimas == 3) {
            // 3. Valiutos pardavimas (pasirinkta valiuta -> EUR)
            double sumaValiutos;
            cout << "Iveskite suma (" << valiutosPavadinimas << "), kuria norite parduoti: ";
            cin >> sumaValiutos;

            if (cin.fail() || sumaValiutos <= 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Klaida: suma turi buti teigiama skaitmenine reikšme." << endl;
                continue;
            }

            double gaunamaSumaEur = sumaValiutos / parduotiKursas;

            cout << fixed << setprecision(2);
            cout << "\n--- PARDAVIMO REZULTATAS ---" << endl;
            cout << "Pradine suma: " << sumaValiutos << " " << valiutosPavadinimas << endl;
            cout << "Pasirinkta valiuta: EUR" << endl;
            cout << "Gaunama suma: " << gaunamaSumaEur << " EUR" << endl;
        }

    } while (true);

    return 0;
}