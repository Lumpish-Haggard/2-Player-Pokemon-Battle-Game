#include <bits/stdc++.h> //includes all relevent libraries automatically.
using namespace std ; //for reducing std redundancy 

enum PokemonType //creating enum for choosing pokemon. reduces code
{
    Bulbasaur, Pikachu, Charizard //by default, their values are bulbasaur=0,pikachu=1 and charizard=2
} ;

PokemonType t1Pokemon ; //creating objects of enum to be used later.
PokemonType t2Pokemon ;

bool t1Playing ; //necessary global variables.
int t1Input, t2Input ; //for taking input from user
char tInput, restart ; //mainly for restarting the game

class Trainer //base class to be inherited later
{
private: //declaring private variables so that they can't be manipulated outside of the class
    int jaanKaPotionMin ; //variable for minimum heal 
    int jaanKaPotionMax ; //variable for maximum heal

public: //now starts the public functions and variables
        int Health ; 
        int PokemonMaara ; //variable for 'give damage'

        void Shuruat(int jaan, int maar, int minMaar, int maxMaar, int _jaanKaPotionMin, int _jaanKaPotionMax) //void function for starting the game
        {
            Health = jaan ; //using hindi slangs as data variables
            PokemonMaara = maar ;
            
            jaanKaPotionMin = _jaanKaPotionMin ; //Shuruat function used for setting private variables
            jaanKaPotionMax = _jaanKaPotionMax ;
            //for output screen
            cout<<" \033[0mPokemon main kitni jaan hai: " << Health << endl ;  //displays Pokemon Health
            cout<<" \033[0mPokemon kitna maarta hai: " << PokemonMaara << endl ; //displays Pokemon damage
            cout <<" \033[0mPuri Jaan Laga ke kitna maar sakta hai: " << minMaar << " - " << maxMaar << endl ;//displays the range in which the pokemon can do more damage
            cout<<" \033[0mApne aap ko heal karne ki kshamta: " << jaanKaPotionMin <<" - "<< jaanKaPotionMax << endl ;  //displays the range in which pokemon can heal itself
        }
    
        virtual void MaarKhaana(int damage, int additionalDamage) //virtual function to be overridden
        {
          cout << "\033[0mBase function to be overridden." ; 
        }
       
        virtual int aurMaarna() //virtual function to be overridden
        {
          cout << "\033[0mBase function to be overridden." ;
          return 0 ; //returning 0 because it is int function.
        }
        
        void Heal() //creating the function to heal pokemon
        {
           
          if ((t1Pokemon == Bulbasaur && t1Playing) || (t2Pokemon == Bulbasaur && !t1Playing))
             { //nested if
                int BahotSaaraHeal ; //creating healing function to randomize it later
                srand(time(0)) ; //this function makes it unique everytime the code is run.
                BahotSaaraHeal = (rand() % (5 - 1 + 1)) + 1 ; //randomizing healing
                if (BahotSaaraHeal > 4)
                {
                    cout << "\033[0mTrainer healed Bulbasaur with a Boosted Health Potion!" << endl ;
                    Health += 25 ; //use of heal function
                    cout << "\033[0mNew Health after using Potion: " << Health << endl ;
                    return ;
                }
              }
           
           cout << KisTrainerKiBaari() << " \033[0mis using Health Potion" << endl ;
           int ThodaHealKarde ;
           srand(time(0)) ;
           ThodaHealKarde = (rand() % (jaanKaPotionMax - jaanKaPotionMin + 1)) + jaanKaPotionMax ;
           Health += ThodaHealKarde ;
           cout << KisTrainerKiBaari() << " \033[0mis Healed by " << ThodaHealKarde << " \033[0mand the current Health is: " << Health<<endl ;//displaying the health before and after the use of heal
        }
        string KisTrainerKiBaari()
        {
            if (t1Playing)
                return "\033[0mTrainer 1" ;
                return "\033[0mTrainer 2" ;
        }

        string SaamneKaunHai()
        {
            if (!t1Playing)
                return "\033[0mTrainer 1" ;
                return "\033[0mTrainer 2" ;
        }
} ;

