## Structure de données :

``` proposition: (valeur ^ nom) = ( Booleen ^ liste <caractère> ) <br>
premElement: ( proposition ^ next ^ pred ) = ( ( valeur ^ nom ) ^ premElement ^ premElement ) 
premisse: Liste<proposition>  , la prémisse d'une regle est représenté sous la forme d'une liste chainée <br>
regle: ( premisse  ^ conclusion ) = ( Liste <proposition> ^ proposistion ); <br>
BC: Liste<regle> <br>
baseFait: Liste<proposition> , représenter sous la forme d'une File, basée sur les entrée de l'utilisateur <br>
````
## Opérations type abstrait 

-Algorithme du sous programme creerRegle qui cree une regle vide:<br>

```Entête```: Fonction creerRegle():regle<br>
Algorithme Resultat: regle<br>
           Données :<br>
```
Fonction creerRegle():regle<br>
  début
      regle<-Allouer()
      premisse(regle)<-INDEFINI
      conclusion(regle<-INDEFINI
  fin
```

-Algorithme du sous programme ajoutPremisse qui ajoute une proposition à la premisse, en queue

```Entête```: Fonction ajoutPremisse(R:regle, ajout:proposition):regle
Algorithme Resultat: regle
           Données: regle,proposition
```
Fonction ajoutPremisse(R:regle,ajout:proposition):regle
  début
      newProp: premElement <- creerElement()
      proposition(newProp) <- ajout
      next(newProp) <- INDEFINI
      pred(newProp) <- INDEFINI
      Si est premisseVide(R) alors 
          premisse(R) <- newProp
      Sinon
          cp:premElement <- tete(premisse(R))
          Tant que non est vide(cp) faire 
              cp <- next(cp)
          fait
          next(cp) <- newProp
          pred(newProp) <- cp
      fin si
  fin
```
  -Algorithme du sous programme creerConclusion qui crée la conclusion d'une regle  | Deux implementation differentes : soit met en paramètre la proposition associé à la conclusion -> crée OU  on crée la proposition dans la fonction -> recup du nom et de la valeur de la proposition | 

// Algo 1

```Entête```: Fonction creeConclusion(R:regle, titre:liste<caractère,e: Booleen):regle
Algorithme Resultat: regle
           Données: regle,proposition
```
Fonction creerConclusion (R:regle, titre:liste<caractère,e: Booleen):regle
  debut
        Si conclusion(R)= INDEFINI ET ajout != INDEFINI alors
            concl:proposition <- AllouerMemoire()
            nom(concl)<-titre
            valeur(concl)<-e
            conclusion(R)<-concl
        fin si
  fin
```

- Algorithme du sous programme pDansRegle qui verifie recursivement si une proposition est dans la premisse d'une regle

```Entête```: Fonction pDansRegle(R:regle,prop:proposition):Booleen
Algorithme Resultat: booleen
           Données: regle, proposition
```
Fonction pDansRegle(tete:premElement,prop:proposition):booleen
  debut
      Si tete=INDEFINI alors
          pDansRegle(tete,prop)<- FAUX
      Sinon
          si valeur(prop)=valeur(proposition(tete)) ET nom(prop)=nom(proposition(tete)) alors
              pDansRegle(tete,prop) <- VRAI
          Sinon
              pDansRegle(tete,prop)<-pDansRegle(next(tete),prop)
          fin si
      fin si
  fin
  ```
