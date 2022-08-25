#include <iostream>
#include <unistd.h>
#include <cstdio>
//#include "input.hpp"
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

using namespace std;

void rajz(int *allapot, int &jatekos, int &lepes, int &vege, int &jatekmod);
void lepesem(int *allapot, int &jatekos, int &lepes, int &vege);
void nyert(int *allapot, int &vege);
void bot(int *allapot, int &jatekos, int &lepes, int &vege);

int main()
{

    int vege_main=0, jatekos_main=0, lepes_main=0;
    int allapot_main[]={0,0,0,0,0,0,0,0,0};

    int jatekmod_main=0;

    while(jatekmod_main!=1 && jatekmod_main!=2){
        system("CLS");
        cout<<"hany jatekos van? ";
        cin.clear();
        cin>>jatekmod_main;
    }

    if(jatekmod_main==2){

        while(vege_main==0){
            rajz(allapot_main, jatekos_main, lepes_main, vege_main, jatekmod_main);
            lepesem(allapot_main, jatekos_main, lepes_main, vege_main);
            if(jatekos_main % 2==1){
                allapot_main[lepes_main]=1;
            }
            if(jatekos_main % 2==0){
                allapot_main[lepes_main]=2;
            }
            nyert(allapot_main, vege_main);

            if(jatekos_main==9){
                rajz(allapot_main, jatekos_main, lepes_main, vege_main, jatekmod_main);
                cout<<"dontetlen :(";
                //ha van termios (linux) akko ez jöhet vissza
                //sleep(1000);
                return 0;
            }

        }

        rajz(allapot_main, jatekos_main, lepes_main, vege_main, jatekmod_main);

        if(jatekos_main % 2==1){
            cout<<"X nyert!";
            //sleep(1000);
            return 0;

        }

        if(jatekos_main % 2==0){
            cout<<"O nyert!";
            //sleep(1000);
            return 0;
        }

    }

    if(jatekmod_main==1){
        while(vege_main==0){
            rajz(allapot_main, jatekos_main, lepes_main, vege_main, jatekmod_main);
            lepesem(allapot_main, jatekos_main, lepes_main, vege_main);
            allapot_main[lepes_main]=1;
            nyert(allapot_main, vege_main);
            if(vege_main==1){
                rajz(allapot_main, jatekos_main, lepes_main, vege_main, jatekmod_main);
                cout<<"nyertel!";
                //sleep(1000);
                return 0;
            }
            if(jatekos_main==5){
                rajz(allapot_main, jatekos_main, lepes_main, vege_main, jatekmod_main);
                cout<<"dontetlen :(";
                //sleep(1000);
                return 0;
            }


            bot(allapot_main, jatekos_main, lepes_main, vege_main);
            rajz(allapot_main, jatekos_main, lepes_main, vege_main, jatekmod_main);
            allapot_main[lepes_main]=2;
            nyert(allapot_main, vege_main);
            if(vege_main==1){
                rajz(allapot_main, jatekos_main, lepes_main, vege_main, jatekmod_main);
                cout<<"nyertem!";
                //sleep(1000);
                return 0;
            }
        }
        //sleep(1000);
        return 0;
    }
}

