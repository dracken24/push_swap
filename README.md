# push_swap

Consignes générales
-------------------
• Ce projet ne sera corrigé que par des humains. Vous êtes  donc libres d’organiser
  et de nommer vos fichiers comme vous le désirez, en respectant néanmoins les
  contraintes listées ici.

• Le premier exécutable doit s’appeller checker et le   second push_swap.

• Vous devez rendre un Makefile. Ce Makefile doit compiler  le projet, et doit
  contenir les règles habituelles. Il ne doit recompiler et relinker les programmes
  qu’en cas de nécessité.

• Si vous êtes malin et que vous utilisez votre       biliothèque  libft pour ce projet, vous
  devez en copier les sources et le Makefile associé dans un dossier nommé libft
  qui devra être à la racine de votre dépôt de rendu. Votre Makefile devra compiler
  la bibliothèque, en appelant son Makefile, puis compiler votre projet.

• Les variables globales sont interdites.

• Votre projet doit être en C et à la Norme. La norminette fait foi.

• Vous devez gérer les erreurs de façon raisonnée. En aucun cas vos programmes ne
  doivent quitter de façon inattendue (segmentation fault, bus error, double free,
  etc...).

• Vos programmes ne doivent pas avoir de fuites mémoire.

• Vous devez rendre, à la racine de votre dépôt de rendu, un fichier auteur contenant
  votre login suivi d’un ’\n’ :
    $>cat -e auteur
    xlogin$

• Dans le cadre de votre partie obligatoire, vous avez le droit d’utiliser les fonctions
  suivantes de la libc :
    ◦ write
    ◦ read
    ◦ malloc
    ◦ free
    ◦ exit

_______________________________________________________________________________________

Partie obligatoire
------------------
Règles du jeu
• Le jeu est constitué de 2 piles nommées a et b.

• Au départ :
◦ a contient un nombre arbitraire d’entiers positifs ou négatifs, sans doublons.
◦ b est vide

• Le but du jeu est de trier a dans l’ordre croissant.

• Pour ce faire, on ne dispose que des opérations suivantes :
  <!-- sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun. -->

  <!-- sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun. -->

  <!-- ss : sa et sb en même temps. -->

  <!-- pa : push a - prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.

  pb : push b - prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide. -->

  <!-- ra : rotate a - décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier. -->

  <!-- rb : rotate b - décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier. -->

  <!-- rr : ra et rb en même temps. -->

  <!-- rra : reverse rotate a - décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier. -->

  <!-- rrb : reverse rotate b - décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier. -->
  
  <!-- rrr : rra et rrb en même temps. -->


Le programme “checker”
----------------------
• Vous devez écrire un programme nommé checker qui prend en paramètre la pile
  a sous la forme d’une liste d’entiers. Le premier paramètre est au sommet de la
  pile (attention donc à l’ordre).

• Checker doit ensuite attendre de lire des instructions sur l’entrée standard, chaque
  instruction suivie par un ’\n’. Une fois toutes les instructions lues, le checker va
  exécuter ces instructions sur la pile d’entiers passée en paramètres.

• Si après exécution la pile a est bien triée et la pile b est vide, alors checker doit
  afficher "OK" suivi par un ’\n’ sur la sortie standard. Dans tous les autres cas,
  checker doit afficher "KO" suivi par un ’\n’ sur la sortie standard.

• En cas d’erreur, vous devez afficher Error suivi d’un ’\n’ sur la sortie d’erreur.
  Par exemple si certains paramètres ne sont pas des nombres, certains paramètres
  ne tiennent pas dans un int, s’il y a des doublons, ou bien sûr si une instruction
  n’existe pas ou est mal formatée.


Le programme “push_swap”
------------------------
• Vous devez écrire un programme nommé push_swap qui prend en paramètre la
  pile a sous la forme d’une liste d’entiers. Le premier paramètre est au sommet
  de la pile (attention donc à l’ordre). Si aucun paramètre n’est passé, push_swap
  termine immédiatement et n’affiche rien.

• Le programme doit afficher le programme composé de la plus petite suite d’ins-
  tructions possible qui permet de trier la pile a, le plus petit nombre étant au
  sommet.

• Les instructions doivent être affichées separées par un ’\n’ et rien d’autre.

• Le but est de trier les entiers avec le moins d’opérations possibles. En soutenance,
  nous comparerons le nombre d’instructions que votre programme a calculé avec un
  nombre d’opération maximum toléré. Si votre programme affiche un programme
  trop long, ou si bien sûr ce programme ne trie pas la liste, vous n’aurez pas de
  points pour ce test.

• En cas d’erreur, vous devez afficher Error suivi d’un ’\n’ sur la sortie d’erreur.
  Par exemple si certains paramètres ne sont pas des nombres, certains paramètres
  ne tiennent pas dans un int, ou encore s’il y a des doublons.

