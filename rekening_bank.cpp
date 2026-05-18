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