class BulbasaurKiClass : public Trainer //creating bulbasaur class to inherit from Trainer class
{
private: //hardcoding private variables
    int BulbasaurKiHealth = 200 ; //health
    int BulbasaurKiTaakat = 40 ; //damage
    int KamSeKamKitnaMaar = 5 ; //range for min add damage
    int ZyadaSeZyadaMaar = 15 ; //range for max add damage
    int jaanKaPotionMax = 10 ; //range for max heal
    int jaanKaPotionMin = 5 ; //range for min heal

public:
    BulbasaurKiClass() //custom contructor for bulabasaurkiclass
    {
        cout << "\033[92mBulbasaur! Main Tumhe Chunta Hoon!" <<endl ;
        Shuruat(BulbasaurKiHealth, BulbasaurKiTaakat, KamSeKamKitnaMaar, ZyadaSeZyadaMaar, jaanKaPotionMin, jaanKaPotionMax) ;
    }
    void MaarKhaana(int damage,int additionalDamage) //take damage function
    {
        cout << "\033[92mBulbasaur Maar Kha Rha Hai!! (" << SaamneKaunHai() << ")" << endl ;
        cout << "\033[0mAur kitna Maara: " << additionalDamage << endl ;
       
        if (additionalDamage > ZyadaSeZyadaMaar - 3)
        {
            cout <<"\033[0mAbbe "<<KisTrainerKiBaari()<<" \033[0mne to Dhaaga Khol Diya "<<endl ;
        }

        int totalDamage = damage + additionalDamage ;

        cout<<KisTrainerKiBaari()<<" \033[0mne ab tak Total "<<totalDamage<<" \033[0mmaara."<<endl ;

        Health -= totalDamage ;
        cout<<SaamneKaunHai()<< " \033[0mke Pokemon ki maar khane ke baad health: " << Health<<endl ;
    }

    int aurMaarna() //additional damage function
    {
        int aurThoko ;
        srand(time(0)) ;
        aurThoko = (rand() % (ZyadaSeZyadaMaar - KamSeKamKitnaMaar + 1)) + KamSeKamKitnaMaar ;
        return aurThoko ;
    }
} ;

class PikachuKiClass : public Trainer //creating pikachu class to inherit from Trainer class
{
private:
    int PikachuKiHealth = 150 ; //health
    int PikachuKiTaakat = 30 ; //damage
    int KamSeKamKitnaMaar = 7 ; //min range for add damage
    int ZyadaSeZyadaMaar = 12 ; //max range for add damage
    int jaanKaPotionMax = 20 ; //max range for add heal
    int jaanKaPotionMin = 10 ; //min range for addd heal
public:
    PikachuKiClass() //custom constructor for Pikachukiclass
    {
        cout << "\033[93mPikachu! Main Tumhe Chunta Hoon!"<<endl ;
        Shuruat(PikachuKiHealth, PikachuKiTaakat, KamSeKamKitnaMaar, ZyadaSeZyadaMaar, jaanKaPotionMin, jaanKaPotionMax) ;
    }
    void MaarKhaana(int damage, int additionalDamage) //take damage function
    {
        int TukkeSeRoka ;
        srand(time(0)) ;
        TukkeSeRoka = (rand() % (7 - 1 + 1) + 1) ;
        cout << TukkeSeRoka << endl ;
        if (TukkeSeRoka > 5)
        {
            cout << "\033[93mPikachu Side hatke bach gaya! Kya Kismat Payi hai!"<<endl ;
            return ;
        }
        cout << "\033[93mPikachu maar kha rha hai! (" << SaamneKaunHai() << ")" << endl ;
        cout << "\033[0mAur Kitna Maara: " << additionalDamage << endl ;

        if (additionalDamage > ZyadaSeZyadaMaar - 3)
        {
          cout <<"\033[0mAbbe "<<KisTrainerKiBaari()<<" \033[0mne to Dhaaga Khol Diya "<<endl ;
        }
        int totalDamage = damage + additionalDamage ;

        cout<<KisTrainerKiBaari()<<" \033[0mne ab tak Total "<<totalDamage<<" maara."<<endl ;

        Health -= totalDamage ;
        cout<<SaamneKaunHai()<< " \033[0mke Pokemon ki maar khane ke baad health: " << Health<<endl ;
    }

