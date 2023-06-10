#include <iostream>
#include <vector>

class Parent {
private:
    float *number;
public:
    Parent(float num = 0.0) {
        number = new float;
        *number = num;
    }
    virtual ~Parent() {
        delete number;
        number = nullptr;
    }
};

class Child : public Parent {
public:
    Child(float num = 0.0) : Parent(num) {}
    ~Child() {}
};

int main() {
    std::vector<Parent *> vector1;
    std::vector<Parent *> vector2;

    // заполняем вектор объектами
    for (int i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            vector1.push_back(new Parent(i));
        } else {
            vector1.push_back(new Child(i));
        }
    }

    // глубокая копия вектора
    for (int i = 0; i < vector1.size(); i++) {
        if (dynamic_cast<Child*>(vector1[i])) {
            vector2.push_back(new Child(*(dynamic_cast<Child*>(vector1[i]))));
        } else {
            vector2.push_back(new Parent(*(vector1[i])));

        }
    }

    // освобождаем ресурсы
    for (int i = 0; i < vector1.size(); i++) {
        delete vector1[i];
    }

    for (int i = 0; i < vector2.size(); i++) {
        delete vector2[i];
    }

    return 0;
}
