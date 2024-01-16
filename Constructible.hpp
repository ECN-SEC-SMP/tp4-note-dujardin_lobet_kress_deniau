#include "Parcelle.hpp"

class Constructible : public Parcelle 
{

  private :

    int surfaceConstructible;

  public :

  virtual int surfaceConstructible() = 0;

};