    int aurMaarna() //add damage function
    {
        int aurThoko ;
        srand(time(0)) ;
        aurThoko = (rand() % (ZyadaSeZyadaMaar - KamSeKamKitnaMaar + 1)) + KamSeKamKitnaMaar ;
        return aurThoko ;
    } 
} ;

class CharizardKiClass : public Trainer //creating charizard class to inherit from Trainer class
{
private:
    int CharizardKiHealth = 100 ; //health
    int CharizardKiTaakat = 55 ; //damage
    int KamSeKamKitnaMaar = 8 ; //min add damage
    int ZyadaSeZyadaMaar = 18 ; //max add damage
    int jaanKaPotionMax = 30 ; //max add heal
    int jaanKaPotionMin = 20 ; //min add heal
public:
    CharizardKiClass() //custom constructor of charizardkiclass
    {
        cout << "\033[31mCharizard! Main Tumhe Chunta Hoon!"<<endl ;
        Shuruat(CharizardKiHealth, CharizardKiTaakat, KamSeKamKitnaMaar, ZyadaSeZyadaMaar, jaanKaPotionMin, jaanKaPotionMax) ;
    }
    void MaarKhaana(int damage,int additionalDamage) //take damage function
    {
        cout << "\033[31mCharizard maar Kha rha hai! (" << SaamneKaunHai() << ")" << endl ;
        cout << "\033[0mAur Kitna Maara: " << additionalDamage << endl ;

        if (additionalDamage > ZyadaSeZyadaMaar - 3)
        {
            cout <<"\033[0mAbbe "<<KisTrainerKiBaari()<<" ne to Dhaaga Khol Diya "<<endl ;
        }
        int totalDamage = damage + additionalDamage ;

        cout<<KisTrainerKiBaari()<<" \033[0mne ab tak Total "<<totalDamage<<" maara."<<endl ;

        Health -= totalDamage ;
        cout<<SaamneKaunHai()<< " \033[0mke Pokemon ki maar khane ke baad health: " << Health<<endl ;
    }
    int aurMaarna() //add damage function
    {
        int aurThoko ;
        srand(time(0)) ;
        aurThoko = (rand() % (ZyadaSeZyadaMaar - KamSeKamKitnaMaar + 1)) + KamSeKamKitnaMaar ;
        return aurThoko + 3 ; 
    }
} ;

void StartScreen() //user interface
{
    cout <<"\033[96mPokemon Fire Emblem ke is aitihasik Tournament main apka Swagat hai!" << endl ;
    cout <<"\033[92mRules sunlo ab sabke sab : \n" ;
    cout << "Hamare yaha sirf do he rule hai.\n * Pehla! Ki tum ek baari main sirf ek he kaam kar skte ho..yaa to maaro aur ya phir apni marham patti karo.\n * aur Dusra! Tumhe H dabana hoga Heal k liye aur D dabana hoga damage dene k liye. "<< endl ;
   
    cout <<"\033[95m**********************************************************************************************"<< endl ;
    cout <<"**********************************************************************************************"<< endl ;
    cout << "\033[97mHamare paas 3 Pokemon Hai!" << endl ;
    
    cout << endl ;
    cout << "\033[92m1) Bulbasaur! Nature se jude is Pokemon ki Health bahot High hai, lekin Damage bahot kam! Ye Health potion se thik thak health le sakta hai." << endl ;
    cout << " Specail Ability: Sun Seed! (Sooraj ki kirno se apne aapko kaafi heal kar skta hai!) \n Sludge Bomb!(Bahot Badboodar bomb hai; Ye mat Khaana!)" << endl ;
    cout << endl ;

    cout << endl ;
    cout << "\033[93m2) Pikachu! Chuho ki Duniya ka ye Thor kaafi Average hai apni zindagi main. Bas kyunki ye size main chota hai, isliye isko Health Potion se zyada heal kar skte hai." << endl ;
    cout << " Specail Ability: Sidestep(Side main Dodge karke apne aap ko bach sakta hai.) \n Ek hee bari main cheating karke Heal or Attack dono kar skta hai! " << endl ;
    cout << endl ;
   
    cout << endl ;
    cout << "\033[31m3) Charizard! Bahot Zaalim cheez hai ye. Iski health k alawa iska sab high rehta hai. Darr ke maare baki Pokemon iski peeth peeche isko Daanav bhi bolte hai." << endl ;
    cout <<" Specail Ability: Overheat(Khudki Health k heesab se Pelta hai! Jitni kam iski health, utna zyda gussa!) \n Kasam se bata rha hu, Bahot pelega ye!\033[97m" << endl ; 
    cout << endl ;
    
}
void TrainerKyaDabaya() //check input function
{
    if (t1Playing)
        cin >> t1Input ;
    else
        cin >> t2Input ;
   
}
void AbAgleKiBaari() //switching turn
{
    t1Playing = !t1Playing ;
}

