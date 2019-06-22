# iCinema

**Tecnólogo en informática - UTEC**

**Programación Avanzada - 2019**

## 
### Laboratorio 1

La empresa **iCinema** , una de las firmas que dispone de montones de salas de cine por todoelpaís,deseamejorarlacalidaddesuservicio,porloqueselehaencomendadoeldesarrollo de una aplicación para la reserva de entradas, de manera de evitar las colas largas y las esperas innecesarias. En dicha aplicación se desea que se registren usuarios, los cuales serán identificados por un nickname y deberán tener una imagen de perfil, (de la cual se almacenará su url) y una contraseña. El nickname y su contraseña le permitirán iniciar sesión en el sistema para poder disfrutar de todassus funcionalidades.

Delaspelículasinteresasabersutítuloquelaidentifica,suposter(urldelmismo)yunabreve sinopsis. Interesa saber las películas que se transmiten en los diferentes cines de la firma. Cada cineestáidentificadoporunnúmero.Tambiénsedeseasaberladireccióndecadacine,paraqueel usuario pueda elegir funciones en aquellos que le queden cerca. Cada cine dispone de salas, (también identificadas por número), que tienen diferente capacidad(medida en cantidad de asientos).

Enloscinessetransmitendistintasfuncionesparacadapelícula.Lafunciónseidentificapor un número, y es importante saber en qué sala se pasa dicha función. Además es imprescindible saber la fecha y horario de cadauna.

La aplicación debe brindarle al usuario la posibilidad de realizar una reserva para cualquier función.Interesasabercuántosasientosreservóparalamisma,ysucostototal.Lareservapuede ser realizada con tarjeta de crédito o con tarjeta de débito. En caso de ser de débito es importante saberelbancoquelaemitió.Encasodeserdecrédito,puededisponerdedescuentos,porloque se debe saber el porcentaje de descuento que tiene y la financiera a la quepertenece.

Los usuarios registrados pueden puntuar a las películas y/o realizar comentarios sobre las mismas. Tanto de los puntajes como de los comentarios es importante saber el usuario que lo realiza y la película a la que se refiere. Interesa además saber el puntaje promedio de cada película. Por último, los usuarios pueden responder comentarios realizados, por lo que también interesa registrarlos.

## 
### Laboratorio 2


El equipo de analistas del proyecto recabó información adicional acerca del sistema y como conclusión se hará primero un prototipo como prueba de concepto. Para ello se definieron ciertos requisitos funcionales a satisfacer. Estos requisitos están expresados en los siguientes casos de uso.

Un aspecto no funcional que se recabó es que el prototipo será usado por un usuario a la vez; no concurrentemente. Por último, en todos los casos de uso que se necesite, asumir que se cuenta con la fecha y hora actual (“fecha y hora del sistema”).

#### Casos de uso


| Nombre | **Iniciar Sesión** |
| --- | --- |
| Actores | **Usuario** |
|    Sinopsis | El caso de uso comienza cuando un usuario, que no tiene una sesión iniciada, desea iniciar sesión en el sistema ingresando su nickname. El sistema solicita su contraseña y si es correcta se asigna la sesión al usuario. Si se ingresa una contraseña incorrecta, el usuario podrá volver a ingresar otra o cancelar el caso de uso. |

# 

| Nombre | **Alta Cine** |
| --- | --- |
| Actores | **Usuario Administrador** |
|       Sinopsis | El caso de uso comienza cuando un administrador, que previamente ha iniciado sesión, desea agregar cines en el sistema.Para cada  cine,  en  primer  lugar,  el  sistema  le permite ingresar la dirección del cine. Luego, le permite ingresar una a una las salas del cine. Para cada sala, le solicita que ingrese su capacidad. Finalmente, el sistema le solicita que confirme o cancele si desea agregar el cine. Si confirma, el sistema da de alta al cine y sus salas generando internamente (es decir, sin solicitarle al administrador) el número del cine y los números de las salas. Si cancela continúa con el siguiente cine si así lo desea o termina el caso de uso. |

# 

| Nombre | **Alta Función** |
| --- | --- |
| Actores | **Usuario Administrador** |
|        Sinopsis | El caso de uso comienza cuando un administrador, que previamente ha iniciado sesión, desea dar de alta una función. Para ello el sistema lista las películas existentes y el usuario elige una. A continuación el sistema lista los cines y el usuario debe seleccionar uno. Luego el sistema lista las salas del cine elegido indicando la cantidad de asientos que poseen y cuando están ocupadas. Una vez seleccionada la sala el usuario ingresa la fecha y hora de la función y el sistema la da de alta. Esto se repite mientras el usuario quiera seguir agregando funciones para esapelícula. |

