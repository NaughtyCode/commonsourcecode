#include "TObjectTempalte.h"
#include "GlobalData.h"

template<typename T>
TObjectTempalte<T>::TObjectTempalte()
{
    
}

template<typename T>
TObjectTempalte<T>::~TObjectTempalte()
{
    
}

template<typename T>
void TObjectTempalte<T>::SetSelectedObject()
{
    SetSelectedObject((ObjectHandle)this)
}
