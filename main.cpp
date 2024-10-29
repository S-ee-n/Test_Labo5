#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

double saisie () {
    bool bonne_saisie = false;
    double n = 0.0;
    double min = 0;
    int long long max = 999999999999999.99;
    do {
        bonne_saisie = (cin >> n) && (n >= min) && (n<=max);
        if(!bonne_saisie){
            cout << "erreur : montant ";
            if (n < min) {
                cout << "negatif" << endl;
            } else if (n > max) {
                cout << "trop grand" << endl;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (!bonne_saisie);
    return n;
}


// chaque paquet de mille :

void exprime_paquet_mille(string nombre, int numero_paquet) {

    // centaines
    switch (nombre[nombre.length()-3*numero_paquet]) {
        case '0': cout << "rien "; break;
        case '1': cout << "cent "; break;
        case '2': cout << "deux "; break;
        case '3': cout << "trois "; break;
        case '4': cout << "quatre "; break;
        case '5': cout << "cinq "; break;
        case '6': cout << "six "; break;
        case '7': cout << "sept "; break;
        case '8': cout << "huit "; break;
        case '9': cout << "neuf "; break;
    }

    cout << "cent ";

    // dizaines
    switch (nombre[nombre.length()-3*numero_paquet+1]) {
        case '0': cout << "rien "; break;
        case '1': cout << "dix-"; break;
        case '2': cout << "vingt-"; break;
        case '3': cout << "trente-"; break;
        case '4': cout << "quarante-"; break;
        case '5': cout << "cinquante-"; break;
        case '6': cout << "soixante-"; break;
        case '7': cout << "septante-"; break;
        case '8': cout << "huitante-"; break;
        case '9': cout << "nonante-"; break;
    }

    // unités
    switch (nombre[nombre.length()-3*numero_paquet+2]) {
        case '0': cout << "rien "; break;
        case '1': cout << "un "; break;
        case '2': cout << "deux "; break;
        case '3': cout << "trois "; break;
        case '4': cout << "quatre "; break;
        case '5': cout << "cinq "; break;
        case '6': cout << "six "; break;
        case '7': cout << "sept "; break;
        case '8': cout << "huit "; break;
        case '9': cout << "neuf "; break;
    }
}

void exprime_separation(int numero_paquet) {
    switch (numero_paquet) {
        case 5: cout << "billions "; break;
        case 4: cout << "milliards "; break;
        case 3: cout << "millions "; break;
        case 2: cout << "mille "; break;
    }
}

int main() {
    double n = saisie();
    stringstream flux_pour_pt_entiere ;
    flux_pour_pt_entiere << fixed << setprecision(0) << n;
    string pt_entiere = flux_pour_pt_entiere.str();
    cout << pt_entiere << endl;

    for (int numero_paquet = 3; numero_paquet >= 1; --numero_paquet) {
        exprime_paquet_mille(pt_entiere, numero_paquet);
        exprime_separation(numero_paquet);

    }
}