void TrainerAction(Trainer* YeMainHu, Trainer* YeTuHai)
{
  
    if (tInput == 'D' || tInput == 'd')
    {
        if ((t1Pokemon == Bulbasaur && t1Playing) || (t2Pokemon == Bulbasaur && !t1Playing))
        {
            int SludgeBomb ; //Bulbasaur special attack
            srand(time(0)) ;
            SludgeBomb = (rand() % (5 - 1 + 1) + 1) ;
            if (SludgeBomb > 4) 
            {
                cout << "\033[92mBulbasaur used Sludge Bomb!...Gandagi kar di...ew"<<endl ;
                YeTuHai->MaarKhaana(YeMainHu->PokemonMaara, YeMainHu->aurMaarna()) ;
                YeTuHai->MaarKhaana(YeMainHu->PokemonMaara, YeMainHu->aurMaarna()) ;
                return ;
            }
        }
        else if ((t1Pokemon == Charizard && t1Playing) || (t2Pokemon == Charizard && !t1Playing))
        {
            if (YeMainHu->Health < 50)
            {
                cout << "\033[31mCharizard ko gussa aa gya hai. Bachke rehna!"<<endl ; //bulbasaur overheat ability
                YeTuHai->MaarKhaana(YeMainHu->PokemonMaara + 10, YeMainHu->aurMaarna()+10) ;
                return ;
            }
        }
     
        YeTuHai->MaarKhaana(YeMainHu->PokemonMaara, YeMainHu->aurMaarna()) ;
    }

    else if (tInput == 'H' || tInput == 'h')
    {
        if ((t1Pokemon == Pikachu && t1Playing) || (t2Pokemon == Pikachu && !t1Playing))
        {
            int cheatingKartaHai ; //pikachu cheating ability
            srand(time(0)) ;
            cheatingKartaHai = (rand() % (5 - 1 + 1) + 1) ;
            if (cheatingKartaHai > 2) 
            { 
                cout << "\033[93mAyye! Ye Saala Pikachu doobara cheating karta hai. Apne aap ko Heal bhi karliya aur samne wale ko maara bhi!" << endl ;
                YeTuHai->MaarKhaana(YeMainHu->PokemonMaara, YeMainHu->aurMaarna()) ;
            }
        }
        YeMainHu->Heal() ;
    }
    else
    {
       cout << "\033[0mAbbe Sahi se likh na!" << endl ; //handling invalid input error
       cin >> tInput ;
       TrainerAction(YeMainHu, YeTuHai) ;
    }
}


    
int main()
{
    Trainer* trainer1 ; //pointers for Trainer class
    Trainer* trainer2 ;
    trainer1 = NULL ; //preventing memory clogging and leak
    trainer2 = NULL ;

    cout << endl ;
    StartScreen() ; //start of gamne
    cout << endl ;
    do
    {
        cout << endl ;
        cout << "\033[0mSun Trainer 1 bhidu! In teeno main se apna Pokemon choose kar!\nBulbasaur ke liye 1 dabaye, Pikachu ke liye 2 dabaye aur Charizard ke liye 3!" ; //trainer 1 chooses his/her pokemon
        cout << endl ;

       
        t1Playing = true ;
        
        do
        { //trainer 1 choosing his/her pokemon
            TrainerKyaDabaya() ;
            cout << endl ;
            if (t1Input == 1)
            {
                t1Pokemon = Bulbasaur ;
                trainer1 = new BulbasaurKiClass ;
            }
            else if (t1Input == 2)
            {
                t1Pokemon = Pikachu ;
                trainer1 = new PikachuKiClass ;
            }
            else if (t1Input == 3)
            {
                t1Pokemon = Charizard ;
                trainer1 = new CharizardKiClass ;
            }
            else
            {
                cout << "\033[0mAbbe saale sahi input de na!" << endl ; //handling invalid input error
            }
        } while (t1Input > 3 || t1Input <= 0) ;
        cout << endl ;

        AbAgleKiBaari() ; //doosre trainer ki baari

        cout << endl ;
        cout << "\033[0mTrainer 2 Bhidu, ab tum select kar lo tumhara pokemon. Magar yaad rkhna jo Trainer 1 ne liya hai wo tum ab nhi le skte!" ;
        cout << endl ; //trainer 2's turn to choose pokemon

        do
        {
            TrainerKyaDabaya() ;
             if (t2Input > 3 || t2Input <= 0)
            {
            cout << "\033[0mAbbe saale sahi input de na!" << endl ; //handling invalid input error
            }
             else if (t1Input == t2Input)
            {
            cout << "\033[0mArre yaar jo Trainer 1 ne pehle he le liya wo ab aap nhi le paoge meri jaan. Please koi doosra pokemon chuno." << endl ; //error for choosing the same pokemon as trainer 1
            }
             else if (t2Input == 1) //trainer 2 choosing his/her pokemon
            {
                t2Pokemon = Bulbasaur ;
                trainer2 = new BulbasaurKiClass ;
            }
            else if (t2Input == 2)
            {
                t2Pokemon = Pikachu ;
                trainer2 = new PikachuKiClass ;
            }
            else if (t2Input == 3)
            {
                t2Pokemon = Charizard ;
                trainer2 = new CharizardKiClass ;
            }
           
        } while (t2Input > 3 || t2Input <= 0 || t1Input == t2Input) ;

 
        cout << endl ;
        AbAgleKiBaari() ;//trainer 1 starts the game
        cout << "\033[0mChalo ready ho jao! Trainer 1, pehle tumhari baari!" << endl << endl ; ;

        do
        {
            cout << "\033[0mTrainer 1: D daba damage dene k liye or ya H apne aap ko heal karne k liye." << endl ; //trainer 1 choosing their input for either heal or damage
            cin >> tInput ;
            TrainerAction(trainer1, trainer2) ;
            AbAgleKiBaari() ;
            cout << endl ;
            if (trainer1->Health <= 0 || trainer2->Health <= 0) break ;
            cout << "\033[0mTrainer 2: D daba damage dene k liye or ya H apne aap ko heal karne k liye." << endl ; //trainer 2 choosing their input for either heal or damage
            cin >> tInput ;
            TrainerAction(trainer2, trainer1) ;
            AbAgleKiBaari() ;
            cout << endl ;
            if (trainer1->Health <= 0 || trainer2->Health <= 0) break ; //game end logic
        } while (trainer1->Health > 0 && trainer2->Health > 0) ;

        if (trainer1->Health <= 0)
        { //trainer 2 win condition
            cout << "\033[0mTrainer 1 ka Pokemon mar gaya!" ;
            cout << endl << endl ;
            cout << "\033[0mTrainer 2 Jeet Gaya!" ;
            cout << endl << endl ;
        }
        else if (trainer2->Health <= 0)
        { //trainer 1 win condition
            cout << "\033[0mTrainer 2 ka Pokemon mar gaya!" ;
            cout << endl << endl ;
            cout << "\033[0mTrainer 1 Jeet Gaya!" ;
            cout << endl << endl ;
        }
        cout << "\033[0mS dabao agar doobara khelna chahte ho!" << endl ; //calling restart function
        cin >> restart ;
        cout << endl << endl ;
    } while (restart == 'S') ;
}