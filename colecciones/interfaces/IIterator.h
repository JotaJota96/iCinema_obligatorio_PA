/* 
 * File:   IIterator.h
 * Author: igui
 *
 * Created on 28 de mayo de 2011, 07:43 PM
 */

#include "ICollectible.h"

#ifndef _IITERATOR_H
#define	_IITERATOR_H

/** 
 * Interfaz de iteradores
 */ 
class IIterator{
public:
    virtual ICollectible *getCurrent() = 0;	//  Devuelve el actual elemento de la colección en la iteración.  Tira una excepción out_of_range si no hay tal elemento
    virtual bool hasCurrent() = 0;	//  Devuelve true si hay un elemento en la colección. 
    virtual void next() = 0;	//  Hace un paso en la iteración. Si hasCurrent() es false tira excepción out_of_range
    virtual ~IIterator();
};

#endif	/* _IITERATOR_H */

