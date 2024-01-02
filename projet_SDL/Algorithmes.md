## Structure de données :
```
proposition: (valeur ^ nom) = ( Booleen ^ liste <caractère> ) <br>
premElement: ( proposition ^ next ^ pred ) = ( ( valeur ^ nom ) ^ premElement ^ premElement ) 
premisse: Liste<proposition>  , la prémisse d'une regle est représenté sous la forme d'une liste chainée 
regle: ( premisse  ^ conclusion ) = ( Liste <proposition> ^ proposistion ); 
BC: Liste<regle> 
baseFait: Liste<proposition> , représenter sous la forme d'une File, basée sur les entrée de l'utilisateur 
```
## Traduction en C:

```
typedef struct{
           char *nom;
           bool etat;
}proposition;

- TYPE ABSTRAIT regle

typedef struct pElem{
           proposition valeur;
           struct pElem *next;
           struct pElem *pred;
}premElement;

typedef struct {
           premisse *tete;
           premisse *queue;
           proposition *conclusion;
}regle;

```
## Opérations type abstrait regle
- Algorithme du sous programme creerRegle qui cree une regle vide:<br>

```Entête```: Fonction creerRegle():regle<br>
Algorithme Resultat: regle<br>
           Données :<br>
```
Fonction creerRegle():regle<br>
  début
      R:regle<-creerElement()
      tete(R)<-INDEFINI
      queue(R)<-INDEFINI
      conclusion(R)<-INDEFINI
  fin
```

- Algorithme du sous programme ajoutPremisse qui ajoute une proposition à la premisse, en queue

```Entête```: Fonction ajoutPremisse(R:regle, ajout:proposition):regle
Algorithme Resultat: regle <br>
           Données: regle,proposition <br>
```
Fonction ajoutPremisse(R:regle,ajout:proposition):regle
  début
      Si R != INDEFINI alors
        newProp: premElement <- creerElement()
        valeur(newProp) <- ajout
        next(newProp) <- INDEFINI
        pred(newProp) <- INDEFINI
        Si est premisseVide(tete(R)) alors 
            tete(R) <- newProp
            queue(R) <- newProp
        Sinon
            Si queue(R)=tete(R) alors
                   next(tete(R)) <- newProp
                   pred(newProp) <- tete(R)
                   queue(R) <- newProp
            Sinon
                   next(queue(R)) <- newProp
                   pred(newProp) <- queue(R)
                   queue(R) <- newProp
            fin si  
        fin si
      fin si
  fin
```
- Algorithme du sous programme creerConclusion qui crée la conclusion d'une regle  | Deux implementation differentes : soit met en paramètre la proposition associé à la conclusion -> crée OU  on crée la proposition dans la fonction -> recup du nom et de la valeur de la proposition | 

// Algo 1

```Entête```: Fonction creeConclusion(R:regle, titre:liste<caractère,e: Booleen):regle
Algorithme Resultat: regle
           Données: regle,proposition
```
Fonction creerConclusion (R:regle, titre:liste<caractère> ,e: Booleen):regle
  debut
        Si conclusion(R)= INDEFINI ET titre != INDEFINI alors
            concl:proposition <- creerElement()
            nom(concl)<-titre
            etat(concl)<-e
            conclusion(R)<-concl
        fin si
  fin
```

- Algorithme du sous programme pDansRegle qui verifie recursivement si une proposition est dans la premisse d'une regle

```Entête```: Fonction pDansRegle(p: premElement, prop: proposition):Booleen <br>
Algorithme Resultat: booleen <br>
           Données: regle, proposition<br>
```
Fonction pDansRegle(p: premisse, prop: proposition):booleen
  debut
      Si p = INDEFINI alors
          pDansRegle <- FAUX
      Sinon
          si etat(prop)=etat(valeur(p)) ET nom(prop)=nom(valeur(p)) alors
              pDansReglev <- VRAI
          Sinon
              pDansRegle <-pDansRegle(Reste(p),prop)
          fin si
      fin si
  fin
  ```
