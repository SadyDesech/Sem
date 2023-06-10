#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base {
protected:
    int* m_var;
public:
    Base() {
        m_var = new int(0);
    }
    Base(const Base& obj_copy) { m_var = new int(*(obj_copy.m_var)); }
    virtual Base* copy() { return new Base(*this); }
    virtual ~Base() { delete m_var; }
};

class Derived : public Base {
private:
    string m_st;
public:
    Derived() {
        m_st = "Prostite";
    }
    Derived(const Derived& obj_copy):Base(obj_copy) { m_st = obj_copy.m_st; }
    virtual Base* copy() { return new Derived(*this); }
    ~Derived() {}
};


class DB{
private:
    vector <Base*>* m_ob1;
public:
    DB() {
        m_ob1 = new vector<Base*>();
    };
    DB(const DB& obj_copy) : m_ob1(new vector <Base*>()) {
        for (int i = 0; i < (*obj_copy.m_ob1).size(); i++) {
            m_ob1->push_back(((*obj_copy.ob1)[i])->copy());
        }
    }
    DB* copy() { return new DB(*this); }
    template <typename T>
    void add() {
        (* (this->m_ob1)).push_back(new T);
    }
    ~DB() {
        for (int i = 0; i < (*m_ob1).size(); i++) {
            delete (*m_ob1)[i];
        }
        (*m_ob1).clear();
    }
};

int main()
{
    DB db1;
    DB db2;
    db1.add<Base>();
    db1.add<Derived>();
    db2 = *(db1.copy());
}
