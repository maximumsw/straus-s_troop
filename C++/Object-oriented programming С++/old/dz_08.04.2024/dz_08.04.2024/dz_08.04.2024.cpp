#include <iostream>
#include <cstring>
using namespace std;

class Reservoir
{
    char* name;
    double* depth;
    double* length;
    double* width;
    
    
    

public:
    Reservoir()
    {
        const int size = 8;
        this->name = new char[size+1];
        strcpy_s(this->name, size + 1, "Nameless");

        this->depth = 0;
        this->length = 0;
        this->width = 0;
    }

    Reservoir(char* nm)
    {
        if (nm != nullptr)
        {
            int size = strlen(nm);
            this->name = new char[size + 1];
            strcpy_s(this->name, size + 1, nm);
        }
        
        
    }

    Reservoir(char* nm, double dep)
    {
        if (nm != nullptr)
        {
            int size = strlen(nm);
            this->name = new char[size + 1];
            strcpy_s(this->name, size + 1, nm);
            if (dep != 0)
            {
                this->depth = new double[dep];
            }
        }
    }
    Reservoir(char* nm, double dep, double len, double wid)
    {
        if (nm != nullptr)
        {
            int size = strlen(nm);
            this->name = new char[size + 1];
            strcpy_s(this->name, size + 1, nm);
        }
        if (dep > 0)
        {
            this->depth = new double[dep];
        }
        if (len > 0)
        {
            this->depth = new double[dep];
        }
        if (wid > 0)
        {
            this->depth = new double[dep];
        }
    }

    

    char* getName()
    {
        return this->name;
    }
    double* getDepth()
    {
        return this->depth;
    }
    double* getLenth()
    {
        return this->length;
    }
    double* getWidth()
    {
        return this->width;
    }
    


    // Деструктор для звільнення пам'яті
    ~Reservoir()
    {
        delete[] name;
        delete depth;
        delete length;
        delete width;
        
    }
};

int main()
{
    int size = 255;
    char* nm = new char[size];
    strcpy_s(nm, size, "Lake Victoria");


    Reservoir lake1(nm);
    cout << lake1.getName() << endl;

    Reservoir lake2;
    cout << lake2.getName() << endl;

    delete[] nm;  // Звільняємо пам'ять, виділену в main
}
