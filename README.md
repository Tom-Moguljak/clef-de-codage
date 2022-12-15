<h1> Instruction de compilation </h1>

Pour compiler, un Makefile a été mis à dispostion, pour cela il suffit d'exécuter la commande "make" dans le terminal, et laisser le Makefile s'occuper du reste. Après cela nous allons avoir un fichier exécutable portant le nom de "vernam".

<h1>Instruction d'utilisation</h1>

Pour utiliser notre programme, il faut dans un premier temps compiler avec le Makefile, dans un deuxième temps il va falloir utiliser des commandes spécifique sur le terminal: <br>
-Si nous voulons créer une clé de codage en fonction d'un fichier texte, il faut utiliser la commande "./vernam -k [Message.txt] [Fichier_Cle.txt] <br>
-Si nous voulons coder un fichier texte avec une clé de codeage définie, il faut utiliser la commande "./vernam -c [Message.txt] [Fichier_Cle.txt] [Message_C.txt] <br>
-Si nous voulons décoder un fichier texte avec une clé de codeage définie, il faut utiliser la commande "./vernam -d [Message_c.txt] [Fichier_Cle.txt] [Message_dc.txt] <br>
(Les noms des fichiers ne sont pas définitifs, vous pouvez les changer et mettre le nom que vous voulez)