
#MaaT - DevKit

Lo scopo di questo strumento è rendere possibile ed agevole lo sviluppo di moduli.

Poiché il progetto cerca di rendere l'accesso alle funzionalità in maniera modulare se pur utilizzando un meccanismo di link statico (per le ovvie ragioni embedded) si cerca di forzare questo meccanismo con l'ausilio di una suite di compilazione.

Prendendo spunto dal compilatore e la gestione delle librerie di Arduino IDE, si simula gli import e la compilazione del codice costruendo un vero e proprio progetto funzionante sulla propria architettura di sviluppo. In tal modo sarà quindi agevole sia l'editing (ad esempio mediante IDE) sia la compilazione.

##Quick Start

1. Inizia a configurare l'ambiente e lancia il comando:

'''bash
./config.sh
'''

2. Genera tutti i file oggetto con il comando:

'''
make all
'''

3. Il nuovo modulo della libreria è 'module', composto da codice '.cpp' ed header '.h' : editalo.

4. Adesso puoi compilare il modulo 'module' con il comando:

'''
make module.o
'''

5. Opzionalmente puoi generare un 'main.cpp' e provare il codice: puoi compilarlo lanciando il comando:

'''
make test_newmodule
'''

   Se il modulo fa uso di altri moduli, inserirli nel Makefile alla variabile 'IMPORTED_LIBRARY' separandoli con uno spazio.


##Descrizione del Kit

In questa cartella è presente un progetto C/CPP, la sua struttura è cosi definita:

- src:
  In questa cartella sono presenti tutti i file di codice dei moduli.
  I file sono ricopiati dalla root del progetto git in questa cartella al lancio del comando config.sh

- include:
  In questa cartella sono presenti tutti i file header di tutti i moduli.
  Anche questi sono ricopiati dalla root del progetto git mediante lo script config.sh

- obj:
  In questa cartella sono presenti tutti i codici oggetto dei moduli della libreria
  Sono generati mediante la console di compilazione 'Makefile'

- il nuovo modulo (module.h e module.cpp):
  Sono i nuovi file del nuovo modulo, rispettivamente l'header ed il codice associato (se presente).
  Terminato lo sviluppo possono essere aggiunti nella root del progetto git in una opportuna sottodirectory.

- main.cpp:
  Un main da utilizzare per prove e testing del nuovo modulo e la sua integrazione con il restante ambiente.