#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>






bool existMot(char mot[100], char idTable[100][2][100], int tailleIdTable ){
    int i=0;
    while(strcmp(mot,idTable[i][0])!=0 && i<tailleIdTable){
        i++;
    }
    if(i<tailleIdTable){
        return true;
    }else{
        return false;
    }
}


bool isKeyWord(char motLu[100]){
        //printf("isKeyWord : %s\n",motLu);
    if (!strcmp(motLu, "if") || !strcmp(motLu, "else") ||
        !strcmp(motLu, "while") || !strcmp(motLu, "do") ||
         !strcmp(motLu, "program") ||  !strcmp(motLu, "integer") ||
        !strcmp(motLu, "read") || !strcmp(motLu, "readln") ||
        !strcmp(motLu, "writeln") || !strcmp(motLu, "write") ||
        !strcmp(motLu, "char") || !strcmp(motLu, "var") ||
        !strcmp(motLu, "begin") || !strcmp(motLu, "end") || !strcmp(motLu, "then") ){
            return (false);
        }else{
            return (true);
        }
}

// Test if the character passed is number or alphabet
bool isAlpha(char ch){
    if (isalpha((char)ch) != 0){
        return false;
    }else{
        return true;
    }
}

bool isNumber(char mot[100]){
    int i = 0;
    while(i < strlen(mot) && isdigit(mot[i])!=0){
        i++;
    }
    if(i < strlen(mot)){
        return false;
    }else{
        return true;
    }
}

bool isOper(char motOper)
{
    if (motOper=='*' || motOper=='/' || motOper=='+' || motOper=='-'||
        motOper=='|' || motOper=='%' || motOper=='&' || motOper=='='||
        motOper=='>' || motOper=='<')
        return (true);
    return (false);
}

//return true if there's no similarity
bool isOperel(char mot[3])
{
    if (!strcmp(mot, "==") || !strcmp(mot, "<=")
        ||!strcmp(mot, ">=") || !strcmp(mot, "<>")
        || !strcmp(mot, "<")|| !strcmp(mot, ">")){
            return (false);
        }else{
            return (true);
        }
}

//return true if there's no similarity
bool isOpMul(char mot[3])
{
    if (!strcmp(mot, "*") || !strcmp(mot, "%") || !strcmp(mot, "/") || !strcmp(mot, "&&")){
            return (false);
        }else{
            return (true);
        }
}


//return true if there's no similarity
bool isOpAdd(char mot[3])
{
    if (!strcmp(mot, "+") || !strcmp(mot, "-") || !strcmp(mot, "||")){
            return (false);
        }else{
            return (true);
        }
}

bool isSeparator(char mot){
    if( (mot == ',') || (mot == ';') || (mot == '.') ){
        return true;
    }else{
        return false;
    }
}

bool isParenthese(char mot){
    if(mot == '(' || mot==')'){
        return true;
    }else{
        return false;
    }
}

///////////////////////////// PILE ****************************************
    typedef struct element {
        char donnee[100];
        /*La donnée que notre pile stockera*/
        struct element *precedent;
        /*Pointeur vers l'élément précédent de la pile*/
    } element;
    typedef element* Pile;
    Pile p=NULL;
    Pile production=NULL;

void Empiler(Pile *p, char valeur[100]) {
        /*On crée un nouvel élément*/
        element* nouveau = (element*)malloc(sizeof(element));

        /*Si le nouvel élément est crée*/
        if (nouveau != NULL) {
            /* On assigne la valeur au nouvel élément */
            strcpy(nouveau->donnee,valeur);
            /*On attache le nouvel élément au premier élément de la pile*/
            nouveau->precedent=*p;
            /*on pointe la pile vers le nouvel élément*/
            *p=nouveau;
        }
    }

    char* Depiler(Pile *p, char temp[100]) {
        if(*p!= NULL) {
            /*on memorise la valeur à dépiler*/
            strcpy(temp,(*p)->donnee);
            /*on memorise l'adresse de l'avant dernière élément de la pile*/
            element* ptemp = (*p)->precedent;
            /* On libère le premier élément */
            free(*p);
            /* On pointe la pile vers le deuxième élément */
            *p=ptemp; }
            /*on retourne la valeur dépilée*/
            //printf("temp = %s\n",temp);
        return temp;
    }

    void vider_pile(Pile *p, char temp[100]) {
        while (*p != NULL) {

                Depiler(p,temp);
                printf("%s|",temp);
        }
    }



