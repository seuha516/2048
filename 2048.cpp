#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <memory.h>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int cursor=1;  //메인화면 커서의 위치
int selcur=1;  //모드 선택 화면 커서의 위치
int rankcur=1; //랭킹 커서 위치
int board4[4][4]={0,}; //4x4 보드
int board5[5][5]={0,}; //5x5 보드
float timeleft=600;
int gaming=0;          //게임중이면 1
char ranklist[200][100]={0,};
int scorelist[200][100]={0,};
int scorenum[200]={0,};
int rankorder[200]={0,};
int realorder[200]={0,};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int rankupload(int gamemode, int clear, int move, float timeleft, int maxcombo, int score);
void mainscreen(int whereiscursor);
int howto();
int ranking4();
int ranking5();
void rankingscreen(int whereiscursor);
int ranking();
void selectscreen(int whereiscursor);
int selectmode();
int howmanyzero(int a,int b,int c,int d);
int howmanyzero2(int a,int b,int c,int d, int e);
int movecheck(int a,int b,int c,int d);
int moving2(int *a1,int *a2,int *a3,int *a4, int *a5);
int ingame4();
int ingame5();
void printnum(int num);
void drawboard4(int score, int combo, int move, int thisturnscore);
void drawboard5(int score, int combo, int move, int thisturnscore);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    mainscreen(1);
    FILE *fptest; fptest=fopen("ranking4.txt","r");
    if(fptest==NULL){
        FILE *fp1; fp1=fopen("ranking4.txt","wt");
        fprintf(fp1,"    Test1        CLEAR      1853     47.56      15       291\n    Test2        CLEAR      3218      3.48      12       351\n    Test3         LOSE      2876     230.48      6       182\n    전승하       CLEAR      4818     135.48     32       230\n");
        fclose(fp1);

        FILE *fp2; fp2=fopen("ranking5.txt","wt");
        fprintf(fp2,"    Test1        CLEAR      2335     147.56     15       291\n    Test2        CLEAR      4218      3.48      12       351\n    Test3         LOSE      2335     218.48      6       182\n    전승하       CLEAR      9818     135.48     32       230\n");
        fclose(fp2);

        FILE *fp3; fp3=fopen("score4.txt","wt");
        fprintf(fp3,"1853\n3218\n2876\n4818\n");
        fclose(fp3);

        FILE *fp4; fp4=fopen("score5.txt","wt");
        fprintf(fp4,"2335\n4218\n2335\n9818\n");
        fclose(fp4);
    }
    fclose(fptest);

    while(1){
        char input;
        input=getch();

        if((input=='s'||input=='S')&&cursor!=4){
            mainscreen(++cursor);
        }else if((input=='W'||input=='w')&&cursor!=1){
            mainscreen(--cursor);
        }else if(input==13){
            if(cursor==1){
                selcur=1;
                selectmode();
            }else if(cursor==2){
                howto();
            }else if(cursor==3){
                rankcur=1;
                ranking();
            }else if(cursor==4){
                return 0;
            }
        }
    }
    return 0;
}
void mainscreen(int whereiscursor){

    system("cls");

    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("\n============================================\n");
    printf("||                 ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
    printf("2 0 4 8");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("                ||\n");
    printf("============================================\n\n\n\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);

    if(whereiscursor==1){
        printf("            ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
        printf("▶");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("    ");
        printf("GAME START\n\n");
        printf("                  How To Play\n\n");
        printf("                  Ranking\n\n");
        printf("                  Exit\n\n");
    }else if(whereiscursor==2){
        printf("                  GAME START\n\n");
        printf("            ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
        printf("▶");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("    ");
        printf("How To Play\n\n");
        printf("                  Ranking\n\n");
        printf("                  Exit\n\n");
    }else if(whereiscursor==3){
        printf("                  GAME START\n\n");
        printf("                  How To Play\n\n");
        printf("            ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
        printf("▶");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("    ");
        printf("Ranking\n\n");
        printf("                  Exit\n\n");
    }else if(whereiscursor==4){
        printf("                  GAME START\n\n");
        printf("                  How To Play\n\n");
        printf("                  Ranking\n\n");
        printf("            ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
        printf("▶");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("    ");
        printf("Exit\n\n");
    }

    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
    printf("\n           (use W, A, S, D, Enter)\n     작동이 안될 시 한영키를 누르십시오.\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("\n    ====================================\n");

    printf("============================================\n\n\n\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
}
int selectmode(){
    selectscreen(1);
    while(1){
	    char input;
	    input=getch();
	
	    if((input=='s'||input=='S')&&selcur!=3){
	         selectscreen(++selcur);
	    }else if((input=='W'||input=='w')&&selcur!=1){
	         selectscreen(--selcur);
	    }else if(input==13){
	        if(selcur==1){
	            ingame4();
	            break;
	        }else if(selcur==2){
	            ingame5();
	            break;
	        }else if(selcur==3){
	            break;
	        }
	    }
    }
    cursor=1;
    mainscreen(1);
    return 0;
}
void selectscreen(int whereiscursor){
    system("cls");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("\n============================================\n");
    printf("||                 ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
    printf("2 0 4 8");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("                ||\n");
    printf("============================================\n\n\n\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    if(whereiscursor==1){
        printf("            ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
        printf("▶");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("    ");
        printf("4 X 4\n\n");
        printf("\n                  5 X 5\n");
        printf("\n\n\n\n              Back To Main Menu\n\n");
    }else if(whereiscursor==2){
        printf("                  4 X 4\n\n");
        printf("\n            ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
        printf("▶");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("    ");
        printf("5 X 5\n");
        printf("\n\n\n\n              Back To Main Menu\n\n");
    }else if(whereiscursor==3){
        printf("                  4 X 4\n\n");
        printf("\n                  5 X 5\n");
        printf("\n\n\n\n        ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
        printf("▶");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("    ");
        printf("Back To Main Menu\n\n");
    }

    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
    printf("\n\n           (use W, A, S, D, Enter)\n\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("\n    ====================================\n");
    printf("============================================\n\n\n\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
}
int howto(){
    system("cls");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
    printf("\n\n< 2 0 4 8 >\n\n\n\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    printf("2048을 만들자!\n\n\n");
    printf("판 위에 있는 숫자들을 W, A, S, D 키를 사용해 한쪽으로 모두 밀어낼 수 있습니다.\n\n");
    printf("이때, 두 개의 같은 숫자가 만나면 합쳐집니다. 예를 들어, 4 블록 두개는 8로 합쳐집니다.\n\n");
    printf("이 과정을 반복하여 2048 블록을 만드십시오.\n\n");
    printf("10분의 시간이 주어집니다.\n\n");
    printf("더이상 움직일 수 없는 상태가 되거나 시간초과 시 패배합니다.\n\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
    printf("\n\n         Press Esc to EXIT\n\n\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    while(1){
        char input;
        input=getch();
        if(input==27){
            break;
        }
    }
    cursor=1;
    mainscreen(1);
    return 0;
}
int ranking(){
    rankingscreen(1);
    while(1){
        char input;
        input=getch();

        if((input=='s'||input=='S')&&rankcur!=3){
             rankingscreen(++rankcur);
        }else if((input=='W'||input=='w')&&rankcur!=1){
             rankingscreen(--rankcur);
        }else if(input==13){
            if(rankcur==1){
                ranking4();
            }else if(rankcur==2){
                ranking5();
            }else if(rankcur==3){
                break;
            }
        }
    }
    cursor=1;
    mainscreen(1);
    return 0;
}
void rankingscreen(int whereiscursor){
    system("cls");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("\n=================================================\n");
    printf("||                 ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
    printf("2048 Ranking");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("                ||\n");
    printf("=================================================\n\n\n\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    if(whereiscursor==1){
        printf("            ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
        printf("▶");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("    ");
        printf("4 X 4\n\n");
        printf("                  5 X 5\n\n\n");
        printf("                  Back To Main Menu\n\n");
    }else if(whereiscursor==2){
        printf("                  4 X 4\n\n");
        printf("            ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
        printf("▶");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("    ");
        printf("5 X 5\n\n\n");
        printf("                  Back To Main Menu\n\n");
    }
    else if(whereiscursor==3){
        printf("                  4 X 4\n\n");
        printf("                  5 X 5\n\n\n");
        printf("            ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
        printf("▶");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("    ");
        printf("Back To Main Menu\n\n");
    }
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
    printf("\n\n               (use W, A, S, D, Enter)\n\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("\n   ============================================\n");
    printf("==================================================\n\n\n\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
}
int rankupload(int gamemode, int clear, int move, float timeleft, int maxcombo, int score){
    system("cls");
    char name[10];
    printf("\n\n\n  이름을 입력해주세요 (3글자 한글 권장) : "); scanf("%s",name);
    system("cls");
    printf("\n\n  이름 : %s\n",name);
    printf("\n\n  점수 : %d\n",score);
    printf("\n\n  남은 시간 : %0.2f\n",timeleft);
    printf("\n\n  최대콤보 : %d\n",maxcombo);
    printf("\n\n  이동횟수 : %d\n",move);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
    printf("\n\n\n  Press Esc to EXIT\n  메인화면에서 조작이 불가능할 시 한영키를 확인하세요.\n\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    FILE *fp;
    if(gamemode==4){fp=fopen("ranking4.txt","a+");}
    else if(gamemode==5){fp=fopen("ranking5.txt","a+");}
    if(fp==NULL){return 0;}
    fprintf(fp,"    ");
    fprintf(fp,name);fprintf(fp,"       ");
    if(clear==-1){fprintf(fp," LOSE");}else if(clear==1){fprintf(fp,"CLEAR");}
    fprintf(fp,"      %d",score);
    fprintf(fp,"     %0.2f",timeleft);
    fprintf(fp,"      %d",maxcombo);
    fprintf(fp,"       %d\n",move);
    fclose(fp);
    FILE *fpscore;
    if(gamemode==4){fpscore=fopen("score4.txt","a+");}
    else if(gamemode==5){fpscore=fopen("score5.txt","a+");}
    if(fpscore==NULL){return 0;}
    fprintf(fpscore,"%d\n",score);
    fclose(fpscore);
    while(1){
        char input;
        input=getch();
        if(input==27){
            break;
        }
    }
    return 0;
}
int ranking4(){
    system("cls");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("\n=================================================\n");
    printf("||                 ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11);
    printf("4 X 4 Ranking");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("               ||\n");
    printf("=================================================\n");
    for(int i=0;i<200;i++){
        for(int j=0;j<100;j++){
            ranklist[i][j]=0;
            scorelist[i][j]=0;
        }
	}
    for(int i=0;i<200;i++){
        rankorder[i]=0;
        scorenum[i]=0;
        realorder[i]=0;
    }
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 15);
    printf("=================================================================\n");
    printf("||  이름       클리어여부   점수   남은 시간 최대콤보 이동횟수 ||\n");
    printf("=================================================================\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    FILE *fp;
    fp = fopen("ranking4.txt", "r");
    int i=0;
	while(!feof(fp)){
		fgets(ranklist[i],100,fp);
        i++;
	}
    fclose(fp);
    FILE *fpscore;
    fpscore=fopen("score4.txt","r");
    int k=0;
    while(!feof(fpscore)){
		fgets((char*)scorelist[k],100,fpscore);
		scorenum[k]=atoi((char*)scorelist[k]);
        k++;
	}
    for(int i=0;ranklist[i][0]!=0;i++){
        for(int j=0;ranklist[j][0]!=0;j++){
            if(scorenum[i]<scorenum[j]){
                rankorder[i]++;
            }else if (scorenum[i]==scorenum[j]){
                if(i<j){
                    rankorder[j]++;
                }
            }
        }
    }
    for(int i=0;ranklist[i][0]!=0;i++){
        realorder[rankorder[i]]=i;
    }
    for(int i=0;ranklist[i][0]!=0;i++){
        printf("%s",ranklist[realorder[i]]);
    }
    fclose(fpscore);
	printf("=================================================================\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
    printf("Press Esc to EXIT\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    while(1){
        char input;
        input=getch();
        if(input==27){
            break;
        }
    }
    rankcur=1;
    rankingscreen(1);
    return 0;
}
int ranking5(){
    system("cls");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("\n=================================================\n");
    printf("||                 ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11);
    printf("5 X 5 Ranking");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("               ||\n");
    printf("=================================================\n");
    for(int i=0;i<200;i++){
        for(int j=0;j<100;j++){
            ranklist[i][j]=0;
            scorelist[i][j]=0;
        }
    }
    for(int i=0;i<200;i++){
        rankorder[i]=0;
        scorenum[i]=0;
        realorder[i]=0;
    }
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 15);
    printf("=================================================================\n");
    printf("||  이름       클리어여부   점수   남은 시간 최대콤보 이동횟수 ||\n");
    printf("=================================================================\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    FILE *fp;
    fp = fopen("ranking5.txt", "r");
    int i=0;
	while(!feof(fp)){
		fgets(ranklist[i],100,fp);
        i++;
	}
    fclose(fp);
    FILE *fpscore;
    fpscore=fopen("score5.txt","r");
    int k=0;
    while(!feof(fpscore)){
		fgets((char*)scorelist[k],100,fpscore);
		scorenum[k]=atoi((char*)scorelist[k]);
        k++;
	}
    for(int i=0;ranklist[i][0]!=0;i++){
        for(int j=0;ranklist[j][0]!=0;j++){
            if(scorenum[i]<scorenum[j]){
                rankorder[i]++;
            }else if (scorenum[i]==scorenum[j]){
                if(i<j){
                    rankorder[j]++;
                }
            }
        }
    }
    for(int i=0;ranklist[i][0]!=0;i++){
        realorder[rankorder[i]]=i;
    }
    for(int i=0;ranklist[i][0]!=0;i++){
        printf("%s",ranklist[realorder[i]]);
    }
    fclose(fpscore);
	printf("=================================================================\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
    printf("Press Esc to EXIT\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    while(1){
        char input;
        input=getch();
        if(input==27){
            break;
        }
    }
    rankcur=1;
    rankingscreen(1);
    return 0;
}
void printnum(int num){
    if(num==0){
        printf("       ");
    }else if(num==2){
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
    printf("   2   ");
    }else if(num==4){
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    printf("   4   ");
    }else if(num==8){
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 15);
    printf("   8   ");
    }else if(num==16){
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
    printf("  1 6  ");
    }else if(num==32){
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
    printf("  3 2  ");
    }else if(num==64){
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
    printf("  6 4  ");
    }else if(num==128){
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 9);
    printf(" 1 2 8 ");
    }else if(num==256){
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11);
    printf(" 2 5 6 ");
    }else if(num==512){
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
    printf(" 5 1 2 ");
    }else if(num==1024){
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
    printf("1 0 2 4");
    }else if(num==2048){
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("2 0 4 8");
    }
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
}
void drawboard4(int score, int combo, int move, int thisturnscore){
    system("cls");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
    printf("\n  < 2 0 4 8 >");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
    printf("\n\n  SCORE : ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    printf("%d",score);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
    printf(" (+%d)",thisturnscore);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 13);
    printf("\n                         Combo : ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    printf("%d",combo);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("\n  Time : ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    printf("%0.2f left",timeleft);
    printf("\n\n=================================\n");
    printf("|       |       |       |       |\n");
    for(int i=0;i<4;i++){
        printf("|");
        for(int j=0;j<4;j++){
            printnum(board4[i][j]);printf("|");
        }
        if(i==3){break;}
        printf("\n|       |       |       |       |\n=================================\n|       |       |       |       |\n");
    }
    printf("\n|       |       |       |       |\n=================================\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
    printf("\n\n\nPress Esc to EXIT\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
}
void drawboard5(int score, int combo, int move, int thisturnscore){
    system("cls");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
    printf("\n  < 2 0 4 8 >");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
    printf("\n\n  SCORE : ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    printf("%d",score);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
    printf(" (+%d)",thisturnscore);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 13);
    printf("\n                              Combo : ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    printf("%d",combo);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("\n  Time : ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    printf("%0.2f left",timeleft);
    printf("\n=========================================\n");
    printf("|       |       |       |       |       |\n");
    for(int i=0;i<5;i++){
        printf("|");
        for(int j=0;j<5;j++){
            printnum(board5[i][j]);printf("|");
        }
        if(i==4){break;}
        printf("\n|       |       |       |       |       |\n=========================================\n|       |       |       |       |       |\n");
    }
    printf("\n|       |       |       |       |       |\n=========================================\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
    printf("Press Esc to EXIT\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
}
int howmanyzero(int a,int b,int c,int d){
    int count=0;
    if(a==0){count++;}
    if(b==0){count++;}
    if(c==0){count++;}
    if(d==0){count++;}
    return count;
}
int howmanyzero2(int a,int b,int c,int d, int e){
    int count=0;
    if(a==0){count++;}
    if(b==0){count++;}
    if(c==0){count++;}
    if(d==0){count++;}
    if(e==0){count++;}
    return count;
}
int movecheck(int a,int b,int c,int d){
    if(howmanyzero(a,b,c,d)==4){     //4칸 다 0
        return -1;
    }else if(howmanyzero(a,b,c,d)==3&&d!=0){
        return -1;
    }else if(howmanyzero(a,b,c,d)==2&&d!=0&&c!=0&&d!=c){
        return -1;
    }else if(howmanyzero(a,b,c,d)==1&&a==0&&b!=c&&c!=d){
        return -1;
    }else if(howmanyzero(a,b,c,d)==0&&a!=b&&b!=c&&c!=d){
        return -1;
    }else{
        return 0;
    }
}
int movecheck2(int a,int b,int c,int d, int e){
    if(howmanyzero2(a,b,c,d,e)==5){     //5칸 다 0
        return -1;
    }else if(howmanyzero2(a,b,c,d,e)==4&&e!=0){
        return -1;
    }else if(howmanyzero2(a,b,c,d,e)==3&&a+b+c==0&&d!=e){
        return -1;
    }else if(howmanyzero2(a,b,c,d,e)==2&&a+b==0&&c!=d&&d!=e){
        return -1;
    }else if(howmanyzero2(a,b,c,d,e)==1&&a==0&&b!=c&&c!=d&&d!=e){
        return -1;
    }else if(howmanyzero2(a,b,c,d,e)==0&&a!=b&&b!=c&&c!=d&&d!=e){
        return -1;
    }else{
        return 0;
    }
}
int moving(int *a1,int *a2,int *a3,int *a4){
    while(*a4==0&&(*a3!=0||*a2!=0||*a1!=0)){*a4=*a3; *a3=*a2; *a2=*a1; *a1=0;}
    while(*a3==0&&(*a2!=0||*a1!=0)){*a3=*a2; *a2=*a1; *a1=0;}
    while(*a2==0&&(*a1!=0)){*a2=*a1; *a1=0;}
    int returnvalue=0;
    if(*a1==*a2&&*a2!=*a3&&*a3!=*a4){
        if(*a1**a2==0){returnvalue=0;}
        else{returnvalue= *a2+*a1;}
        *a2+=*a1; *a1=0;
        return returnvalue;
    }else if((*a1!=*a2&&*a2==*a3&&*a3!=*a4)||(*a1==*a2&&*a2==*a3&&*a3!=*a4)){
        if(*a2**a3==0){returnvalue= 0;}
        else{returnvalue= *a3+*a2;}
        *a3+=*a2; *a2=*a1; *a1=0;
        return returnvalue;
    }else if((*a1!=*a2&&*a2!=*a3&&*a3==*a4)||(*a1!=*a2&&*a2==*a3&&*a3==*a4)){
        if(*a4**a3==0){returnvalue= 0;}
        else{returnvalue= *a4+*a3;}
        *a4+=*a3; *a3=*a2; *a2=*a1; *a1=0;
        return returnvalue;
    }else if((*a1==*a2&&*a2!=*a3&&*a3==*a4)||(*a1==*a2&&*a2==*a3&&*a3==*a4)){
        if(*a4**a3==0&&*a2**a1==0){returnvalue= 0;}
        else if(*a4**a3==0){returnvalue= *a2+*a1;}
        else if(*a2**a1==0){returnvalue= *a4+*a3;}
        else{returnvalue= *a4+*a3+*a2+*a1;}
        *a4+=*a3; *a3=*a2+*a1; *a2=0; *a1=0;
        return returnvalue;
    }else{
        return 0;
    }
}
int moving2(int *a1,int *a2,int *a3,int *a4, int *a5){
    while(*a5==0&&(*a4!=0||*a3!=0||*a2!=0||*a1!=0)){*a5=*a4; *a4=*a3; *a3=*a2; *a2=*a1; *a1=0;}
    while(*a4==0&&(*a3!=0||*a2!=0||*a1!=0)){*a4=*a3; *a3=*a2; *a2=*a1; *a1=0;}
    while(*a3==0&&(*a2!=0||*a1!=0)){*a3=*a2; *a2=*a1; *a1=0;}
    while(*a2==0&&(*a1!=0)){*a2=*a1; *a1=0;}
    if(*a1==*a2&&*a2!=*a3&&*a3!=*a4&&*a4!=*a5){
        *a2+=*a1; *a1=0;
        return *a2;
    }else if((*a1!=*a2&&*a2==*a3&&*a3!=*a4&&*a4!=*a5)||(*a1==*a2&&*a2==*a3&&*a3!=*a4&&*a4!=*a5)){
        *a3+=*a2; *a2=*a1; *a1=0;
        return *a3;
    }else if((*a1!=*a2&&*a2!=*a3&&*a3==*a4&&*a4!=*a5)||(*a1!=*a2&&*a2==*a3&&*a3==*a4&&*a4!=*a5)){
        *a4+=*a3; *a3=*a2; *a2=*a1; *a1=0;
        return *a4;
    }else if((*a1!=*a2&&*a2!=*a3&&*a3!=*a4&&*a4==*a5)||(*a1!=*a2&&*a2!=*a3&&*a3==*a4&&*a4==*a5)){
        *a5+=*a4; *a4=*a3; *a3=*a2; *a2=*a1; *a1=0;
        return *a5;
    }else if((*a1==*a2&&*a2!=*a3&&*a3==*a4&&*a4!=*a5)||(*a1==*a2&&*a2==*a3&&*a3==*a4&&*a4!=*a5)){
        *a4+=*a3; *a3=*a2+*a1; *a2=0; *a1=0;
        return *a4+*a3;
    }else if((*a1==*a2&&*a2!=*a3&&*a3!=*a4&&*a4==*a5)||(*a1==*a2&&*a2!=*a3&&*a3==*a4&&*a4==*a5)){
        *a5+=*a4; *a4=*a3; *a3=*a2+*a1; *a2=0; *a1=0;
        return *a5+*a3;
    }else if((*a1!=*a2&&*a2==*a3&&*a3!=*a4&&*a4==*a5)||(*a1==*a2&&*a2==*a3&&*a3==*a4&&*a4==*a5)||(*a1==*a2&&*a2==*a3&&*a3!=*a4&&*a4==*a5)||(*a1!=*a2&&*a2==*a3&&*a3==*a4&&*a4==*a5)){
        *a5+=*a4; *a4=*a3+*a2; *a3=0; *a2=0; *a1=0;
        return *a5+*a4;
    }else{
        return 0;
    }
}
int ingame4(){
    gaming=1;
    timeleft=600;
    int score=0;
    int combo=0;
    int move=0;
    int ending=0;  //1은 승리, -1은 패배
    int beforenumsoo=0;
    int afternumsoo=0;
    int thisturnscore=0;
    int maxcombo=0;
    int pressesc=0;
    for(int i=0;i<4;i++){           //배열 초기화
        for(int j=0;j<4;j++){
            board4[i][j]=0;
        }
    }
    int r1=rand()%4; int r2=rand()%4;  //초기 랜덤 숫자 좌표
    int r3; int r4;
    while(1){
        r3=rand()%4; r4=rand()%4;
        if(r1!=r3||r2!=r4){break;}
    }
    int r5=rand()%5; int r6=rand()%4;   //초기 랜덤 숫자 2 or 4
    if(r5==3){r5=4;}else{r5=2;}
    if(r6==3){r6=4;}else{r6=2;}
    board4[r1][r2]=r5; board4[r3][r4]=r6;
    drawboard4(score, combo, move, thisturnscore);
    while(1){
        clock_t start=clock();
        char input;
        input=getch();
        beforenumsoo=0;
        afternumsoo=0;
        thisturnscore=0;
        for (int i=0;i<4;i++){
            beforenumsoo+=howmanyzero(board4[3][i],board4[2][i],board4[1][i],board4[0][i]);
        }
        int isitmove=0;
        if(input=='W'||input=='w'){
            for(int i=0;i<4;i++){
                int *a1=&board4[3][i];int *a2=&board4[2][i];int *a3=&board4[1][i];int *a4=&board4[0][i];
                if(movecheck(board4[3][i],board4[2][i],board4[1][i],board4[0][i])!=-1){
                    isitmove=1;
                    thisturnscore+=moving(a1,a2,a3,a4);
                }
            }
        }else if(input=='A'||input=='a'){
            for(int i=0;i<4;i++){
                int *a1=&board4[i][3];int *a2=&board4[i][2];int *a3=&board4[i][1];int *a4=&board4[i][0];
                if(movecheck(board4[i][3],board4[i][2],board4[i][1],board4[i][0])!=-1){
                    isitmove=1;
                    thisturnscore+=moving(a1,a2,a3,a4);
                }
            }
        }else if(input=='S'||input=='s'){
            for(int i=0;i<4;i++){
                int *a1=&board4[0][i];int *a2=&board4[1][i];int *a3=&board4[2][i];int *a4=&board4[3][i];
                if(movecheck(board4[0][i],board4[1][i],board4[2][i],board4[3][i])!=-1){
                    isitmove=1;
                    thisturnscore+=moving(a1,a2,a3,a4);
                }
            }
        }else if(input=='D'||input=='d'){
            for(int i=0;i<4;i++){
                int *a1=&board4[i][0];int *a2=&board4[i][1];int *a3=&board4[i][2];int *a4=&board4[i][3];
                if(movecheck(board4[i][0],board4[i][1],board4[i][2],board4[i][3])!=-1){
                    isitmove=1;
                    thisturnscore+=moving(a1,a2,a3,a4);
                }
            }
        }else if(input==27){
            pressesc=1; break;
        }else{
            continue;
        }
        for (int i=0;i<4;i++){
            afternumsoo+=howmanyzero(board4[3][i],board4[2][i],board4[1][i],board4[0][i]);
        }
        if(beforenumsoo<afternumsoo){
            combo++;
            if(maxcombo<combo){
                maxcombo=combo;
            }
        }else{
            combo=0;
        }
        if(isitmove){move++;}
        else{continue;}
        int randomx; int randomy; int randomnumber=rand()%4;         //랜덤 숫자 생성
            if(randomnumber==3){randomnumber=4;}else{randomnumber=2;}
            while(1){
                randomx=rand()%4; randomy=rand()%4;
                if(board4[randomx][randomy]==0){
                    board4[randomx][randomy]=randomnumber; break;
                }
            }
        ending=-1;
        for(int i=0;i<4;i++){
            if(movecheck(board4[3][i],board4[2][i],board4[1][i],board4[0][i])!=-1){ending=0;}
            if(movecheck(board4[i][3],board4[i][2],board4[i][1],board4[i][0])!=-1){ending=0;}
            if(movecheck(board4[0][i],board4[1][i],board4[2][i],board4[3][i])!=-1){ending=0;}
            if(movecheck(board4[i][0],board4[i][1],board4[i][2],board4[i][3])!=-1){ending=0;}
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(board4[i][j]==2048){ending=1;}
            }
        }
        clock_t end=clock();
        float losttime=((float)end-(float)start)/(float)CLOCKS_PER_SEC;
        timeleft-=(losttime);
        if(timeleft<0){timeleft=0;}
        if(timeleft==0){
            ending=-1;
        }
        score+=thisturnscore;
        if(ending!=0){break;}
        drawboard4(score, combo, move, thisturnscore);
    }
    if(ending==-1){
    system("cls");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
    printf("\n  < 2 0 4 8 >");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
    printf("\n\n  SCORE : ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    printf("%d",score);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
    printf(" (+%d)",thisturnscore);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 13);
    printf("\n                      Combo : ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    printf("%d",combo);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("\n  Time : ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    printf("%0.2f left",timeleft);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
    printf("\n\n=================================\n");
    printf("|       |       |       |       |\n");
    for(int i=0;i<4;i++){
        printf("|");
        for(int j=0;j<4;j++){
            printnum(board4[i][j]);SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);printf("|");
        }
    if(i==3){break;}SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
    printf("\n|       |       |       |       |\n=================================\n|       |       |       |       |\n");
    }
    printf("\n|       |       |       |       |\n=================================\n\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12); printf(" You Lose...      ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11); printf("Score:    %d\n\n",score);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8); printf("Press Esc to Exit.\n"); gaming=0;
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    while(1){
        char input;
        input=getch();
        if(input==27){
            break;
        }
    }
    }else if(ending==1){
        system("cls");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
        printf("\n  < 2 0 4 8 >");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
        printf("\n\n  SCORE : ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("%d",score);
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
        printf(" (+%d)",thisturnscore);
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 13);
        printf("\n                      Combo : ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("%d",combo);
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
        printf("\n  Time : ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("%0.2f left",timeleft);
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
        printf("\n\n=================================\n");
        printf("|       |       |       |       |\n");
        for(int i=0;i<4;i++){
            printf("|");
            for(int j=0;j<4;j++){
                printnum(board4[i][j]);SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);printf("|");
            }
        if(i==3){break;}SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
        printf("\n|       |       |       |       |\n=================================\n|       |       |       |       |\n");
        }
        printf("\n|       |       |       |       |\n=================================\n\n");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14); printf(" You Win!         ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11); printf("Score:    %d\n\n",score);
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8); printf("Press Esc to Exit.\n"); gaming=0;
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        while(1){
            char input;
            input=getch();
            if(input==27){
                break;
            }
        }
    }
    if(!pressesc){rankupload(4, ending, move, timeleft, maxcombo, score);}
    return 0;
}
int ingame5(){
    gaming=1;
    timeleft=600;
    int score=0;
    int combo=0;
    int move=0;
    int ending=0;  //1은 승리, -1은 패배
    int beforenumsoo=0;
    int afternumsoo=0;
    int thisturnscore=0;
    int maxcombo=0;
    int pressesc=0;
    for(int i=0;i<5;i++){           //배열 초기화
        for(int j=0;j<5;j++){
            board5[i][j]=0;
        }
    }
    int r1=rand()%5; int r2=rand()%5;  //초기 랜덤 숫자 좌표
    int r3; int r4;
    while(1){
        r3=rand()%5; r4=rand()%5;
        if(r1!=r3||r2!=r4){break;}
    }
    int r5=rand()%5; int r6=rand()%4;   //초기 랜덤 숫자 2 or 4
    if(r5==3){r5=4;}else{r5=2;}
    if(r6==3){r6=4;}else{r6=2;}
    board5[r1][r2]=r5; board5[r3][r4]=r6;
    drawboard5(score, combo, move, thisturnscore);
    while(1){
        clock_t start=clock();
        char input;
        input=getch();
        beforenumsoo=0;
        afternumsoo=0;
        thisturnscore=0;
        for (int i=0;i<5;i++){
            beforenumsoo+=howmanyzero2(board5[4][i],board5[3][i],board5[2][i],board5[1][i],board5[0][i]);
        }
        int isitmove=0;
        if(input=='W'||input=='w'){
            for(int i=0;i<5;i++){
                int *a1=&board5[4][i];int *a2=&board5[3][i];int *a3=&board5[2][i];int *a4=&board5[1][i];int *a5=&board5[0][i];
                if(movecheck2(board5[4][i],board5[3][i],board5[2][i],board5[1][i],board5[0][i])!=-1){
                    isitmove=1;
                    thisturnscore+=moving2(a1,a2,a3,a4,a5);
                }
            }
        }else if(input=='A'||input=='a'){
            for(int i=0;i<5;i++){
                int *a1=&board5[i][4];int *a2=&board5[i][3];int *a3=&board5[i][2];int *a4=&board5[i][1];int *a5=&board5[i][0];
                if(movecheck2(board5[i][4],board5[i][3],board5[i][2],board5[i][1],board5[i][0])!=-1){
                    isitmove=1;
                    thisturnscore+=moving2(a1,a2,a3,a4,a5);
                }
            }
        }else if(input=='S'||input=='s'){
            for(int i=0;i<5;i++){
                int *a1=&board5[0][i];int *a2=&board5[1][i];int *a3=&board5[2][i];int *a4=&board5[3][i];int *a5=&board5[4][i];
                if(movecheck2(board5[0][i],board5[1][i],board5[2][i],board5[3][i],board5[4][i])!=-1){
                    isitmove=1;
                    thisturnscore+=moving2(a1,a2,a3,a4,a5);
                }
            }
        }else if(input=='D'||input=='d'){
            for(int i=0;i<5;i++){
                int *a1=&board5[i][0];int *a2=&board5[i][1];int *a3=&board5[i][2];int *a4=&board5[i][3];int *a5=&board5[i][4];
                if(movecheck2(board5[i][0],board5[i][1],board5[i][2],board5[i][3],board5[i][4])!=-1){
                    isitmove=1;
                    thisturnscore+=moving2(a1,a2,a3,a4,a5);
                }
            }
        }else if(input==27){
            pressesc=1; break;
        }else{
            continue;
        }
        for (int i=0;i<5;i++){
            afternumsoo+=howmanyzero2(board5[4][i],board5[3][i],board5[2][i],board5[1][i],board5[0][i]);
        }
        if(beforenumsoo<afternumsoo){
            combo++;
            if(maxcombo<combo){
                maxcombo=combo;
            }
        }else{
            combo=0;
        }
        if(isitmove){move++;}
        else{continue;}
        int randomx; int randomy; int randomnumber=rand()%4;         //랜덤 숫자 생성
            if(randomnumber==3){randomnumber=4;}else{randomnumber=2;}
            while(1){
                randomx=rand()%5; randomy=rand()%5;
                if(board5[randomx][randomy]==0){
                    board5[randomx][randomy]=randomnumber; break;
                }
            }
        ending=-1;
        for(int i=0;i<5;i++){
            if(movecheck2(board5[4][i],board5[3][i],board5[2][i],board5[1][i],board5[0][i])!=-1){ending=0;}
            if(movecheck2(board5[i][4],board5[i][3],board5[i][2],board5[i][1],board5[i][0])!=-1){ending=0;}
            if(movecheck2(board5[0][i],board5[1][i],board5[2][i],board5[3][i],board5[4][i])!=-1){ending=0;}
            if(movecheck2(board5[i][0],board5[i][1],board5[i][2],board5[i][3],board5[i][4])!=-1){ending=0;}
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(board5[i][j]==2048){ending=1;}
            }
        }
        clock_t end=clock();
        float losttime=((float)end-(float)start)/(float)CLOCKS_PER_SEC;
        timeleft-=(losttime);
        if(timeleft<0){timeleft=0;}
        if(timeleft==0){
            ending=-1;
        }
        score+=thisturnscore;
        if(ending!=0){break;}
        drawboard5(score, combo, move, thisturnscore);
    }
    if(ending==-1){
    system("cls");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
    printf("\n  < 2 0 4 8 >");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
    printf("\n\n  SCORE : ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    printf("%d",score);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
    printf(" (+%d)",thisturnscore);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 13);
    printf("\n                           Combo : ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    printf("%d",combo);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
    printf("\n  Time : ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    printf("%0.2f left",timeleft);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
    printf("\n=========================================\n");
    printf("|       |       |       |       |       |\n");
    for(int i=0;i<5;i++){
        printf("|");
        for(int j=0;j<5;j++){
            printnum(board5[i][j]);SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);printf("|");
        }
    if(i==4){break;}SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
    printf("\n|       |       |       |       |       |\n=========================================\n|       |       |       |       |       |\n");
    }
    printf("\n|       |       |       |       |       |\n=========================================\n");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12); printf(" You Lose...      ");
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11); printf("Score:    %d\n",score);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8); printf("Press Esc to Exit.\n"); gaming=0;
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
    while(1){
        char input;
        input=getch();
        if(input==27){
            break;
        }
    }
    }else if(ending==1){
        system("cls");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
        printf("\n  < 2 0 4 8 >");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
        printf("\n\n  SCORE : ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("%d",score);
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
        printf(" (+%d)",thisturnscore);
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 13);
        printf("\n                              Combo : ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("%d",combo);
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
        printf("\n  Time : ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        printf("%0.2f left",timeleft);
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
        printf("\n=========================================\n");
        printf("|       |       |       |       |       |\n");
        for(int i=0;i<5;i++){
            printf("|");
            for(int j=0;j<5;j++){
                printnum(board5[i][j]);SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);printf("|");
            }
        if(i==4){break;}SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
        printf("\n|       |       |       |       |       |\n=========================================\n|       |       |       |       |       |\n");
        }
        printf("\n|       |       |       |       |       |\n=========================================\n");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14); printf(" You Win!         ");
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11); printf("Score:    %d\n",score);
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8); printf("Press Esc to Exit.\n"); gaming=0;
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
        while(1){
            char input;
            input=getch();
            if(input==27){
                break;
            }
        }
    }
    if(!pressesc){rankupload(5, ending, move, timeleft, maxcombo, score);}
    return 0;
}
