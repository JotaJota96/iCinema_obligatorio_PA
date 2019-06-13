TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        clases/cpp/Cine.cpp \
        clases/cpp/Puntuacion.cpp \
        clases/cpp/Reserva.cpp \
        clases/cpp/ReservaCredito.cpp \
        clases/cpp/ReservaDebito.cpp \
        clases/cpp/Sala.cpp \
        clases/cpp/Usuario.cpp \
        colecciones/Integer.cpp \
        colecciones/String.cpp \
        colecciones/collections/List.cpp \
        colecciones/collections/ListIterator.cpp \
        colecciones/collections/ListNode.cpp \
        colecciones/collections/OrderedDictionary.cpp \
        colecciones/collections/OrderedDictionaryEntry.cpp \
        colecciones/interfaces/ICollectible.cpp \
        colecciones/interfaces/ICollection.cpp \
        colecciones/interfaces/IDictionary.cpp \
        colecciones/interfaces/IIterator.cpp \
        colecciones/interfaces/IKey.cpp \
        colecciones/interfaces/OrderedKey.cpp \
        datatypes/cpp/DateTime.cpp \
        datatypes/cpp/Direccion.cpp \
        datatypes/cpp/DtCine.cpp \
        datatypes/cpp/DtComentario.cpp \
        datatypes/cpp/DtFuncion.cpp \
        datatypes/cpp/DtPelicula.cpp \
        datatypes/cpp/DtReserva.cpp \
        datatypes/cpp/DtReservaCredito.cpp \
        datatypes/cpp/DtReservaDebito.cpp \
        datatypes/cpp/DtSala.cpp \
        main.cpp

HEADERS += \
	clases/h/Cine.h \
	clases/h/Puntuacion.h \
	clases/h/Reserva.h \
	clases/h/ReservaCredito.h \
	clases/h/ReservaDebito.h \
	clases/h/Sala.h \
	clases/h/Usuario.h \
	colecciones/Integer.h \
	colecciones/String.h \
	colecciones/collections/List.h \
	colecciones/collections/ListIterator.h \
	colecciones/collections/ListNode.h \
	colecciones/collections/OrderedDictionary.h \
	colecciones/collections/OrderedDictionaryEntry.h \
	colecciones/interfaces/ICollectible.h \
	colecciones/interfaces/ICollection.h \
	colecciones/interfaces/IDictionary.h \
	colecciones/interfaces/IIterator.h \
	colecciones/interfaces/IKey.h \
	colecciones/interfaces/OrderedKey.h \
	datatypes/h/DateTime.h \
	datatypes/h/Direccion.h \
	datatypes/h/DtCine.h \
	datatypes/h/DtComentario.h \
	datatypes/h/DtFuncion.h \
	datatypes/h/DtPelicula.h \
	datatypes/h/DtReserva.h \
	datatypes/h/DtReservaCredito.h \
	datatypes/h/DtReservaDebito.h \
	datatypes/h/DtSala.h
