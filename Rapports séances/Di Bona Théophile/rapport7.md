# Rapport de séance 7

## Configuration du lecteur code barre

En ce début de séance, nous avons reçu un nouveau lecteur de code barre et QR code car le précédent était diysfonctionnel.

Je me suis donc occupé de sa configuration. Tout d'abord, j'ai vérifier son bon fonctionnement en le connectant à mon ordinateur à l'aide d'un port USB.
Une fois assuré de celui-ci, j'ai soudé les fils du port UART à d'autres fils afin de pouvoir connecter le capteur à ma carte arduino.
J'ai donc effectué les branchements et créer un code à l'aide de la bibliothèque arduino SofwareSerial. Après quelques essais, je n'arrivais et toujours pas à 
récupérer ne serait-ce qu'une seule donnée de la part du capteur. J'ai donc été faire un tour sur les forums afin de voir les corrections que je devais apporter 
à mon code. Je me suis finalement rendu compte que, je n'avais pas bien initialisé mon capteur. En effet, pour que celui-ci accepte d'envoyer des données 
il fallait lui faire scanner une série de QR code. Une fois cela effectué, je récupérais bien les données de code barre grâce au capteur.

## Création de QR-Code

La tache suivante était de créer 52 QR-codes différents pour chacunes des cartes du jeu. Bien évidemment, je n'avais ni le temps ni l'envie de les créer tous 
un par un à l'aide d'un générateur de QR code en ligne. J'ai donc opté pour un programme python me permettant de tous les créer en un clic. J'ai réaliser celui-ci 
à l'aide des libraires qrcode et pillow. J'ai donc pu générer un fichier remplis de ces 54 QR codes. Il fallait maitenant les réunir sur un document word afin 
de pouvoir tous les imprimer en une fois et que ceux-ci aient la bonne dimension pour les coller sur les cartes. Bien évidemment, plutôt que de le faire
manuellement, j'ai crée un second algorithme python toujours à l'aide de libraire Pillow. Le document était ainsi réaliser plus qu'à l'imprimer, découper et coller
ces QR-codes sur les cartes. Cependant, cette fois je ne pourrais pas faire d'algorithme python......
