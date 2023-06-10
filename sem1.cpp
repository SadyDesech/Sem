#include <iostream>
#include <vector>

using namespace std;

class Yashik {
protected:
    float* m_var;
public:
    Yashik() {
        m_var = new float(0);
    }
    Yashik(const float var) {
        m_var = new float (var);
    }
    virtual ~Yashik(){}
};
class Korobka : public Yashik {
private:
    int m_Kvar;
public:
    Korobka(const int var) {
        m_Kvar = var;
    }
    ~Korobka(){}
};

vector <Yashik*> Wagon;
vector <Yashik*> Lorry;   

void fill() {
    for (int i = 0; i < 3; i++) {
        Wagon.push_back(new Yashik(i + i / 10)); //i + i/10 - имитация рандомных значений
        Wagon.push_back(new Korobka(i)); // тоже самое
    }
}

int main()
{
    fill();
    for (int i = 0; i < 3; i++) {
        Lorry.push_back(Wagon.back());
        Wagon.pop_back();
    }
}
