---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
kernelspec:
  display_name: Python 3 (ipykernel)
  language: python
  name: python3
---

# Rapport de projet 2048

*Les paragraphes en italique comme celui-ci vous donnent des
indications sur le contenu attendu; ils sont à supprimer une fois
votre rapport rédigé.*

*Ce rapport pourra servir de support pour votre présentation orale.*

*Soyez objectifs et factuels! Vous ne serez pas évalué sur ce que vous
affirmez, mais sur la pertinence et la justesse de ce que vous
affirmez.*

+++

## Auteurs

- Boisramé, Auguste, auguste.boisrame@etu-upsaclay.fr, MI1
- Tang, Huynh Anh, huynh-anh.tang@etu-upsaclay.fr, MI1

+++

## Résumé du travail effectué

:::{admonition} Consignes

Pour chaque niveau du sujet, décrivez brièvement l'avancement de votre
projet.

Exemples de réponses : «non traitée», «réalisée, documentée, testée»,
«réalisée, sauf 2.3», «réalisée mais non testée», «réalisée sauf ...
pour lequel notre programme ne compile pas» ou «pour lequel les tests
de la fonction D ne passent pas».

Pour les questions «Aller plus loin» plus ouvertes, décrivez plus en
détail ce que vous avez choisi de réaliser. Précisez les difficultés
rencontrées, les choix d'implantation que vous avez fait, etc.

En plus du rapport, la documentation de chaque fonction dans le code
devra préciser son auteur et votre degré de confiance dans
l'implantation, ainsi que les éléments factuels motivant cette
confiance: présence de tests, bogues et limitations connus, etc.

- Niveau 0: Réalisé
- Niveau 1: Réalisé sauf 2. et 4.
- Niveau 2: Réalisé

:::

```{code-cell} ipython3
! clang g++ 2048.cpp -o 2048
```

Vous pourrez alors lancer le jeu depuis un terminal avec :
```
./2048
```

## Organisation du travail

:::{admonition} Consignes
Décrivez en quelques phrases comment vous vous êtes organisés pour
travailler sur le projet: nombre d'heures consacrées au projet,
répartition du travail dans le binôme, moyens mis en œuvre pour
collaborer, etc. Si vous avez bénéficié d'aide (en dehors de celle de
vos enseigants), précisez le.
:::

+++

Nous avons passé plus d'une vingtaine d'heures à réaliser le projet, on compte à peu près une dizaine d'heures à rendre le jeu fonctionnel et une autre dizaine à approfondir en détail le jeu. Pour ce, nous avons utilisé la platforme GitHub pour partager entre nous les différentes nouvelles version du code et de suivre le travail de l'autre.

+++

## Prise de recul

:::{admonition} Consignes
Décrivez en quelques phrases les difficultés rencontrées, ce que vous
avez appris à l'occasion du projet, le cas échéant comment vous vous y
prendriez si vous aviez à le refaire.
:::

+++

Rendre le jeu fonctionnel fut notre première difficulté, en effet, à première vue le jeu fonctionnait bien, seulement après plusieurs déplacements spécifiques, le jeu ne respectait pas les règles (déplacements en  trop, score excessif). Il a fallut lui faire passer de nombreux tests afin d'en déduire la source du problème.

+++

De plus, nous avons fait face à des soucis liés à l'utilisation de la fonction aléatoire, des soucis liés au déroulement de la partie (notamment lorsque la partie est terminée) mais encore lié à l'affichage.
De ce fait, nous avons beaucoup appris sur le tas en exécutant notre jeu et en déboguant par la suite.

+++

## Présentation du jeu

+++

Le 2048 est jeu de plateau 4 x 4 qui contient des puissances de 2. L'utilisateur peut déplacer ces puissances en utilisant les touches du clavier z,q,s ou d, et si deux tuiles adjacentes glissent dans la bonne direction, alors l'utilisateur gagne des points et elles se combinent ! À chaque déplacement, une nouvelle case apparaît. Le jeu se termine lorsque l'utilisateur obtient un 2048, ou que toutes les cases sont remplies et qu'il n'y a plus de déplacements possibles.

+++

## Documentation du jeu

+++

Pour une meilleure expérience, il est préférable de suivre les instructions suivantes afin de pouvoir jouer dans les meilleures conditions. A noter que les instructions utilisés dans un environnement linux (Debian/Ubuntu) et peuvent ne pas fonctionner dans Jupyter.

+++

Tout d'abord, compiler le fichier en utilisant la commande :

```{code-cell} ipython3
make
```

Supprime les fichiers .o

```{code-cell} ipython3
make clean
```

Exécute le jeu

```{code-cell} ipython3
./2048
```

Le jeu est lancé, nous demandons à l'utilisateur s'il souhaite prendre connaissance des règles [o/n]. Selon sa réponse, un affichage est produit, il est préférable de ne pas toucher à son clavier durant l'affichage pour éviter des bogues.

+++

La partie est lancée, l'utilisateur a le choix entre 4 déplacements ; droite, gauche, haut ou bas. Pour se déplacer, il utilisera l'une des touches "d", "q", "z" ou "s" suivi de la touche "entrée".

+++

La partie se termine lorsque l'utilisateur obtient un 2048, ou qu'il n'y a plus de déplacements possible, et que toutes les cases sont remplies.
