# Vernam

## Instruction de compilation

Pour compiler, un Makefile a été mis à dispostion, pour cela il suffit d'exécuter la commande `make` dans le terminal, et laisser le Makefile s'occuper du reste. Après cela nous allons avoir un fichier exécutable portant le nom de `vernam`.

## Instruction d'utilisation

Pour utiliser notre programme, il faut dans un premier temps compiler avec le Makefile, dans un deuxième temps il va falloir utiliser des commandes spécifique sur le terminal:
- Si nous voulons créer une clé de codage en fonction d'un fichier texte, il faut utiliser la commande `./vernam -k [Message.txt] [Fichier_Cle.txt]`
- Si nous voulons coder un fichier texte avec une clé de codeage définie, il faut utiliser la commande `./vernam -c [Message.txt] [Fichier_Cle.txt] [Message_C.txt]`
- Si nous voulons décoder un fichier texte avec une clé de codeage définie, il faut utiliser la commande `./vernam -d [Message_c.txt] [Fichier_Cle.txt] [Message_dc.txt]`
(Les noms des fichiers ne sont pas définitifs, vous pouvez les changer et mettre le nom que vous voulez)

**/!\ Il faut faire attention que la clé de codage soit au moins aussi longue que le message, sinon cela peut créer des problèmes lors de l'utilisation.**

## En cas de problème

Si il y a un problème lors de l'utilisation du programme, un message d'erreur dédié au problème va nous dire quel est l'origine du problème. Par exemple si nous voulons coder un message, mais que nous mettons pas la totalité des arguments demandés, un message d'erreur va nous dire qu'il manque un argument. Dès lors nous pourrons corriger notre erreur, et ainsi coder correctement notre message.

## Les limites

Quand nous générons notre clé, cette dernière est limitée par les 26 lettres de l'alphabet, majuscule et minuscule.