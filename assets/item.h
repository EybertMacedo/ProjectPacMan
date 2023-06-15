#include <iostream>
#include <string>
class item
{   
    private:
        int posicion;
        string tipo;
        bool estado;
    public:
        virtual item();
        virtual ~item();
        virtual int getPosicion() = 0;
        virtual void setPosicion(int) = 0;
        virtual string getTipo() = 0;
        virtual void setTipo(string) = 0;
        virtual bool getEstado() = 0;
        virtual void setEstado(bool) = 0;
};
