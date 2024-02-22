# Rapport de séance 8

## Impression des stickers 

Au cours de la dernière séance, j'ai réaliser deux programmes python permettant de me créer un fichier avec les 52 QR codes représentant les cartes.
J'ai donc repris ce fichier que j'ai mit sur inkscape. J'ai ajuster la taille des QR codes pour que ceux-ci soient lisible par le lecteur de QR lorsqu'ils sont 
dans le réservoir à carte. Puis j'ai imprimer tout ces QR à l'aide de l'imprimante à stickers 

J'ai commencé à découper certain de ces QR codes et les coller sur les cartes mais j'ai vite réaliser que c'était une perte de temps car je pouvais réaliser cette 
tâche chez moi. Je suis donc aller aider mon binome.

## Fixation du lecteur de QR sur le support

Afin de fixer le lecteur de QR, j'ai utilisé un plaque de bois designée par Matveï qui ne convenait pas pour ce qui voulait faire. J'ai collé cette plaque à 
l'aide la colle à bois sur le coté du réservoir à cartes. Puis à l'extrémité de cette plaque, j'ai fixé le lecteur de QR une fois que je m'étais assuré que 
son placement était bon. Cela fonctionne parfaitement.

![image](https://github.com/MatveiMKS/Le-Dealos/blob/main/Images%20Diverses/lecteur_qr.jpg)

# Réglage du lecteur 
Un problème auquel je n'avais pas pensé est que le capteur étant placé tout le temps devant le QR celui-ci lit constament la valeur du QR. Ce qui surcharge la
mémoire de l'Arduino. J'ai donc modifier mon programme de manière à ce que un fois le QR est lu, si le précédent est le même alors celui-ci n'est pris compte.
