# Rapport de séance 4 du 10/01/2024

## Interaction homme machine
J'ai pu dans cette séance mettre en commun ce que Théophile et moi avions fait auparavant, le bouton 1 permet maintenant de distribuer une carte.

J'ai pu donc ensuite procéder aux premières parties de code. A l'aide d'une variable booléenne j'ai pu suivre l'état du jeu (en cours/finit) et utiliser cela pour créer la possibilité de choisir le nombre de joueur. Ensuite j'ai implémenté le fait de finir une partie, en effet si tout les joueurs dont stop (bouton 2) alors le croupier peux jouer.

Afin de simuler la distribution d'une carte je choisi au hasard dans une liste,l'une des 52 cartes d'un jeu de cartes classique et j'affiche celle si lorsque l'on appuie sur le bouton 1 pour tirer.

<p align="middle">
    <img src="/Images Diverses/choix nb joueur.jpg" width="600" />
</p>

Objectif pour la prochaine semaine: permettre au croupier de jouer, et si on a reçu le lecteur qr code implementer lecture des cartes .