////////////////// FILE ********************************************************************

struct node {
  char data[100];
  struct node *next;
};

struct node *start = NULL;
void insert_at_begin(char *);
void traverse();
void delete_from_begin();
void delete_from_end();
int count = 0;


void insert_at_begin(char x[100]) {
  struct node *t;

  t = (struct node*)malloc(sizeof(struct node));
  strcpy(t->data,x);
  count++;

  if (start == NULL) {
    start = t;
    start->next = NULL;
    return;
  }

  t->next = start;
  start = t;
}

void insert_at_end(char x[100]) {
  struct node *t, *temp;

  t = (struct node*)malloc(sizeof(struct node));
  strcpy(t->data,x);
  count++;

  if (start == NULL) {
    start = t;
    start->next = NULL;
    return;
  }

  temp = start;

  while (temp->next != NULL)
    temp = temp->next;

  temp->next = t;
  t->next   = NULL;
}


void traverse() {
  struct node *t;

  t = start;

  if (t == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  printf("There are %d elements in linked list.\n", count);

  while (t->next != NULL) {
    printf("%s\n", t->data);
    t = t->next;
  }
  printf("%s\n", t->data); // Print last node
}

void delete_from_begin(char ch[100]) {
  struct node *t;
  //char n;

  if (start == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  strcpy(ch,start->data);
  t = start->next;
  free(start);
  start = t;
  count--;
  //printf("%d deleted from the beginning successfully.\n", n);
}

void delete_from_end() {
  struct node *t, *u;
  char n[100];

  if (start == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  count--;

  if (start->next == NULL) {
    strcpy(n,start->data);
    free(start);
    start = NULL;
    printf("%s deleted from end successfully.\n", n);
    return;
  }

  t = start;

  while (t->next != NULL) {
    u = t;
    t = t->next;
  }

  strcpy(n,t->data);
  u->next = NULL;
  free(t);

  printf("%s deleted from end successfully.\n", n);
}


///////////////////////////////////// TABLE PREDECTIF ///////////////////////////////////////

bool isNotTerminal(char chPile[100],char text_ptr[20][29][100]){
    int i=0;
    while(strcmp(chPile,text_ptr[i][0]) != 0 && i<20){
        i++;
    }
    if(i<20){
        return true;
    }else{
        return false;
    }
}

void decomposition(char str[100], Pile *production, const char *fproduction){
    //int init_size = strlen(str);
    FILE *fprod = fopen(fproduction,"a");
    char delim[] = " ";
    char *ptr = strtok(str, delim);
    char temp[100],temp2[100] = "";
    //printf("-----------------------------------------------");
    while(ptr != NULL){
        Empiler(production,ptr);
        fprintf(fprod,ptr);
        fprintf(fprod," ");
        ptr = strtok(NULL, delim);

    }
    fprintf(fprod,"=>");
    while(*production!=NULL){
        Depiler(production,temp);
        Empiler(&p,temp);

    }
}

bool rechercheProduction(char text_ptr[20][29][100],char chPile[100],char chFile[100],Pile *production,Pile *p, const char *fproduction){
    int i=0;
    int j=0;
    char str[100];
    char temp[100];
    printf("--------------------------------------------\n");
    //printf("- rechercheProduction PILE :%s\n",chPile);
    printf("- rechercheProduction :[%s , %s]\n",chPile,chFile);
    while(strcmp(text_ptr[i][0],chPile)!=0 && i<20){
        i++;
    }

    while(strcmp(text_ptr[0][j],chFile)!=0 && j<29){
        j++;
    }


    if(strcmp(text_ptr[i][j],"")!=0){
        strcpy(str,text_ptr[i][j]);
        if(strcmp(str,"£")!=0){
            decomposition(str,production,fproduction);
        }else{
            Depiler(p,temp);
            Empiler(p,temp);
        }
        return true;
    }else{
        printf("Erreur de compilation : Production introuvable!\n");
        return false;
    }
}

bool isAccepted(Pile *p){
    //char chPile[100];
    struct node *t;
    t = start;

    if(*p==NULL && t==NULL){
        return true;
    }else{
        return false;
    }
}

void rechercheCorrespondance(char text_ptr[20][29][100],const char *fproduction){
    char chPile[100]= "";
    char chFile[100]= "";
    //char chPileTemporaire[100] = "";

    int i=0;
    Depiler(&p,chPile);
    delete_from_begin(chFile);
    do{
            i++;
        //printf("PILE : %s\n",chPile);
        //printf("FILE : %s\n",chFile);
        if(isNotTerminal(chPile,text_ptr) == false || strcmp(chPile,"$")==0){
            //printf("NOTTERMINAl!\n");
            if(strcmp(chPile,chFile) != 0){
                printf("Erreur syntaxique at token : %s\n",chFile);
                break;
            }else{
                Depiler(&p,chPile);
                delete_from_begin(chFile);
                printf("|********* %s Lu ***********|\n",chFile);
            }
        }else if(rechercheProduction(text_ptr,chPile,chFile,&production,&p,fproduction) == true){
            Depiler(&p,chPile);
            //printf("Le nouveau sommet de la pile : %s\n",chPile);
        }else{
            break;
        }
    }while(strcmp(chPile,"$")!=0);

    if(isAccepted(&p)==true){
        printf("\nCompilation terminated with status 0 : No syntax error!");
    }else{
        printf("\nCompilation terminated with status 1 : Syntax error found!");
    }


}



int main(){

    char curseur;
    char motLu[100] = "";
    char idTable[100][2][100];
    char motOper[3] = "";
    char separator[2] = "";
    char parenthese[2] = "";
    char affectation[2] = "";
    int tailleIdTable = 0;
//    char ch[100] = "";
    int i = 0;
    int j = 0;
    int compteur = 0;
    int k = 0;
    //char data[100];

    /////////////// TABLE D'ANALYSE /////////////////////
    int l,c;
    char text_ptr[20][29][100];
    FILE* fm = fopen("matrix.txt","w+");
    const char fproduction[] = "production.txt";
    FILE* fprod = fopen(fproduction,"a");
    // remplissage des non terminaux
    for (l = 0; l < 20; l++){
        for (c = 0; c < 29; c++){
            strcpy(text_ptr[l][c],"");
            //printf("%s | ",text_ptr[0][j]);
            }
    }

        strcpy(text_ptr[0][0],"ter/nnT");
        strcpy(text_ptr[1][0],"p"); strcpy(text_ptr[1][1],"program id ; dcl inst_compose .");
        strcpy(text_ptr[2][0],"dcl");strcpy(text_ptr[2][4],"dcli");strcpy(text_ptr[2][8],"dcli");
        strcpy(text_ptr[3][0],"dcli");strcpy(text_ptr[3][4],"var liste_id : type ; dcli");strcpy(text_ptr[3][8],"£");
        strcpy(text_ptr[4][0],"liste_id");strcpy(text_ptr[4][2],"id liste_idi");
        strcpy(text_ptr[5][0],"liste_idi");strcpy(text_ptr[5][7],", id liste_idi");strcpy(text_ptr[5][10],"£");
        strcpy(text_ptr[6][0],"type");strcpy(text_ptr[6][5],"integer");strcpy(text_ptr[6][6],"char");
        strcpy(text_ptr[7][0],"inst_compose");strcpy(text_ptr[7][8],"begin inst end");strcpy(text_ptr[7][27],"begin inst end");
        strcpy(text_ptr[8][0],"inst");strcpy(text_ptr[8][2],"liste_inst");strcpy(text_ptr[8][9],"£");strcpy(text_ptr[8][13],"liste_inst");strcpy(text_ptr[8][15],"liste_inst");strcpy(text_ptr[8][17],"liste_inst");strcpy(text_ptr[8][18],"liste_inst");strcpy(text_ptr[8][19],"liste_inst");strcpy(text_ptr[8][20],"liste_inst");
        strcpy(text_ptr[9][0],"liste_inst");strcpy(text_ptr[9][2],"i liste_insti");strcpy(text_ptr[9][12],"i liste_insti");strcpy(text_ptr[9][17],"i liste_insti");strcpy(text_ptr[9][18],"i liste_insti");strcpy(text_ptr[9][19],"i liste_insti");strcpy(text_ptr[9][17],"i liste_insti");strcpy(text_ptr[9][18],"i liste_insti");strcpy(text_ptr[9][19],"i liste_insti");strcpy(text_ptr[9][17],"i liste_insti");strcpy(text_ptr[9][18],"i liste_insti");strcpy(text_ptr[9][19],"i liste_insti");strcpy(text_ptr[9][20],"i liste_insti");
        strcpy(text_ptr[10][0],"liste_insti");strcpy(text_ptr[10][3],"; i liste_insti");strcpy(text_ptr[10][9],";i liste_insti");
        strcpy(text_ptr[11][0], "i");strcpy(text_ptr[11][2],"id : = exp_simple");strcpy(text_ptr[11][12],"if exp then i else i");strcpy(text_ptr[11][15],"while exp do I");strcpy(text_ptr[11][17],"read ( id )");strcpy(text_ptr[11][18],"readln ( id )");strcpy(text_ptr[11][19],"write ( id )");strcpy(text_ptr[11][20],"writeln ( id )");
        strcpy(text_ptr[12][0],"exp");strcpy(text_ptr[12][2],"exp_simple expi");strcpy(text_ptr[12][24],"exp_simple expi");strcpy(text_ptr[12][25],"exp_simple expi");
        strcpy(text_ptr[13][0],"expi");strcpy(text_ptr[13][13],"£");strcpy(text_ptr[13][16],"£");strcpy(text_ptr[13][21],"oprel exp-simple");
        strcpy(text_ptr[14][0],"exp_simple");strcpy(text_ptr[14][2],"terme exp_simplei");strcpy(text_ptr[14][24],"terme exp_simplei");strcpy(text_ptr[14][25],"terme exp_simplei");
        strcpy(text_ptr[15][0],"exp_simplei");strcpy(text_ptr[15][3],"£");strcpy(text_ptr[15][9],"£");strcpy(text_ptr[15][13],"£");strcpy(text_ptr[15][14],"£");strcpy(text_ptr[15][16],"£");strcpy(text_ptr[15][21],"£");strcpy(text_ptr[15][22],"opadd exp_simplei");
        strcpy(text_ptr[16][0],"terme");strcpy(text_ptr[16][2],"facteur termei");strcpy(text_ptr[16][24],"facteur termei");strcpy(text_ptr[16][25],"facteur termei");
        strcpy(text_ptr[17][0],"termei");strcpy(text_ptr[17][3],"£");strcpy(text_ptr[17][9],"£");strcpy(text_ptr[17][13],"£");strcpy(text_ptr[17][14],"£");strcpy(text_ptr[17][16],"£");strcpy(text_ptr[17][21],"£");strcpy(text_ptr[17][22],"£");strcpy(text_ptr[17][23],"opmul facteur termei");strcpy(text_ptr[17][26],"£");
        strcpy(text_ptr[18][0],"facteur");strcpy(text_ptr[18][2],"id");strcpy(text_ptr[18][24],"nb");strcpy(text_ptr[18][25],"( exp_simple )");

        //remplissage des terminaux

        strcpy(text_ptr[0][1],"program");
        strcpy(text_ptr[0][2],"id");
        strcpy(text_ptr[0][3],";");
        strcpy(text_ptr[0][4],"var");
        strcpy(text_ptr[0][5],"integer");
        strcpy(text_ptr[0][6],"char");
        strcpy(text_ptr[0][7],",");
        strcpy(text_ptr[0][8],"begin");
        strcpy(text_ptr[0][9],"end");
        strcpy(text_ptr[0][10] ,":");
        strcpy(text_ptr[0][11],"=");
        strcpy(text_ptr[0][12],"if");
        strcpy(text_ptr[0][13],"then");
        strcpy(text_ptr[0][14],"else");
        strcpy(text_ptr[0][15],"while");
        strcpy(text_ptr[0][16],"do");
        strcpy(text_ptr[0][17],"read");
        strcpy(text_ptr[0][18],"readln");
        strcpy(text_ptr[0][19],"write");
        strcpy(text_ptr[0][20],"writeln");
        strcpy(text_ptr[0][21],"oprel");
        strcpy(text_ptr[0][22] ,"opadd");
        strcpy(text_ptr[0][23],"opmul");
        strcpy(text_ptr[0][24] ,"nb");
        strcpy(text_ptr[0][25],"(");
        strcpy(text_ptr[0][26],")");
        strcpy(text_ptr[0][27],".");
        strcpy(text_ptr[0][28],"$");


    for (l = 0; l< 20; l++){
        for (c = 0; c < 29; c++){
            fprintf(fm,"%31s |",text_ptr[l][c]);
            //printf("%s | ",text_ptr[0][j]);
        }
        fprintf(fm,"\n");
        for(int k=0; k<956;k++){
            fprintf(fm,"-");
        }
        fprintf(fm,"\n");

    }

    /////////////////////////////////////////////////////////////

    FILE *fp = fopen("souceCode.txt","r");

	if (fp==NULL){
		printf("Erreur : Could Not Open File");
	}else{
		printf("ALL GOOD!\n\n");
	}

	while((curseur=fgetc(fp))!=EOF){
        if(curseur=='\n'){
            compteur++;
        }
        if(isalnum(curseur)!=0 && isspace(curseur)==0){
            motLu[i]=curseur;
            i++;
        }else{
            if(isKeyWord(motLu) == false){
                strcpy(idTable[tailleIdTable][0],motLu);
                strcpy(idTable[tailleIdTable][1],"KeyWord");
                //Empiler(&p,motLu);
                insert_at_end(motLu);
                tailleIdTable++;
                printf("KEYWORD: %s\n",motLu);
                i=0;
                memset(motLu,0,sizeof(motLu));

            }else if(isAlpha(motLu[0]) == false){
                strcpy(idTable[tailleIdTable][0],motLu);
                strcpy(idTable[tailleIdTable][1],"ID");
                //Empiler(&p,motLu);
                insert_at_end("id");
                tailleIdTable++;
                printf("MOT: %s \n",motLu);
                i=0;
                memset(motLu,0,sizeof(motLu));
            }else if(isAlpha(motLu[0]) == true && strlen(motLu) > 0){
                if(isNumber(motLu) == false){
                    printf("\nError at Ligne %d : Number must be numeric only.\n\n",compteur);
                    //break;
                }
                strcpy(idTable[tailleIdTable][0],motLu);
                strcpy(idTable[tailleIdTable][1],"Number");
                //Empiler(&p,motLu);
                insert_at_end("nb");
                tailleIdTable++;
                printf("NUMBER: %s \n",motLu);
                i=0;
                memset(motLu,0,sizeof(motLu));
            }


        }

        if((isOper(curseur) == true) && (j<2)){
            motOper[j] = curseur;
            j++;
            printf("MOT OPER : %s\n",motOper);
        }else if(j>0){
            if(isOperel(motOper) == false){
                strcpy(idTable[tailleIdTable][0],motOper);
                strcpy(idTable[tailleIdTable][1],"Operel");
                //Empiler(&p,motOper);
                insert_at_end("oprel");
                tailleIdTable++;
                j=0;
                memset(motOper,0,sizeof(motOper));
            }else if(isOpMul(motOper) == false){
                strcpy(idTable[tailleIdTable][0],motOper);
                strcpy(idTable[tailleIdTable][1],"OpMul");
                //Empiler(&p,motOper);
                insert_at_end("opmul");
                printf("opmul %s\n",motOper);
                tailleIdTable++;
                j=0;
                printf("OPMUL : %s\n",motOper);
                memset(motOper,0,sizeof(motOper));
            }else if(isOpAdd(motOper) == false){
                strcpy(idTable[tailleIdTable][0],motOper);
                strcpy(idTable[tailleIdTable][1],"OPADD");
                //Empiler(&p,motOper);

                insert_at_end("opadd");
                tailleIdTable++;
                j=0;
                printf("OPADD : %s\n",motOper);
                memset(motOper,0,sizeof(motOper));
            }else{
                j=0;
                memset(motOper,0,sizeof(motOper));
            }
        }

        if(isSeparator(curseur) == true){
            int i=0;
            separator[i]=curseur;
            printf("SEPARATOR : %s\n",separator);
            //Empiler(&p,separator);
            insert_at_end(separator);
            memset(motOper,0,sizeof(separator));
        }

        if(isParenthese(curseur)){
            int i=0;
            parenthese[i]=curseur;
            printf("PARENTHESE : %s\n",parenthese);
            insert_at_end(parenthese);
            memset(motOper,0,sizeof(parenthese));
        }

        if(curseur==':'){
            affectation[0]=curseur;
            insert_at_end(affectation);

            printf("AFFECTATION => %s\n",affectation);
            memset(affectation,0,sizeof(parenthese));
            k++;
        }else if((k>0) && (curseur == '=')){
            affectation[0]=curseur;
            insert_at_end(affectation);
            printf("AFFECTATION => %s\n",affectation);
            k=0;
            memset(affectation,0,sizeof(parenthese));
        }

    }
    insert_at_end("$");
    Empiler(&p,"$");
    Empiler(&p,"p");
    fprintf(fprod,"p=>");

    rechercheCorrespondance(text_ptr,fproduction);

    //char temp[100];
    //vider_pile(&p,temp);
    //traverse();

    //printf("NOMBRE DE LIGNE = %d",compteur);
    //delete_from_begin();
    //delete_from_end();
    //traverse();

    return 0;
}
