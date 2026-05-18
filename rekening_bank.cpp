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

