
# MaaT - Analisi numerica su Arduino

## Introduzione

Maat è una libreria di funzioni utilizzabili su Arduino ( c++ compatibile ) che riguarda il calcolo numerico.
Lo scopo del progetto è quello di rendere gli algoritmi numerici fruibili a dispositivi embedded normalmente non predisposti al calcolo strumenti utili per l'analisi di segnali e risoluzione di problemi.

Date le specifiche molto ristrette di dispositivi quali microcontrollori e pic circa lo spazio ed il tempo in termini algoritmici, l'obiettivo del progetto è quello di cercare di massimizzare entrambe ricorrendo dove possibile a stratagemmi: ad esempio a discapito della risorsa più abbondante come il tempo, alla bontà della soluzione o addirittura sfruttando determinati fenomeni che riguardano la metodologia e l'ambiente embedded.


## Il manifesto, obiettivi e principi

In questa sezione voglio elencare quali devono essere gli obiettivi di design del progetto, ma possiamo semplificare i concetti con una semplice metafora: una ferrari con il motore di una 600.

1) **Architettura**

Al primo posto vi è sicuramente l'architettura, intesa nel senso più fisico possibile: ogni volta che si deve prendere una decisione è bene pensare dapprima alla parte fisica e chiedersi se è possibile realizzare quella determinata componente con un circuito fisico e con quale tecnologia (digitale e/o analogico)


2) **Modello di computazione embedded**

In ambienti quali arduino, pic e simili l'architettura prevede generalmente almeno 2 cose:

- *Esiste un corpo di una funzione che viene eseguito ciclicamente una volta che il dispositivo è acceso.*

	Ad esempio Arduino prevede la funzione loop mentre nei pic è solito fare un main al cui interno è presente un while(true).
	Questa visione procedurale equivalente a quanto avviene nell'architettura (quando viene compilato in assembly) deve esserci da guida nella stesura del programma che dovrà risolvere un problema. Non dimentichiamo infatti che il microcontrollore ha il compito di acquisire informazioni dall'esterno ed attuare un azione nell'ambiente in cui opera. In termini di sistemi automatici, il dispositivo è generalmente parte di una catena di retroazione.
	Questa considerazione è molto importante, poiché potrebbe orientare la tipologia di algoritmo di risoluzione verso determinate scelte (es. risoluzione di un sistema lineare classica e quella iterativa) 

- *Esistono chiamate bloccanti e non*

	un algoritmo presente sulla scheda/microcontrollore deve inevitabilmente aver a che fare con codice che gestisce la scheda.
	Per tanto esistono chiamate che possono essere bloccanti, ossia che in qualche modo fermano l'ambiente di esecuzione in cui tali istruzioni sono presenti, e altre invece che non lo sono.
	Generalmente il comportamento può dipendere da vari fattori, ma tipicamente se l'operazione da compiere è commissionata ad altri circuiti elettrici esterni (es. gestione on/off delle porte) allora esse sono non bloccanti. 

- *Altri meccanismi HW/SW*

	oltre queste sono presenti tante altre opzioni ed operazioni in dipendenza della scheda e/o microcontrollore come ad esempio la gestione delle interrupt presenti su alcuni di essi

3) **Risorse: tempo e spazio**

  Anche se le risorse a volte possono essere più del dovuto, specialmente in progetti elementari, bisogna cercare di usarne il meno possibile con parsimonia 


4) **Modularità**

  Creare software a blocchi riutilizzabile è certamente comodo per lo sviluppo del programmatore. Lo scopo principale in questo caso però è non è lo sviluppo bensì la memoria.
  Infatti scrivere blocchi in maniera efficiente (loose coupling) significa caricare solo le componenti necessarie allo scopo, caricando meno codice possibile sulla scheda lasciando spazio per le altri componenti progettuali.
