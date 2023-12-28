# include <iostream>
using namespace std;


void WaterGun(int& eCurHP, int& eDef){
    int baseDMG = 36 + rand( )%7; // 36 - 42 inclusive
    int realDMG = baseDMG - eDef;
    //eCurHp means current HP;
    eCurHP -= realDMG;
    cout << "Wartortle used Water Gun! It inflicted " << realDMG << " damage!\n";
}

void TailWhip(int& eDef){
    int defDropAmt = 7;
    eDef -= defDropAmt;
    cout << "Wartortle used Tail Whip! It lowered the opponent's Defense!\n";
}

void HydroPump(int& eCurHP, int& eDef){
    int accRoll = rand()%100+1; // 1 - 100 inclusive

    if(accRoll<=80){
        // attack hits
        int baseDMG = 105 + rand ( )%16; // 105 - 120 inclusive
        int realDMG = baseDMG - eDef;
        eCurHP -= realDMG;
        cout << "Wartortle used Hydro Pump! It inflicted " << realDMG << " damage!\n";

    }else{
        // attack misses
        cout << "Wartortle used Hydro Pump! The attack missed!\n";

    }
}



int main (){
    int eMaxHP = 434;
    int eDef = 22;
    int eCurHP = eMaxHP;
    bool GameOn = true;
    string action;
    
    while (GameOn){
        cout << "What will Wartortle do?\n> W for Water Gun\n";
        cout << "> T for Tail Whip\n> H for Hydro Pump\n> R for Run\n\n";
        cin >> action;

        if(action=="W" || action=="w" || action=="Water Gun"){
            WaterGun(eCurHP, eDef);
        }else if(action=="T" || action=="t" || action == "Tail Whip"){
            TailWhip(eDef);
        }else if(action=="H" || action=="h" || action == "Hydro Pump"){
            HydroPump(eCurHP, eDef);
        }else if(action=="R" || action=="r" || action == "Run" || action == "L" || action == "l" || action == "Leave"){
            cout << "You ran from the battle! Got away safely! You dealt " << eMaxHP - eCurHP << " Damage to your opponent.\n";
            GameOn = false; //run = leave
        }
	else {
            cout << "Invalid action; try again";
        }
		

        if(eCurHP<0){
            cout << "The opposing Jigglypuff fainted!\nYou won the battle!";
            GameOn = false;
        }
    }

    return 0;
}