# 

| Nombre | **Crear Reserva** |
| --- | --- |
| Actores | **Usuario** |
|              Sinopsis | El caso de uso comienza cuando un usuario, que previamente ha iniciado sesión, desea reservar asientos para ver una película. El sistema lista los títulos de todas las películas registradas, y el usuario selecciona el título que desee, o puede cancelar. En caso de seleccionar una película, el sistema muestra su póster, y su sinopsis. El usuario puede elegir si finalizar el caso de uso, o ver información adicional de dicha película. Si desea ver la información adicional, se listan los cines en los que pasan esa película. Se puede optar por finalizar, o seleccionar un cine. Si se selecciona un cine, se listan para esa película y ese cine las funciones existentes en el sistema posterior a la fecha y hora actual. El usuario puede repetir este proceso para otra película, si lo desea. Una vez elegida la película, selecciona la función que desea ver, y el sistema le solicita la cantidad de asientos que desea reservar. Una vez ingresada la cantidad, el sistema le pide que ingrese el modo de pago. El usuario debe indicar si se trata de una tarjeta de crédito o de débito. En caso de ser de débito debe ingresar el nombre del banco. En caso de ser de crédito debe especificar el nombre de la financiera, y el sistema le indica para esa financiera si tiene descuento y cuánto es.Finalmente, el usuario ve el precio total y puede confirmar o cancelar. Si confirma se crea la reserva en el sistema. |

# 

| Nombre | **Puntuar Película** |
| --- | --- |
| Actores | **Usuario** |
|      Sinopsis |  El caso de uso comienza cuando un usuario, que previamente ha iniciado sesión, desea puntuar una película. Para ello el sistema lista las películas existentes y el usuario selecciona una. Si el usuario ya puntuó la película elegida, se le mostrará el puntaje anterior. Si desea modificarlo deberá ingresar el nuevo puntaje, en caso contrario el caso de uso finaliza. Si el usuario nunca la puntuó, ingresa el puntaje y el sistema lo registra. |

# 

| Nombre | **Comentar Película** |
| --- | --- |
| Actores | **Usuario** |
|      Sinopsis | El caso de uso comienza cuando un usuario, quepreviamente ha iniciado sesión, desea comentar una película. Para ello el sistema lista las películas existentes y el usuario elige una. Luego el sistema lista los comentarios de la película elegida. El usuario entonces puede elegir entre realizar un nuevo comentario o responder a uno ya existente. Si crea uno nuevo, debe ingresar el texto. En caso de responder a otro comentario debe primero elegirlo y luego ingresar el texto de respuesta. Esto último se repite mientras el usuario quiera seguiragregando comentarios para esa película. |

# 

| Nombre | **Eliminar Película** |
| --- | --- |
| Actores | **Usuario Administrador** |
|     Sinopsis | El caso de uso comienza cuando el administrador, que previamente ha iniciado sesión, desea eliminar una película del sistema. El sistema lista los títulos de todas las películas registradas y el administrador selecciona la que desea eliminar. El sistema le pide que confirme y el administrador puede confirmar o cancelar y termina el caso de uso. En caso de confirmar se borran del sistema la película y todas las funciones y reservas asociadas a la misma. |

# 

| Nombre | **Ver Información de Película** |
| --- | --- |
| Actores | **Invitado, Usuario** |
|    Sinopsis | El caso de uso comienza cuando el actor desea ver información de un a película. El sistema lista los títulos de todas las películas registradas, y el actor selecciona el título que desee, o puede cancelar. En caso de seleccionar una película, el sistema muestra su póster y su sinopsis. El actor puede elegir finalizar el caso de uso, o ver información adicional de dicha película. Si desea ver la información adicional, se listan los cines en los que pasan esa película. Se puede optar por finalizar, o seleccionar un cine. Si se selecciona un cine, se listan para esa película y ese cine las funciones existentes en el sistema posterior a la fecha y hora actual. El actor puederepetir este proceso para otra película, o finalizar el caso de uso. |

# 

| Nombre | **Ver Comentarios y Puntajes de Película** |
| --- | --- |
| Actores | **Invitado, Usuario** |
|               Sinopsis | El caso de uso comienza cuando un actor desea ver información acerca de los puntajes y comentarios sobre una película. Para ello el sistema lista el título y el póster (su url) de las películas registradas y el actor selecciona una de ellas. Luego se muestra la información de los puntajes y comentarios de la película |