void bot(int *allapot, int &jatekos, int &lepes, int &vege){

    //!sajat nyeres felismerese
    for(int i=0;i<9;i++){
        if(allapot[i]==2){
            if(i==4){
                if((allapot[i-4]==2 || allapot[i+4]==2) && (allapot[i-4]==0 || allapot[i+4]==0)){
                    if(allapot[i-4]==0){
                        lepes=i-4;
                        return;
                    }
                    else{
                        lepes=i+4;
                        return;
                    }
                }
                if((allapot[i-2]==2 || allapot[i+2]==2) && (allapot[i-2]==0 || allapot[i+2]==0)){
                    if(allapot[i-2]==0){
                        lepes=i-2;
                        return;
                    }
                    else{
                        lepes=i+2;
                        return;
                    }
                }
                if((allapot[i-3]==2 || allapot[i+3]==2) && (allapot[i-3]==0 || allapot[i+3]==0)){
                    if(allapot[i-3]==0){
                        lepes=i-3;
                        return;
                    }
                    else{
                        lepes=i+3;
                        return;
                    }
                }
                if((allapot[i-1]==2 || allapot[i+1]==2) && (allapot[i-1]==0 || allapot[i+1]==0)){
                    if(allapot[i-1]==0){
                        lepes=i-1;
                        return;
                    }
                    else{
                        lepes=i+1;
                        return;
                    }
                }
            }
            if(i==0 || i==6){
                if((allapot[i+1]==2 || allapot[i+2]==2) && (allapot[i+1]==0 || allapot[i+2]==0)){
                    if(allapot[i+1]==0){
                        lepes=i+1;
                        return;
                    }
                    else{
                        lepes=i+2;
                        return;
                    }
                }
            }
            if(i==2 || i==8){
                if((allapot[i-1]==2 || allapot[i-2]==2) && (allapot[i-1]==0 || allapot[i-2]==0)){
                    if(allapot[i-1]==0){
                        lepes=i-1;
                        return;
                    }
                    else{
                        lepes=i-2;
                        return;
                    }
                }
            }
            if(i==0 || i==2){
                if((allapot[i+3]==2 || allapot[i+6]==2) && (allapot[i+3]==0 || allapot[i+6]==0)){
                    if(allapot[i+3]==0){
                        lepes=i+3;
                        return;
                    }
                    else{
                        lepes=i+6;
                        return;
                    }
                }
            }
            if(i==6 || i==8){
                if((allapot[i-3]==2 || allapot[i-6]==2) && (allapot[i-3]==0 || allapot[i-6]==0)){
                    if(allapot[i-3]==0){
                        lepes=i-3;
                        return;
                    }
                    else{
                        lepes=i-6;
                        return;
                    }
                }
            }
        }
    }

    //!veszto allas felismerese
    for(int i=0;i<9;i++){
        if(allapot[i]==1){
            if(i==4){
                if((allapot[i-4]==1 || allapot[i+4]==1) && (allapot[i-4]==0 || allapot[i+4]==0)){
                    if(allapot[i-4]==0){
                        lepes=i-4;
                        return;
                    }
                    else{
                        lepes=i+4;
                        return;
                    }
                }
                if((allapot[i-2]==1 || allapot[i+2]==1) && (allapot[i-2]==0 || allapot[i+2]==0)){
                    if(allapot[i-2]==0){
                        lepes=i-2;
                        return;
                    }
                    else{
                        lepes=i+2;
                        return;
                    }
                }
                if((allapot[i-3]==1 || allapot[i+3]==1) && (allapot[i-3]==0 || allapot[i+3]==0)){
                    if(allapot[i-3]==0){
                        lepes=i-3;
                        return;
                    }
                    else{
                        lepes=i+3;
                        return;
                    }
                }
                if((allapot[i-1]==1 || allapot[i+1]==1) && (allapot[i-1]==0 || allapot[i+1]==0)){
                    if(allapot[i-1]==0){
                        lepes=i-1;
                        return;
                    }
                    else{
                        lepes=i+1;
                        return;
                    }
                }
            }
            if(i==0 || i==6){
                if((allapot[i+1]==1 || allapot[i+2]==1) && (allapot[i+1]==0 || allapot[i+2]==0)){
                    if(allapot[i+1]==0){
                        lepes=i+1;
                        return;
                    }
                    else{
                        lepes=i+2;
                        return;
                    }
                }
            }
            if(i==2 || i==8){
                if((allapot[i-1]==1 || allapot[i-2]==1) && (allapot[i-1]==0 || allapot[i-2]==0)){
                    if(allapot[i-1]==0){
                        lepes=i-1;
                        return;
                    }
                    else{
                        lepes=i-2;
                        return;
                    }
                }
            }
            if(i==0 || i==2){
                if((allapot[i+3]==1 || allapot[i+6]==1) && (allapot[i+3]==0 || allapot[i+6]==0)){
                    if(allapot[i+3]==0){
                        lepes=i+3;
                        return;
                    }
                    else{
                        lepes=i+6;
                        return;
                    }
                }
            }
            if(i==6 || i==8){
                if((allapot[i-3]==1 || allapot[i-6]==1) && (allapot[i-3]==0 || allapot[i-6]==0)){
                    if(allapot[i-3]==0){
                        lepes=i-3;
                        return;
                    }
                    else{
                        lepes=i-6;
                        return;
                    }
                }
            }
        }
    }


    if(jatekos==1){
        if(allapot[4]==1){
            lepes=8;
            return;
        }
        else{
            lepes=4;
            return;
        }
    }

    //!egyeb

    if(allapot[4]!=0){
        if(allapot[1]==0){
            lepes=1;
            return;
        }
        if(allapot[3]==0){
            lepes=3;
            return;
        }
        if(allapot[5]==0){
            lepes=5;
            return;
        }
        if(allapot[7]==0){
            lepes=7;
            return;
        }
    }

    if(allapot[0]==0){
        lepes=0;
        return;
    }
    if(allapot[2]==0){
        lepes=2;
        return;
    }
    if(allapot[4]==0){
        lepes=4;
        return;
    }
    if(allapot[8]==0){
        lepes=8;
        return;
    }

    return;
}