**************************************************************************************************************

CORRETION:
----------
Partie obligatoire:
Rappel : N'oubliez pas que pendant toute la durée de la soutenance, aucune erreur de segmentation, ni
autre résiliation inattendue, prématurée, incontrôlée ou inattendue du
programme, sinon la note finale est 0. Utilisez le drapeau approprié. Cette règle est
actif tout au long de la défense.

Fichier auteur:
---------------
Vérifiez que le fichier auteur est à la racine du référentiel
et formaté comme expliqué dans le sujet. Sinon la défense est
terminé et la note finale est 0.

Fuites de mémoire:
------------------
Tout au long de la soutenance, faites attention à la quantité de mémoire
utilisé par push_swap (en utilisant la commande top par exemple) afin
pour détecter toute anomalie et s'assurer que la mémoire allouée est
correctement libéré. S'il y a une fuite de mémoire (ou plus), la dernière
la note est 0.

Programme de vérification - Gestion des erreurs
-----------------------------------------------
Dans cette section, nous évaluerons la gestion des erreurs du vérificateur.
Si au moins un échoue, aucun point ne sera attribué pour ce
section. Passez au suivant.

- Exécutez le vérificateur avec des paramètres non numériques. Le programme
doit afficher "Erreur".
- Exécutez le vérificateur avec un paramètre numérique en double. Le
programme doit afficher "Erreur".
- Exécutez le vérificateur avec uniquement des paramètres numériques dont un
supérieur à MAXINT. Le programme doit afficher "Erreur".
- Exécutez le vérificateur sans aucun paramètre. Le programme doit
ne rien afficher et renvoyer l'invite.
- Exécutez le vérificateur avec des paramètres valides et écrivez une action qui
n'existe pas pendant la phase d'instruction. Le programme doit
afficher "Erreur".
- Exécutez le vérificateur avec des paramètres valides et écrivez une action avec

un ou plusieurs espaces avant et/ou après l'action pendant
la phase d'instruction. Le programme doit afficher "Erreur".
Programme de vérification - Faux tests
Dans cette section, nous évaluerons la capacité du vérificateur à gérer
une liste d'instructions qui ne trie pas la liste. Exécutez le
suite à 2 essais. Si au moins un échoue, aucun point ne sera attribué
pour cette rubrique. Passez au suivant.
N'oubliez pas d'appuyer sur CTRL+D pour arrêter la lecture pendant le
phase d'instruction.

- Exécutez checker avec la commande suivante "$>./checker 0 9 1 8 2
7 3 6 4 5" puis écrivez la liste d'actions valides suivante
"[sa, pb, rrr]". Checker devrait afficher "KO".
- Exécutez le vérificateur avec une liste valide comme paramètre de votre choix, puis

écrire une liste d'instructions valide qui n'ordonne pas les entiers.
Checker devrait afficher "KO". Vous devrez vérifier spécifiquement
que le programme n'a pas été développé uniquement pour répondre correctement
sur le test inclus dans cette échelle. Vous devriez répéter ceci
testez quelques fois avec plusieurs permutations avant de
le valider.

Programme de vérification - Bons tests
--------------------------------------
Dans cette section, nous évaluerons la capacité du vérificateur à gérer
une liste d'instructions qui trient la liste. Exécutez le
suite à 2 essais. Si au moins un échoue, aucun point ne sera
être attribué pour cette section. Passez au suivant.
N'oubliez pas d'appuyer sur CTRL+D pour arrêter la lecture pendant le
phase d'instruction.

- Exécutez checker avec la commande suivante "$>./checker 0 1 2"
puis appuyez sur CTRL+D sans écrire aucune instruction. Le
programme doit afficher "OK".
- Exécutez checker avec la commande suivante "$>./checker 0 9 1
8 2" puis écrivez la liste d'actions valides suivante
"[pb, ra, pb, ra, sa, ra, pa, pa]". Le programme devrait
afficher "OK".
- Exécutez le vérificateur avec une liste valide comme paramètre de votre choix, puis

écrire une liste d'instructions valide qui ordonne les nombres entiers.
Le vérificateur doit afficher "OK". Vous devrez vérifier spécifiquement
que le programme n'a pas été développé uniquement pour répondre correctement
sur le test inclus dans cette échelle. Vous devriez répéter ceci
testez quelques fois avec plusieurs permutations avant de
le valider.

Push_swap - Test d'identité
---------------------------
Dans cette section, nous évaluerons le comportement de push_swap lorsque
donné une liste, qui a déjà été triée. Exécutez le
après 3 essais. Si au moins un échoue, aucun point ne sera
décerné pour cette section. Passez au suivant.

