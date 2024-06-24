#include "../../inc/fahaleovantena.h"

char    **all_questions(void)
{
    char **all = malloc(sizeof(char *) * 17);
    all[0] = strdup("Iza no filohan'ny repoblikan'i Madagasikara ?\n1. Hery RAJAONARIMAMPIANINA\n2. Marc RAVALOMANANA\n3. Andry RAJOELINA\n");
    all[1] = strdup("Iza no renivohitr'i Madagasikara ?\n1. Fianarantsoa\n2. Antananarivo\n3. Analamanga\n");
    all[2] = strdup("Inona no lohatenin'ny hiram-pirenena Malagasy ?\n1. Zanahary oh ! Tahio ny tanindrazanay\n2. Ry tanindrazanay malala oh !\n3. Nosindrazanay\n");
    all[3] = strdup("Inona no lokon'ny sainam-pirenena Malagasy?\n1. Maitso-fotsy-mena\n2. Fotsy-Mena-Maitso\n3. Mena-fotsy-maitso\n");
    all[4] = strdup("Oviana no nambara ampahibe-maso ny fahaleovan-tenan'i Madagasikara ?\n1. 18 Oktobra 1958\n2. 26 Jona 1960\n3. 13 Mai 1959\n");
    all[5] = strdup("Inona ny foto-tsakafon'ny Malagasy?\n1-katsaka\n2-vary\n3-mangahazo\n");
    all[6] = strdup("Inona no fanalavana ny V.V.S?\n1-Vy vato Safelika\n2-Vy Vato Sakelika\n3-Vy Vary Sakelika\n");
    all[7] = strdup("Iza no nahita an'i Madagasikara voalohany ?\n1. Marco Polo\n2. Christophe Colomb\n3. Diego Diaz\n");
    all[8] = strdup("Iza no filohan'ny Repoblika voalohany teto Madagasikara ?\n1. Didier RATSIRAKA\n2. Zafy ALBERT\n3. Philbert TSIRANANA\n");
    all[9] = strdup("Iza no mpanjaka farany teto Madagasikara ?\n1. Rindra II\n2. Rasoherina\n3. Ranavalona III\n");
    all[10] = strdup("Misy foko firy eto Madagasikara ?\n1. 22\n2. 17\n3. 18\n");
    all[11] = strdup("Inona ny vokatra fanondranana mampalaza an'i Madagasikara?\n1-vanilla\n2-jirofo\n3-vary\n");
    all[12] = strdup("Taiza no natao ny fanambarana ny fahaleovantena an'i madagasikara?\n1-lalan'ny Fahaleovantena\n2-Kianjan'i Magamasina\n3-Kianjan'ny 13 May\n");
    all[13] = strdup("Firy ny faritra eto Madagasikara?\n1-23\n2-22\n3-21\n");
    all[14] = strdup("Fanalavana ny M.D.R.M?\n1-Mouvement Democratique pour la Rénovation Malgache\n2-Mouvement Democratique pour la Révolution Malgache\n3-Mouvement Democratique pour la République Malgache\n");
    all[15] = strdup("tohizo ity ohabolana ity : 'Aleo very tsikalakalam-bola ...\n1- toy izay very tsikalakalam-pihavanana.'\n2- toy izay very tsikalakalam-pifaliana.'\n3- toy izay very tsikalakalam-pinamanana.'\n");
    return (all);
}

bool varavarana(void)
{
    static int index;
    int i = 2;
    char **all = all_questions();
    int result[16] = {'3', '2', '2', '2', '2', '2', '2', '3', '3', '3', '3', '1', '2', '1', '1', '1'};
    while (i > 0)
    {
        printf("%s", all[index]);
        int ch = getchar();
        getchar();
        if (ch == result[index]) {
            printf("Felicitations ! Vous avez ouvert une porte vers l'independance .\n");
            index++;
            return (true);
        } else {
            printf("Non nefaaaa !\n");
            index++;
        }
        i--;
        if (i == 0)
            printf("Ty tena daika tssssss !\n");
    }
   
    return (false);
}
