// Lightweight.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <unordered_map>

// Інтерфейс легковагового об'єкта
class LightweightObject {
public:
    virtual void operation() const = 0;
    virtual ~LightweightObject() = default;
};

// Конкретний легковаговий об'єкт
class ConcreteLightweightObject : public LightweightObject {
public:
    ConcreteLightweightObject(const std::string& name) : name(name) {}

    void operation() const override {
        std::cout << "Concrete Lightweight Object: " << name << std::endl;
    }

private:
    std::string name;
};

// Фабрика легковагових об'єктів
class LightweightObjectFactory {
public:
    LightweightObject* getLightweightObject(const std::string& key) {
        auto it = lightweightObjects.find(key);
        if (it != lightweightObjects.end()) {
            return it->second;
        }
        else {
            LightweightObject* newObj = new ConcreteLightweightObject(key);
            lightweightObjects[key] = newObj;
            return newObj;
        }
    }

private:
    std::unordered_map<std::string, LightweightObject*> lightweightObjects;
};

int main() {
    LightweightObjectFactory factory;

    LightweightObject* obj1 = factory.getLightweightObject("Object1");
    LightweightObject* obj2 = factory.getLightweightObject("Object2");
    LightweightObject* obj3 = factory.getLightweightObject("Object1");

    obj1->operation();  // Виведе "Concrete Lightweight Object: Object1"
    obj2->operation();  // Виведе "Concrete Lightweight Object: Object2"
    obj3->operation();  // Виведе "Concrete Lightweight Object: Object1"

    // Звільнення ресурсів
    delete obj1;
    delete obj2;
    delete obj3;

    return 0;
}


    // Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
    // Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

    // Советы по началу работы 
    //   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
    //   2. В окне Team Explorer можно подключиться к системе управления версиями.
    //   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
    //   4. В окне "Список ошибок" можно просматривать ошибки.
    //   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
    //   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
