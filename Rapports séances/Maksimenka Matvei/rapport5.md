# Rapport de séance 5 du 24/01/2024

## Reconnaissance de cartes
Nous avons efin recu le lecteur de qr codes qui nous permettra de reconnaitre les cartes. Le lecteur avait un cable pour lequel on n'avais pas d'adaptateur en sortie, j'ai donc soudé des fils afin de pouvoir le brancher a la carte Arduino
<p align="middle">
    <img src="/Images Diverses/soudure lecteur.jpg" width="600" />
</p>
J'ai ensuite suivis un guide sur internet pour le branchement,
https://how2electronics.com/barcode-qr-code-reader-using-arduino-qr-scanner-module/
Une fois le branchement réalisé, une lumiere bleue s'allumant me montrant donc que le lecteur est bien alimenté et reconnu par la carte. Mais la lecture des qr codes ne marche pas, la premiere piste etait le conflit avec les servos moteur car ils utilisent le meme TIMER, mais meme quand les servos etaient debranches le probleme percistait, j'ai ensuite essayé different branchements pour voir s'iols posaient probleme mais seul le branchement initial avait  l'air d'etre bon car il etait le seul ou la led s'allumait. Finalement sur la page amazon du lecteur un utilisateur a commenté que l'allimentation du qr code etait en 5V mais la transmission d'information etait en 3.3V. Je n'ai pas eu le temps de verifier cela et ce sera ce sur quoi je commencerait la prochaine seance.


