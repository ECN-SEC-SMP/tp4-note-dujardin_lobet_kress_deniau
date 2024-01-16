#include "Parcelle.hpp"

class Constructible : public Parcelle 
{

  private :

    int surfaceConstructible;

  public :

  virtual int surfaceConstructible(int surfaceConstructible)const=0;

};