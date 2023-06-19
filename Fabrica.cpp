#include "Fabrica.h"

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {

}

Fabrica* Fabrica::getInstance() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}
Fabrica::~Fabrica() {
};
