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
size_t LongueurChaine(const char* chaine) {
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
void CopierChaine(char* destination, const char* source) {
    while(*source != '\0')
    {
        *destination = *source;
        source++;
        destination++; 
    }
    *destination='\0';
}
void ConcatenerChaines(char* destination, const char* source) {
    while(*destination != '\0')
    {
        destination++;
    } 
    while(*source!='\0')
    {
        *destination=*source;
        source++;
        destination++;
    }
    *destination='\0';
}
char*  TrouverCaractere(const char* chaine, char caractere) {
   while(*chaine != '\0' && *chaine != caractere)
   {
        chaine++;
   }
   if(*chaine == caractere)
    {
        return const_cast<char*>(chaine);
    } else return nullptr;
}
 size_t CompterOccurrences(const char* chaine, char caractere) {
    size_t occ =0;
    while(*chaine != '\0')
    {
        if(*chaine == caractere) occ++;
        chaine++;
    }
    return occ;
}
 void CopierMemoire(void* destination, const void* source, size_t taille) {
   size_t conteur =0;
   unsigned char* destination_cvt = (unsigned char*)destination;
   const unsigned char* source_cvt = ( const unsigned char*)source;
   while(conteur < taille)
   {
    *destination_cvt = *source_cvt;
    destination_cvt++;
    source_cvt++;
    conteur++;
   }
}
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille) {
    size_t compteur =0;
    unsigned char* zone_cvt = (unsigned char*)zone;
    while(compteur < taille)
   {
    *zone_cvt = valeur;
    zone_cvt++;
    compteur++;
   }
}
 void ExtraireSousChaine(char* destination, const char* source, 
                       size_t debut, size_t longueur) {
    size_t taille =0;
    const char*copi = source;
    while(*copi != '\0')
    {
        taille++;
        copi++;
    }
    if(debut<0 || debut>taille)return;
    size_t compteur=0;
    while(compteur < longueur && source[debut+compteur] !='\0')
    {
        destination[compteur] = source[debut+compteur];
        compteur++;
    }
    destination[compteur] ='\0';
}
size_t DiviserChaine(const char* chaine, char separateur, 
                    char resultat[][100], size_t max_resultats) {
    size_t compteur =0, index =0;
    while(compteur < max_resultats && *chaine != '\0')
    {
        if(*chaine == separateur || *chaine == '\0')
        {
            resultat[compteur][index] = '\0';
            compteur++;
            index =0;
            if(*(chaine+1) == separateur) chaine++;
        }
        else
        {
            resultat[compteur][index] = *chaine;
            index++;
        }
        chaine++;
    }
    resultat[compteur][index] = '\0';
    return compteur+1;
    return 0;
}
int ComparerChaines(const char* chaine1, const char* chaine2) {
    
    while(*chaine1 != '\0' || *chaine2 != '\0')
    {
        if(*chaine1 < *chaine2) return *chaine1-*chaine2;
        if(*chaine1 > *chaine2) return *chaine1-*chaine2;
        if(*chaine1 == '\0' && *chaine2 == '\0') return 0;
        if(*chaine1 == '\0')
        {
            const char* temoin = chaine2;
            while(*chaine2 != '\0' ) chaine2++;
            return *chaine2 - *temoin ;
        }
        if(*chaine2 == '\0')
        {
            const char* temoin = chaine1;
            while(*chaine1 != '\0' ) chaine1++;
            return *chaine1 - *temoin ;
        }
        chaine1++;
        chaine2++;
    }
    return 0;
}
void ConvertirMinuscules(char* chaine) {
    while(*chaine != '\0')
    {
        if(*chaine <= 'Z' && *chaine >= 'A')
        {
             *chaine = *chaine + 32;
        }
        else
        {
            chaine++;
        }
        
    }
}
bool EstChaineNumerique(const char* chaine) {
    if(*chaine == '-') chaine++;
    while(*chaine != '\0')
    {
        if(*chaine > '9' || *chaine < '0') return 0;
        chaine++;
    }
    return 1;
}