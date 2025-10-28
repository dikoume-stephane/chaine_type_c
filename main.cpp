#include <iostream>

// Prototypes des fonctions
size_t LongueurChaine(const char* chaine);
void CopierChaine(char* destination, const char* source);
void ConcatenerChaines(char* destination, const char* source);
char* TrouverCaractere(const char* chaine, char caractere);
size_t CompterOccurrences(const char* chaine, char caractere);
void CopierMemoire(void* destination, const void* source, size_t taille);
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille);
void ExtraireSousChaine(char* destination, const char* source, 
                       size_t debut, size_t longueur);
size_t DiviserChaine(const char* chaine, char separateur, 
                    char resultat[][100], size_t max_resultats);
int ComparerChaines(const char* chaine1, const char* chaine2);
void ConvertirMinuscules(char* chaine);
bool EstChaineNumerique(const char* chaine);

int main() {
    std::cout << "=== TEST DES FONCTIONS DE MANIPULATION DE CHAINES STYLE C ===" << std::endl;
    std::cout << "Compilé avec C++ et CLang++" << std::endl << std::endl;
    
    // Test 1: Longueur de chaîne
    char message[] = "Bonjour le monde";
    std::cout << "1. Longueur de '" << message << "': " << LongueurChaine(message) << std::endl;
    
    // Test 2: Copie de chaîne
    char copie[50];
    CopierChaine(copie, message);
    std::cout << "2. Copie: '" << copie << "'" << std::endl;
    
    // Test 3: Concaténation
    char salutation[100] = "Hello ";
    ConcatenerChaines(salutation, "World!");
    std::cout << "3. Concaténation: '" << salutation << "'" << std::endl;
    
    // Test 4: Recherche de caractère
    char* position = TrouverCaractere(message, 'j');
    if (position != nullptr) {
        std::cout << "4. Caractère 'j' trouvé à la position: " << (position - message) << std::endl;
    } else {
        std::cout << "4. Caractère 'j' non trouvé" << std::endl;
    }
    
    // Test 5: Comptage d'occurrences
    std::cout << "5. Occurrences de 'o' dans '" << message << "': " 
              << CompterOccurrences(message, 'o') << std::endl;
    
    // Test 6: Extraction de sous-chaîne
    char sous_chaine[20];
    ExtraireSousChaine(sous_chaine, message, 3, 5);
    std::cout << "6. Sous-chaîne (pos 3, longueur 5): '" << sous_chaine << "'" << std::endl;
    
    // Test 7: Division de chaîne
    char phrase[] = "pomme,orange,banane,kiwi";
    char fruits[10][100];
    size_t nb_fruits = DiviserChaine(phrase, ',', fruits, 10);
    
    std::cout << "7. Division de '" << phrase << "':" << std::endl;
    for (size_t i = 0; i < nb_fruits; i++) {
        std::cout << "   [" << i << "] " << fruits[i] << std::endl;
    }
    
    // Test 8: Fonctions mémoire
    char zone1[10] = "ABCDEFGHI";
    char zone2[10];
    CopierMemoire(zone2, zone1, 5);
    zone2[5] = '\0';
    std::cout << "8. Copie mémoire (5 octets): '" << zone2 << "'" << std::endl;
    
    char zone3[10];
    InitialiserMemoire(zone3, 'X', 5);
    zone3[5] = '\0';
    std::cout << "9. Initialisation mémoire: '" << zone3 << "'" << std::endl;
    
    // Test 10: Comparaison de chaînes
    char chaineA[] = "apple";
    char chaineB[] = "banana";
    int resultat_comparaison = ComparerChaines(chaineA, chaineB);
    std::cout << "10. Comparaison '" << chaineA << "' vs '" << chaineB << "': " 
              << resultat_comparaison << std::endl;
    
    // Test 11: Conversion minuscules
    char mixte[] = "Hello World!";
    std::cout << "11. Avant conversion: '" << mixte << "'" << std::endl;
    ConvertirMinuscules(mixte);
    std::cout << "    Après conversion: '" << mixte << "'" << std::endl;
    
    // Test 12: Vérification numérique
    char numerique[] = "12345";
    char non_numerique[] = "12a45";
    std::cout << "12. '" << numerique << "' est numérique: " 
              << (EstChaineNumerique(numerique) ? "OUI" : "NON") << std::endl;
    std::cout << "    '" << non_numerique << "' est numérique: " 
              << (EstChaineNumerique(non_numerique) ? "OUI" : "NON") << std::endl;
    
    return 0;
}
size_t LongueurChaine(const char* chaine) { // voir readme
    // Sauvegarde du pointeur initial vers le début de la chaîne
    // On stocke cette adresse pour pouvoir calculer la différence plus tard
    const char* debut = chaine;
    
    // Boucle qui parcourt la chaîne caractère par caractère
    // *chaine déréférence le pointeur pour obtenir le caractère pointé
    // La condition s'arrête quand on rencontre le caractère nul '\0' (fin de chaîne)
    while (*chaine != '\0') {
        // Incrémentation du pointeur : on le fait avancer d'une position en mémoire
        // chaine++ fait passer au caractère suivant dans la chaîne
        // En C++, l'arithmétique des pointeurs tient compte de la taille du type
        // donc chaine++ avance exactement de sizeof(char) = 1 octet
        chaine++;
    }
    
    // Calcul de la longueur par différence d'adresses mémoire
    // chaine pointe maintenant sur le '\0' à la fin de la chaîne
    // debut pointe toujours sur le premier caractère
    // La soustraction donne le nombre d'éléments (char) entre les deux adresses
    // C'est exactement la longueur de la chaîne sans compter le '\0'

    // Exemple concret avec la chaîne "Hello" :
    // Mémoire : [H][e][l][l][o][\0]
    //            ↑           ↑
    //          debut       chaine (après boucle)
          
    // Distance : chaine - debut = 5 (longueur de "Hello")
    return chaine - debut;
}
void CopierChaine(char* destination, const char* source) { // voir readme
    while(*source != '\0') //bloucle permettant parcourir  la chaine de cractere originale tant que le caractere \0 n'est pas atteint (fin de chaine)
    {
        *destination = *source;//on copie le contenu de la souce a chaque indice et on le met dans la destination
        source++;   //on incremente les deux chaine pour pouvoir evoluer dessus  
        destination++; 
    }
    *destination='\0';// des que la copie est terminee on ajoute a la fin de la copie de chaine le \0
}
void ConcatenerChaines(char* destination, const char* source) { // voir readme
    while(*destination != '\0')// on parcour la chaine de destination jusqu'a arriver a ça fin (au \0)
    {
        destination++;
    } 
    while(*source!='\0')//on parcour la chaine a additionner et on ne s'arrete que lorsqu'elle est fini 
    {
        *destination=*source;// a partir du drenier carctere de la chaine de destination , on ajoute un a un les caracters de la chaine a incrementer
        source++;    // on incremente les deux chaine pour pouvoir evoluer dessus au meme moment
        destination++;
    }
    *destination='\0'; // une fois l'addition terminée on ajoute le \0 a la fin de la nouvelle chaine 
}
char*  TrouverCaractere(const char* chaine, char caractere) { // voir readme
   while(*chaine != '\0' && *chaine != caractere)// on parcour la chaine sible et on ne s'arrete que si on arrive a la fin 
   {                                             //ou si on recontre le caractere recherche
        chaine++;
   }
   if(*chaine == caractere)// a la sortie de la boucle , si le caractere actuel de la chaine sible est celui recherche 
    {                       // on retourne le pionteur etant verouillé sur elle 
        return const_cast<char*>(chaine);// pour retourner ce pointeur , une conversion est necessaire car le type de retour de la fonction est pointeur 
            // mais chaine est un pointeur constant . la convertion avec un const_cast est donc utilisée pour enlever les propriete constante du pointeur chaine lors du retour
    } else return nullptr;// si la valeur actuele de la chaine n' est pas celle recherchée , on retourne un pionteur null
}
 size_t CompterOccurrences(const char* chaine, char caractere) { // voir readme
    size_t occ =0; // on defini une variable qui va compter les occurence du caractere recherché
    while(*chaine != '\0')//on parcour la chaine cible et on ne s'arrete que lorsqu'elle est fini 
    {
        if(*chaine == caractere) occ++;// a chaque caractere on verifi su il corespond au caractere recherché 
        chaine++; // si oui , on ajoute une occurrence en plus en incrementant occ et on incremente la chaine pour pouvoir evoluer dessus
    }
    return occ; // a la fin on retourne le nombre d'occurence 
}
 void CopierMemoire(void* destination, const void* source, size_t taille) { // voir readme
   size_t compteur =0; // on definis un compteur pour nous assurer que la taille ne sera pas depassée
   unsigned char* destination_cvt = (unsigned char*)destination; // onconverti les pionteurs en unsigned char* pour faciliter la gestion 
   const unsigned char* source_cvt = ( const unsigned char*)source;// et la manipulation de la memoire 
   while(compteur < taille) // on parcour la chaine source tantque le compteur est inferieur à la taille 
   {
    *destination_cvt = *source_cvt;// pour chaque caractere on le  copie vers l'adresse memoire de  la destination  
    destination_cvt++;
    source_cvt++; //  on incremente les deux chaine pour pouvoir evoluer dessus au meme moment
    compteur++; // et on incremente le compteur 
   }
}
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille) { // voir readme
    size_t compteur =0;  // on definis un compteur pour nous assurer que la taille ne sera pas depassée
    unsigned char* zone_cvt = (unsigned char*)zone; // on convertie le pointeur vers la zone sible en unsigned char* pour une meilleure manipulation de la memoire
    while(compteur < taille) // on parcour la zone memoire sible tantque le compteur est inferieur à la taille 
   {
    *zone_cvt = valeur; // pour chaque emplacement memoire , on affecte la valeur voulue 
    zone_cvt++; // on imcremente le pointeur pour evoluer dans la zone memoire 
    compteur++; // on incremente le compteur à chaque initialization
   }
}
 void ExtraireSousChaine(char* destination, const char* source, 
                       size_t debut, size_t longueur) { // voir readme
    size_t taille =0; // on definit une variable taille pour recupere la taille de la chaine 
    const char*copi = source; // on definit un pointeur constant initializer à source pour copier la valeur de source
                                // cela permet de verifier la taille de soure sans l'alterer
    while(*copi != '\0') // on trouve la taille de copi donc de source 
    {
        taille++;
        copi++;
    }
    if(debut<0 || debut>taille)return; // on verifie si debut est valide (se trouve dans les limittes de source)
    size_t compteur=0;   // on definis un compteur pour nous assurer que la longueur ne sera pas depassée
    while(compteur < longueur && source[debut+compteur] !='\0')// on parcour la chaine tantque le compteur est inferieur à la longueur
    {                                                          // et le caractere actuel est diferent \0 (fin de chaine) 
        destination[compteur] = source[debut+compteur];//on copie a partir de l'indice [debut] vers destination [compteur]
        compteur++; // on incremente le compteur 
    }
    destination[compteur] ='\0'; // on ajoute le \0 à la fin de la chaine extraite 
}
size_t DiviserChaine(const char* chaine, char separateur, 
                    char resultat[][100], size_t max_resultats) { // voir readme
    size_t compteur =0, index =0; // on initialise le compteur de sous-chaine et le compteur decaractere par chaine à 0
    while(compteur < max_resultats && *chaine != '\0') // on parcour la longue chaine tantque le compteur de sous-chaine est inferieur au monbre max de sous-chaine 
    {                                   // et le caractere actuel est different de\0(fin de chaine)
        if(*chaine == separateur || *chaine == '\0')// si le caractere actuel est egale au separateur recherché ou que la chaine est fini 
        {
            resultat[compteur][index] = '\0';// on affecte \0 (fin de chaine) dans l'espace situer a l'indice des deux compteur respectivement (fin de la sous-chaine)
            compteur++; // et on incremente le compteur de sous-chaine
            index =0; // puis on reinitialise le compteur de caractere par sous-chaine
            if(*(chaine+1) == separateur) chaine++; // et on verifi si le caractere suivant n'est pas le separateur . si il l'est , on l'ignore en passant au suivant
        }
        else // sinon 
        {
            resultat[compteur][index] = *chaine; // on range le caractere dans une case tableau (en ordre)
            index++; // et on incremente le compteur de caractere par sous-chaine
        }
        chaine++; // et on fait evoluer la chaine
    }
    resultat[compteur][index] = '\0'; // à la fin on affecte à la fin de la derniere sous-chaine le \0 (fin de chaine)
    return compteur+1; // on retourne le nombre de sous-chaine + 1 car le programme sort de la boucle des que le \0 est trouvé sur la chaine principale
                       // il n'incremente donc pas ce compteur pour une derniere fois
    return 0;
}
int ComparerChaines(const char* chaine1, const char* chaine2) { // voir readme
    
    while(*chaine1 != '\0' || *chaine2 != '\0') // on parcour simultanement les deux chaine et on n'arrete que si elles sont toute les deux fini 
    {                                       // pour chaque caractere des chaine ,
        if(*chaine1 < *chaine2) return *chaine1-*chaine2;// on compare les valeurs et on retourne la difference en focntion du plus grand 
        if(*chaine1 > *chaine2) return *chaine1-*chaine2;// ou du plus petit
        if(*chaine1 == '\0' && *chaine2 == '\0') return 0; // si les caracteres actuel sont \0 , cela signifi que les deux chaine se terminent simultanement et on retourne 0
        if(*chaine1 == '\0')// si la chaine1 se termine avant la 2 alors on retourne la difference de longueur entre les deux
        {                   // pour ce faire 
            const char* temoin = chaine2; // on definit une temoin et on l'initialize avec la valeur actuelle de la chaine2
            while(*chaine2 != '\0' ) chaine2++;// puis on parcour la chaine2 j'uqu'a la fin et 
            return chaine2 - temoin ;// et on retourne la difference entre les adresse memoire 
        }
        if(*chaine2 == '\0') // idem pour la chaine2
        {
            const char* temoin = chaine1; //
            while(*chaine1 != '\0' ) chaine1++; //
            return chaine1 - temoin ; //
        }
        chaine1++;
        chaine2++; // on fait evoluer les des chaine simultanement
    }
    return 0;
}
void ConvertirMinuscules(char* chaine) { // voir readme
    while(*chaine != '\0') //on parcour la chaine cible et on ne s'arrete que lorsqu'elle est fini 
    {
        if(*chaine <= 'Z' && *chaine >= 'A') // pendant le parcour , on verifi pour chaque caractere si il fait partir de l'alphabet 
        {                                    //et si il est en majiscule
             *chaine = *chaine + 32; // si oui , on le remplace par son equivalent en miniscule en ajoutant 32 à sa valeur ASCII
        }
        else
        {
            chaine++;// sinon on évolu sur la chaine
        }
        
    }
}
bool EstChaineNumerique(const char* chaine) { // voir readme
    if(*chaine == '-') chaine++;// si le premier caractere est le - alors on incremente la chaine et on l'ingnore
    while(*chaine != '\0') //on parcour la chaine cible et on ne s'arrete que lorsqu'elle est fini 
    {
        if(*chaine > '9' || *chaine < '0') return 0;// pour chaque caractere , on verifie si il situé entre 0 et 9 sinon on retourne 0
        chaine++; // et on évolu sur la chaine 
    }
    return 1;// à la fin si rien n'a été fait alors c'est que tous les caracteres sont bon donc on retourne 1
}
