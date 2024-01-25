# Rapport de séance 5 du 24/01/2024

## Reconnaissance de cartes
Nous avons efin recu le lecteur de qr codes qui nous permettra de reconnaitre les cartes. Le lecteur avait un cable pour lequel on n'avais pas d'adaptateur en sortie, j'ai donc soudé des fils afin de pouvoir le brancher a la carte Arduino

<p align="middle">
    <img src="/Images Diverses/soudure lecteur.jpg" width="600" />
</p>

J'ai ensuite suivis un guide sur internet pour le branchement,
https://how2electronics.com/barcode-qr-code-reader-using-arduino-qr-scanner-module/
Une fois le branchement réalisé, une lumière bleue s'allume me montrant donc que le lecteur est bien alimenté et reconnu par la carte. Mais la lecture des qr codes ne marche pas, la première piste était le conflit avec les servos moteur car ils utilisent le même TIMER, mais même quand les servos étaient débranchés le problème persistait, j'ai ensuite essayé différent branchements pour voir s'ils posaient problème mais seul le branchement initial avait  l'air d'être bon car il était le seul ou la led s'allumait. Finalement sur la page amazon du lecteur un utilisateur a remarqué que l'alimentation du qr code était en 5V mais la transmission d'information était en 3.3V. Je n'ai pas eu le temps de vérifier cela et ce sera ce sur quoi je commencerai la prochaine séance.


<p align="middle">
    <img src="/Images Diverses/branchement lecteur.jpg" width="600" />
</p>

