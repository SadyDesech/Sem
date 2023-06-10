#include <iostream>
#include <vector>

using namespace std;

class Base {
protected:
    int* m_var;
public:
    Base() {
        m_var = new int(0);
    }
    Base(const Base& obj_copy) : m_var(new int) { *m_var = *obj_copy.m_var; }
    virtual Base* copy() { return new Base(*this); }
    virtual ~Base() { delete m_var; }
};

class Child : public Base {
public:
    float m_float;
    Child() {
        m_float = 2.61;
    };
    Child(const Child& obj_copy) { m_float = obj_copy.m_float; }
    virtual Base* copy() { return new Child(*this); }
    ~Child() {}
};

class Notchild : public Base {
private:
    char m_char;
public:
    Notchild() {
        m_char = 'm';
    };
    Notchild(const Notchild& obj_copy) { m_char = obj_copy.m_char; }
    virtual Base* copy() { return new Notchild(*this); }
    ~Notchild() {}
};

vector <Base*> ob1;
vector <Base*> ob2;

int main()
{
    ob1.push_back(new Base);
    ob1.push_back(new Child);
    ob1.push_back(new NotChild);
    for (int i = 0; i < ob1.size(); i++) {
        Base* new_obj = (ob1[i])->copy();
        ob2.push_back(new_obj);
    }

    for (int i = 0; i < ob1.size(); i++) {
        delete ob1[i];
    }
    for (int i = 0; i < ob2.size(); i++) {
        delete ob2[i];
    }
    ob1.clear();
    ob2.clear();
}
