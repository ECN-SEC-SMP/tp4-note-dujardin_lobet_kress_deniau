#include "Parcelle.hpp"

class Constructible : public Parcelle 
{

  private :

    int surfaceConstructible;

  public :

  virtual int surfaceConstructible()const=0;

};