void nyert(int *allapot, int &vege){
    if(allapot[0]==allapot[1] && allapot[1]==allapot[2]){
        if(allapot[0]==1 || allapot[0]==2){
            vege=1;
            return;
        }
    }
    if(allapot[3]==allapot[4] && allapot[4]==allapot[5]){
        if(allapot[3]==1 || allapot[3]==2){
            vege=1;
            return;
        }
    }
    if(allapot[6]==allapot[7] && allapot[7]==allapot[8]){
        if(allapot[6]==1 || allapot[6]==2){
            vege=1;
            return;
        }
    }
    //!##################################################
    if(allapot[0]==allapot[3] && allapot[3]==allapot[6]){
        if(allapot[0]==1 || allapot[0]==2){
            vege=1;
            return;
        }
    }
    if(allapot[1]==allapot[4] && allapot[4]==allapot[7]){
        if(allapot[1]==1 || allapot[1]==2){
            vege=1;
            return;
        }
    }
    if(allapot[2]==allapot[5] && allapot[5]==allapot[8]){
        if(allapot[2]==1 || allapot[2]==2){
            vege=1;
            return;
        }
    }
    //!##################################################
    if(allapot[0]==allapot[4] && allapot[4]==allapot[8]){
        if(allapot[0]==1 || allapot[0]==2){
            vege=1;
            return;
        }
    }
    if(allapot[2]==allapot[4] && allapot[4]==allapot[6]){
        if(allapot[2]==1 || allapot[2]==2){
            vege=1;
            return;
        }
    }

    return;
}

void rajz(int *allapot, int &jatekos, int &lepes, int &vege, int &jatekmod){

    system ("CLS");
    int i=0, j=0;
    while(i<9){
        if(i/3==0){
            if(i==0){
                cout<<"#####################\n";
            }
            for(j=0;j<3;j++){
                if(allapot[(i/3)+j]==0){
                    cout<<"#     #";
                }
                if(allapot[(i/3)+j]==1){
                    if(i!=1){
                        cout<<"# X X #";
                    }
                    else{
                        cout<<"#  X  #";
                    }
                }
                if(allapot[(i/3)+j]==2){
                    if(i!=1){
                        cout<<"#  O  #";
                    }
                    else{
                        cout<<"# O O #";
                    }
                }
            }
            cout<<endl;
            i++;
            if(i==3){
                cout<<"#####################\n";
            }
        }
        if(i/3==1){
            for(j=0;j<3;j++){
                if(allapot[(i/3)+2+j]==0){
                    cout<<"#     #";
                }
                if(allapot[(i/3)+2+j]==1){
                    if(i!=4){
                        cout<<"# X X #";
                    }
                    else{
                        cout<<"#  X  #";
                    }
                }
                if(allapot[(i/3)+2+j]==2){
                    if(i!=4){
                        cout<<"#  O  #";
                    }
                    else{
                        cout<<"# O O #";
                    }
                }
            }
            cout<<endl;
            i++;
            if(i==6){
                cout<<"#####################\n";
            }
        }
        if(i/3==2){
            for(j=0;j<3;j++){
                if(allapot[(i/3)+4+j]==0){
                    cout<<"#     #";
                }
                if(allapot[(i/3)+4+j]==1){
                    if(i!=7){
                        cout<<"# X X #";
                    }
                    else{
                        cout<<"#  X  #";
                    }
                }
                if(allapot[(i/3)+4+j]==2){
                    if(i!=7){
                        cout<<"#  O  #";
                    }
                    else{
                        cout<<"# O O #";
                    }
                }
            }
            cout<<endl;
            i++;
            if(i==9){
                cout<<"#####################\n";
            }
        }
    }

    return;
}

void lepesem(int *allapot, int &jatekos, int &lepes, int &vege){

    if(vege==1){
        return;
    }

    int c = 0, nyilak=0;
    while(1){
        c = 0;
        switch((c=getch())) {
        case KEY_UP:
            if(nyilak>=3){
                nyilak=nyilak-3;
            }
            break;
        case KEY_DOWN:
            if(nyilak<=5){
                nyilak=nyilak+3;
            }
            break;
        case KEY_LEFT:
            if(nyilak!=0 && nyilak !=3 && nyilak!=6){
                nyilak--;
            }
            break;
        case KEY_RIGHT:
            if(nyilak!=2 && nyilak !=5 && nyilak!=8){
                nyilak++;
            }
            break;
        case ENTER:
            if(allapot[nyilak]==0){
                jatekos++;
                lepes=nyilak;
                return;
            }
        default:
            break;
        }
    }
}
