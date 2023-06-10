#include <iostream>
#include <vector>

using namespace std;

class Base {
public:
    Base() {}
    Base(const Base& obj_copy) {}
    virtual Base* copy() { return new Base(*this); }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    Derived() {}
    Derived(const Derived& obj_copy) : Base(obj_copy) {}
    virtual Base* copy() { return new Derived(*this); }
    ~Derived() {}
};

class Parent {
public:
    vector <Base*> m_ob;
    Parent() = default;
    Parent(const Parent& obj_copy) {
        for (int i = 0; i < obj_copy.m_ob.size(); i++) {
            m_ob.push_back((obj_copy.m_ob[i])->copy());
        }
    }
    virtual Parent* copy() { return new Parent(*this); }
    virtual ~Parent() {}
};

class Child : public Parent {
private:
    vector <Base*>* m_ob2;
public:
    Child(const Child& obj_copy): m_ob2(new vector <Base*>()) {
        for (int i = 0; i < (*obj_copy.m_ob2).size(); i++) {
            m_ob2->push_back(((*obj_copy.m_ob2)[i])->copy());
        }
    }
    virtual Child* copy() { return new Child(*this); }
    ~Child() {}
};
