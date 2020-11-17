#include <iostream>
using namespace std;

class Singleton
{
private:
    static Singleton* instance;
    Singleton()
    {
    }
    ~Singleton()
    {

    }
public:
    static Singleton* get()
    {
        if (instance == NULL)
        {
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = NULL;

int main(int argc, const char* argv[])
{
    Singleton* s1 = Singleton::get();
    Singleton* s2 = Singleton::get();
    cout << s1 << endl << s2 << endl;
    return 0;
}