- Algorithme du sous programme premisseVide qui verifie si une premisse est vide

  ```Entête```: Fonction premisseVide(p: premisse):booléen
  Algorithme Resultat : booléen
             Données : premisse
```
Fonction premisseVide(p: premisse):booléen
  debut
       Si p=INDEFINI alors
            premisseVide<-VRAI
       Sinon
            premisseVide<-Faux
       Fin si
  Fin
```

- Algorithme du sous programme suppProp qui supprime une proposition de la premisse d'une regle

  <br>```Entête```: Fonction suppProp(R: regle, prop: proposition): premisse
Algorithme Resultat: regle <br>
           Données: regle, proposition <br>

```
Fonction suppProp(R: regle, prop: proposition): regle
   debut
           Si R = INDEFINI alors
                suppProp: premisse <-INDEFINI
           Sinon
               Si est premisseVide(tete(R)) alors
                          suppProp <- INDEFINI
               Sinon
                    cp: premisse <- tete(R)
                    Tant que valeur(cp)=valeur(prop) ET next(cp) != INDEFINI faire
                         cp <- next(cp)
                    Fait
                    Si valeur(cp)=valeur(prop) alors
                        Si tete(R)=queue(R) alors
                            queue(R) <- INDEFINI
                            tete(R) <- INDEFINI
                            liberer(cp)
                            suppProp <- INDEFINI
                        Sinon
                            Si valeur(cp)=valeur(tete(R)) alors
                                  pred(next(cp)) <-INDEFINI
                                  tete(R) <-  next(cp)
                                  liberer(cp)
                                  suppProp <- tete(R)
                            Sinon
                                 Si valeur(cp) =valeur(queue(R)) alors
                                      next(pred(cp)) <- INDEFINI
                                      queue(R) <- pred(cp)
                                      liberer(nom(valeur(cp))
                                      liberer(cp)
                                      suppProp <-tete(R)  
                                 Sinon 
                                       next(pred(cp)) <- next(cp)
                                       pred(next(cp)) <- pred(cp)
                                       liberer(cp)
                                       suppProp <- tete(R)
                                 Fin si 
                            Fin si
                        Fin si
                    Fin si
               Fin si
           Fin si
    Fin

```

- Algorithme du sous programme accesTete qui accede à la tête d'une prémisse <br><br>
  ```Entête```: Fonction accesTete(R: regle): proposition <br>
  Algorithme Resultat:proposition <br>
             Données: regle <br>
  ```
    Fonction accesTete(R: regle) : proposition
        Debut
            Si R=INDEFINI alors
                valTete: proposition <- INDEFINI
            Sinon
                Si est premisseVide(R) alors
                    valTete <- INDEFINI
                Sinon
                    valTete <- valeur(tete(R))
                fin si
            fin si
        Fin
            
  ```
- Algorithme du sous programme accesConclusion qui accede à la conclusion d'une regle

    ```Entête```: Fonction accesConclusion(R: regle): proposition <br>
Algorithme Resultat:proposition <br>
Données: regle<br>
  ```
      Fonction accesConclusion(R: regle): proposition
        Debut
            Si R==INDEFINI alors
                valConcl: proposition <- INDEFINI
            Sinon
                Si conclusion(R)=INDEFINI alors
                    valConcl <- INDEFINI
                Sinon
                    valConcl <- conclusion(R)
                fin si
            fin si
        Fin
    
  ```
## Structure de données du type abstrait BC
  ```
    typedef struct bcElem{
           regle regleBC;
           struct bcElem *next;
    }bcElement;

    typedef bcElement* BC;

  ```
## Opérations type abstrait BC

