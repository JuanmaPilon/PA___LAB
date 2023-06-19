#ifndef FABRICA_H
#define FABRICA_H
class Fabrica: public IForo {
    public:
        static Fabrica* getInstance();
        ~Fabrica(); 

    private:
        static Fabrica* instancia;
        Fabrica();
};
#endif