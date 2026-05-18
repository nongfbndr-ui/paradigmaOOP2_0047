#include <iostream>
using namespace std;

class RekeningBank {
protected:
    double saldo;

public:
    RekeningBank(double s) {
        saldo = s;
    }

    virtual void potongAdmin() = 0;

    void tampilSaldo() {
        cout << "Saldo akhir: Rp " << saldo << endl;
    }
};

class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(double s) : RekeningBank(s) {}

    void potongAdmin() {
        cout << "Rekening Syariah bebas biaya admin" << endl;
    }
};

class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(double s) : RekeningBank(s) {}

    void potongAdmin() {
        saldo -= 15000;
        cout << "Biaya admin Rp 15.000 dipotong" << endl;
    }
};

class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(double s) : RekeningBank(s) {}

    void potongAdmin() {
        if (saldo > 10000000) {
            cout << "Nasabah bebas biaya admin" << endl;
        } else {
            saldo -= 50000;
            cout << "Biaya admin Rp 50.000 dipotong" << endl;
        }
    }
};

int main() {
    RekeningBank* rekening;

    RekeningSyariah syariah(5000000);
    RekeningKonvensional konvensional(5000000);
    RekeningPremium premium(8000000);

    rekening = &syariah;
    rekening->potongAdmin();
    rekening->tampilSaldo();

    cout << endl;

    rekening = &konvensional;
    rekening->potongAdmin();
    rekening->tampilSaldo();

    cout << endl;

    rekening = &premium;
    rekening->potongAdmin();
    rekening->tampilSaldo();

    return 0;
}