# TP Comp 

## Compilation

### Release

Compilation en mode *release* (utilisé pour les tests unitaires)

```{r, engine='bash', count_lines}
$ make
```

### Debug

Compilation en mode *debug* permettant d'afficher la trace des appels
aux différentes méthodes et aux différents états dans lequel l'automate est passé.

```{r, engine='bash', count_lines}
$ make debug
```

## Tests unitaires

Le dossier **Tests** contient les différents tests unitaires, chaque fichier ayant un nom de la forme
test(.*) est appelé, chaque fichier doit être formé d'au moins 3 lignes :

- 1ère ligne : expression à évalué
- 2ème ligne : résultat de l'expression
- 3ème ligne : ligne vide au minimum

Les autres lignes ne sont pas utilisés

Le script *tests.sh* peut être lancé sans arguments, il va alors executer les tests pour chaque fichier du dossier *Tests*
qui suit la règle décrite ci dessus. Il peut également être lancé avec pour arguments le nom du fichier de test que l'on souhaite
executer voir plusieurs nom de fichiers.

### Exemple d'utilisation

```{r, engine='bash', count_lines}
$ ./tests.sh
```

Ou

```{r, engine='bash', count_lines}
$ ./tests.sh ./Tests/test1
```

Ou bien encore

```{r, engine='bash', count_lines}
$ ./tests.sh test1 
# ici test1 va être cherché dans le dossier courant puis dans le dossier Tests
```

## Participants

FOLLEAS Jacques SCHROTER Quentin VAILLANT Milly