- Exécutez la commande suivante "$>./push_swap 42". Le programme
ne doit rien afficher (instruction 0).
- Exécutez la commande suivante "$>./push_swap 0 1 2 3". Le
le programme ne doit rien afficher (instruction 0).
- Exécutez la commande suivante "$>./push_swap 0 1 2 3 4 5 6
7 8 9". Le programme ne doit rien afficher (instruction 0).

Push_swap - Version simplifiée
Si le test suivant échoue, aucun point ne sera attribué
pour cette rubrique. Passez au suivant.

- Exécutez "$>ARG="2 1 0"; ./push_swap $ARG | ./checker $ARG".
Vérifiez que le programme de vérification affiche "OK" et que
la taille de la liste des instructions de push_swap est
2 OU 3. Sinon, le test échoue.
Une autre version simplifiée
Effectuez les 2 tests suivants. Si au moins un échoue,
aucun point ne sera attribué pour cette section. Déménager à
le prochain.

- Exécutez "$>ARG="1 5 2 4 3" ; ./push_swap $ARG | ./checker
$ARG". Vérifiez que le programme de vérification affiche "OK"
et que la taille de la liste des instructions de
push_swap n'est pas supérieur à 12. Félicitations si la taille de
la liste des instructions est 8.

- Exécutez "$>ARG="<5 valeurs aléatoires>" ; ./push_swap $ARG |
./checker $ARG" et remplacez l'espace réservé par 5 au hasard
valeurs valides. Vérifiez que le programme de vérification affiche
"OK" et que la taille de la liste des instructions
de push_swap n'est pas supérieur à 12. Sinon, ce test
échoue. Vous devrez vérifier spécifiquement que le programme
n'a pas été développé pour seulement répondre correctement au test
compris dans cette échelle. Vous devriez refaire ce test
quelques fois avec plusieurs permutations devant vous
le valider.

Push_swap - Version intermédiaire
---------------------------------
Si le test suivant échoue, aucun point ne sera attribué
pour cette rubrique. Passez au suivant.

- Exécutez "$>ARG="<100 valeurs aléatoires>" ; ./push_swap $ARG |
./checker $ARG" et remplacez l'espace réservé par 100 au hasard
valeurs valides. Vérifiez que le programme de vérification affiche
"OK" puis donnez une note en fonction de la taille de la liste
de consignes :
- Moins de 700 : 5
- Moins de 900 : 4
- Moins de 1100 : 3
- Moins de 1300 : 2
- Moins de 1500 : 1

Vous devrez vérifier spécifiquement que
le programme n'a pas été développé uniquement pour répondre correctement
sur le test inclus dans cette échelle. Tu devrais répéter
ce test quelques fois avec plusieurs permutations
avant de le valider.
Notez-le de 0 (échec) à 5 (excellent)
Push_swap - Version avancée
Si le test suivant échoue, aucun point ne sera attribué
pour cette rubrique. Passez au suivant.

- Exécutez "$>ARG="<500 valeurs aléatoires>" ; ./push_swap $ARG |
./checker $ARG" et remplacez l'espace réservé par 500
valeurs valides aléatoires (l'une n'est pas appelée John/Jane Script
pour rien) Vérifiez que le programme de vérification affiche "OK"
puis donner une note en fonction de la taille de la liste
de consignes :
- Moins de 5500 : 5
- Moins de 7000 : 4
- Moins de 8500 : 3
- Moins de 10000 : 2
- Moins de 11500 : 1

Sinon, ce test échoue.
Vous devrez vérifier spécifiquement que le programme
n'a pas été développé pour répondre correctement uniquement sur
test inclus dans cette échelle. Vous devriez répéter ceci
tester quelques fois avec plusieurs permutations
avant de le valider.
Notez-le de 0 (échec) à 5 (excellent)

BONUS
--------
Rappel : N'oubliez pas que pendant toute la durée de la soutenance, aucune erreur de segmentation, ni
autre résiliation inattendue, prématurée, incontrôlée ou inattendue du
programme, sinon la note finale est 0. Utilisez le drapeau approprié. Cette règle est
actif tout au long de la défense. Nous examinerons vos bonus si et
seulement si votre partie obligatoire est EXCELLENTE. Cela signifie que vous devez
remplissez la partie obligatoire, du début à la fin, et votre erreur
la gestion doit être sans faille, même en cas de torsion ou de mauvaise utilisation. Alors
si la partie obligatoire n'a pas marqué tous les points lors de cette soutenance des bonus
sera totalement IGNOREE.

Quelques bonus
--------------
Pour mériter d'être considéré comme tel, un bonus doit être :
- Utile (vous jugerez par vous-même), inutile d'exagérer.
- Bon travail
- Opérationnel, il ne peut générer aucune erreur.
ex : -v pour afficher les piles pendant le traitement, -c pour afficher
avec des couleurs etc...
Notez-le de 0 (échec) à 5 (excellent)