- Algorithme du sous programme creerBase qui cree une base de connaissance Vide <br><br>
  ```Entête```: Fonction creerBase():BC <br>
  Algorithme  Resultat:BC <br>
              Données: <br>
  ```
       Fonction creerBase():BC
            Debut
                base: BC <- CreerElement()
                regleBc(base) <- INDEFINI
                next(base) <- INDEFINI
            Fin 
  
  ```
  - Algorithme du sous programme ajoutRegle qui ajoute une regle dans la base de connaissance, en queue

      ```Entête```: Fonction ajoutRegle(base:BC, R: regle):BC <br>
  Algorithme Resultat:BC <br>
  Données: regle,BC<br>
    ```
          Fonction ajoutRegle(base:BC, R: regle):BC
              Debut
                  newRegle:BC <- creerBase()
                  regleBc(newRegle) <- R
                  next(newRegle) <- INDEFINI
                  Si regleBC(base) = INDEFINI ET R != NULL alors
                      ajout: BC <- newRegle
                  Sinon
                      cmp:BC  <- base
                      Tant que next(next) != INDEFINI faire
                            cmp <- next(cmp)
                      Fait 
                      next(cmp) <- newel
                  fin si 
              Fin
  
    ```
- Algorithme du sous programme accesRegle qui accede a la regle en tete de la base de connaissance

    ```Entête```: Fonction accesRegle(base:BC):regle <br>
Algorithme Resultat:BC <br>
Données: BC <br>
  ```
      Fonction accesRegle(base:BC):regle
        Debut
            Si base != INDEFINI alors
                Si regleBc(base) =INDEFINI alors
                    R: regle <- INDEFINI
                Sinon
                    R <- regleBc(base)
                fin si
            Sinon
                R <- INDEFINI
            Fin si
        Fin  
  ```
## Structure de données de la base de fait

  ````
        typedef struct queue {
                proposition input;
                struct queue* next;
        }bfElement;
       
        typedef bfElement *baseFait;
  ````
- Algorithme du sous programme ajoutFile qui ajoute une element à la base de fait 

  ```Entête```: Fonction ajoutFile(Fait:baseFait, ajout:proposition):baseFait <br>
  Algorithme Resultat:baseFait <br>
  Données: baseFait,proposition <br>

````
    Fonction ajoutFile(Fait:baseFait,ajout: proposition):baseFait
        Debut
            newel: bfElement <- CreerElement()
            input(newel) <- ajout
            next(newel) <- INDEFINI
            Si Fait = Indefini alors
                finAjout:baseFait <- newel
            Sinon
                cmp: baseFait <- Fait
                Tant que next(cmp) != indefini faire
                    cmp <- next(cmp)
                Fait 
                next(cmp) <- newel
                finAjout <- cmp
            Fin si
        Fin
````
## Algorithme du moteur d'inférence :
```Entête```: Fonction inference(base:BC,fait:baseFait):baseFait <br>
Algorithme Resultat:baseFait (cmpFait)<br>
Données: BC,baseFait <br>

````
    Fonction inference(base:BC,fait:baseFait):baseFait
        Debut
             Si fait != INDEFINI alors
                    Si base != INDEFINI alors
                    
                        cmpFait: baseFait  <- fait
                        cmpBC: BC <- NULL
                        Tant que cmpFait != INDEFINI faire
                                cmpBc : BC <- accesRegle(BC)
                                Tant que cmpBc != NULL faire
                                    Si non est premisseVide(tete(regleBC(cmpBC))) alors
                                        SI pDansRegle(accesTete(regleBc(cmpBc)),cmpFait) == Vrai alors
                                            suppProp(accesRegle(cmpBc),cmpFait)
                                            Si est videPremisse( accesTete( regleBc(cmpBc) ) ) alors
                                                baseFait <- ajoutFile(baseFait,conclusion(accesTete( regleBc(cmpBc) ) ) ) 
                                            Fin si
                                        fin si
                                    fin si
                                    cmpBc <- next(cmpBc)
                                Fait
                                cmpFait <- next(cmpFait)
                        Fait    
                    Fin si
             Fin si
        Fin