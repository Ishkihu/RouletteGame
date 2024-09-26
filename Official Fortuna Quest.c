#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <ctype.h>
#define BSIZE 1024

FILE *sb;

int money = 0, bet = 0, betnum, betgen, betwon, hour = 12; // Global Variables used Across the program //
int specialtry = 3; // Reserved for TUP's Exclusive Event //
char username[100]; // Characters accepted for usernames //

void WelcomeMessage();
void Instructions();

void MainModes();
void Commoner();
void Scholar();
void Merchant();
void Noble();
void Emperor();
void Scoreboard();
void MiniGame1();
void MiniGame2();





void MainModes() // The Main Menu of the Game, displays the various options of playing the Game Modes //
{
    int gamemode, retry;
    do{
    system("cls");

    if (money <= 0)
    {
        exit_game();
    }

    puts("\n========================================================================================================================");
    puts("\n\t\t\t\t  <•>==========<•> INFORMATION <•>==========<•>"); // Middle Tab //

    printf("\n\t\t\t\t\t  -=[ Player: %s ]=-\n", username); // Displays the playername of the user globally//

    printf("\n\t\t\t\t\t  -=[ Balance: %d Auros ]=-\n", money); // Displays the balance of the user globally//

    puts("\n\t\t\t\t  <•>==========<•> GAMEMODE <•>==========<•>"); // Middle Tab //

    puts("\n\t\t\t-=[ Commoner's Pouch ]=-  [1] [Stakes: 200-750 Auros]      [1.4x Multiplier]"); // First Game Mode //
    puts("\n\t\t\t-=[ Merchant's Bank ]=-   [2] [Stakes: 1250-3000 Auros]    [2.0x Multiplier]"); // Second Game Mode //
    puts("\n\t\t\t-=[ Noble's Casino ]=-    [3] [Stakes: 7000-15000 Auros]   [2.5x Multiplier]"); // Third Game Mode //
    puts("\n\t\t\t-=[ Emperor's Chalice ]=- [4] [Stakes: 45000-100000 Auros] [3.0x Multiplier]"); // Fourth Game Mode //

    puts("\n\t\t\t\t  <•>==========<•> SPECIAL EVENT <•>==========<•>"); // TUP SPECIAL EVENT //

    printf("\n\t\t\t-=[ Scholar's Academy ]=- [5] [Reward: Auros] [Tries: %d]", specialtry); // TUP's Exclusive Mode //

    puts("\n\n\t\t\t\t  <•>==========<•> MINIGAME <•>===========<•>"); // Mini Games of the Program //

    printf("\n\t\t\t-=[ A Worker's Day ]=-    [6] [Profit: Varies] [Attempts: %d]", hour); // First Side Game //
    printf("\n\t\t\t-=[ Redlight District ]=- [7] [Profit: Varies] [Attempts: %d]", hour); // Second Side Game //

    puts("\n\n\t\t\t\t  <•>==========<•> MISC <•>===========<•>");

    puts("\n\t\t\t-=[ SCOREBOARD ]=-        [8] [Check History of Won Amount]"); // Displays the History of Prizes Won Globally //
    puts("\n\t\t\t-=[ INSTRUCTION ]=-       [9] [Learn the Mechanics]"); // Gives the brief instructions of the program //
    puts("\n\t\t\t-=[ Exit ]=-              [0] [Exit]"); // Terminates the Program //
    puts("\n========================================================================================================================");

    printf("\n\t\t [>•<] Select Gamemode: "); // Accepts user input //
    scanf("%d", &gamemode); // Stores input //
    switch(gamemode)
    {
        case 1: Commoner(); break; // Directs to Commoner Function //
        case 2: Merchant(); break; // Directs to Merchant Function //
        case 3: Noble(); break; // Directs to Noble Function //
        case 4: Emperor(); break; // Directs to Emperor Function //
        case 5: Scholar(); break; // Directs to Scholar Function //
        case 6: if (hour <= 0) {
                printf("\n\t\t Hours have reached 0. You cannot access this mode.\n");
                getch();
                MainModes();
                } else
                {
                MiniGame1();
                }
                break;
        case 7: if (hour <= 0) {
                printf("\n\t\t Hours have reached 0. You cannot access this mode.\n");
                getch();
                MainModes();
                } else
                {
                MiniGame2();
                }
                break;
        case 8: Scoreboard(); break; // Directs to Scoreboard Function //
        case 9: Instructions(); break; // Directs to Instructions Function //
        case 0: exit_game(); break; // Directs to Exit Function //
        default: printf("\n\t\t\t\t Entered value isn't available in the selection.");
    }
    // Lines of Code below is used every time a function has ended [START] //
    printf("\n\n\t\t-=- [•] Detecting Completion of Gamemode [•] -=- Return? (Y/N)");
    retry = getch();
    if (retry == 'n' || retry == 'N')
    {
        exit_game();
    }
    }while(retry == 'y' || retry == 'Y');
    // Lines of Code below is used every time a function has ended [END] //
}






void Commoner() // Commoner Function Game Mode //
{
    system("cls");

    FILE *sb;
    sb = fopen("Scoreboard.txt", "a");

    if (money <= 199)
    {
        puts("\n========================================================================================================================");
        printf("\n\t\t BARKEEP: Oh lad, sorry to tell ya but you lack some good ol' cash\n");
        getch();
        printf("\n\t\t %s: That's unfortunate, I'll earn some pocket money for now then I'll come back.\n", username);
        getch();
        printf("\n\t\t BARKEEP: Now that's the spirit! Good luck on your endeavors.\n");
        puts("\n========================================================================================================================");
        getch();
        fclose(sb);
        return;
    }

    srand(time(NULL));

    // Lore/Plot of the Program

    puts("\n========================================================================================================================");

    puts("\n\t\t\t\t  <•>==========<•> COMMONER LORE <•>==========<•>");
    puts("\n\t\tBorn with the lowest standing in the hierarchy, but essential in society's structure.");
    puts("\n\t\tChoosing this mode, you find yourself in a rather shabby but well-maintained bar.");
    puts("\n\t\tAs you walk through this establishment you set your sights on a betting machine.");
    puts("\n\t\tWhile tattered in some parts, the machine works relatively well.");
    puts("\n\t\tAs you get closer, this is where you start your journey \n\n\t\trising through the ranks of materialistic wealth.");

    puts("\n========================================================================================================================");

    printf("\n\t\t\t\tPress [Enter] to Continue . . .");
    getch();
    system("cls");

    puts("\n========================================================================================================================");

    puts("\n\t\t\t\t  <•>==========<•> COMMONER LORE <•>==========<•>");
    puts("\n\t\tClearing yourself of daydreams, you approach the bartender of the place.");
    puts("\n\t\tThough seeing the machine gave you momentary temptation, you still needed a drink.");
    puts("\n\t\tAs you get closer you see the Bartender doing the cliché of cleaning the cups.");
    puts("\n\t\tThough you wonder how you clean wooden cups with a flimsy towel.");
    puts("\n\t\tYou ask if it's okay to bet on the machine, and he replied.....");

    puts("\n========================================================================================================================");

    int betnum, bet;
    while (1)
    {
        printf("\n\t\t<BARKEEP>: Which number would you like to bet on, lad? [1-5]: ");
        if (scanf("%d", &betnum) != 1)
        {
            printf("\n\t\t<BARKEEP>: Invalid input. Please enter a valid bet number.\n");
            fflush(stdin);
            continue;
        }
        if (betnum >= 1 && betnum <= 5)
        {
            break;
        }
        printf("\n\t\t<BARKEEP>: Lad, are you reading the instructions correctly?\n");
    }

    while (1)
    {
        printf("\n\t\t<BARKEEP>: Drop the amount you wish to bet [Min = 200 | Max = 750]: ");
        if (scanf("%d", &bet) != 1)
        {
            printf("\n\t\t<BARKEEP>: Invalid input. Please enter a valid bet amount.\n");
            fflush(stdin);
            continue;
        }
        if (bet >= 200 && bet <= 750 && bet <= money)
        {
            break;
        }
        printf("\n\t\t<BARKEEP>: Laddy, 200-750's the limit, you got reading problems? [ 200 - 750 ] \n");
    }

    int winProb = 60;
    int loseProb = 40;

    int totalProb = winProb + loseProb;
    int randNum = rand() % totalProb;

    int betgen;
    double betwon;

    if (randNum < winProb)
    {
        betgen = betnum;
    }
    else
    {
        do
        {
            betgen = rand() % 5 + 1;
        } while (betgen == betnum);
    }

    if (betgen == betnum)
    {
        betwon = bet * 1.4;
        printf("\n\t\t<BARKEEP>: Congrats lad, you earned %.2f Auros", betwon);
        fprintf(sb, "\n\n\t\t %.2f Auros [Commoner]", betwon);
        money += betwon;
    }
    else
    {
        printf("\n\t\t<BARKEEP>: Bad luck today eh lad? Too bad you lost -=[-%d Auros]=-", bet);
        money -= bet;
    }

    fclose(sb);
}




void Merchant()// Merchant Function Game Mode //
{
    system("cls");

    FILE *sb;
    sb = fopen("Scoreboard.txt", "a");

    if (money <= 1249)
    {
        puts("\n========================================================================================================================");
        printf("\n\t\t ATTENDANT: Dear Guest, you currently lack the funds to engage in the activities here\n");
        getch();
        printf("\n\t\t %s: I see, well I will return when I have obtained sufficient funds.\n", username);
        getch();
        printf("\n\t\t ATTENDANT: Duly noted, please come back to play once again our dear guest.\n");
        puts("\n========================================================================================================================");
        getch();
        fclose(sb);
        return;
    }

    srand(time(NULL));

    // Lore/Plot of the Program

    puts("\n========================================================================================================================");

    puts("\n\t\t\t\t  <•>==========<•> MERCHANT LORE <•>==========<•>");
    puts("\n\t\tGaining some funds to run a business, you compel yourself to chart new heights.");
    puts("\n\t\tChoosing this mode, you find yourself in a well maintained and furnished casino.");
    puts("\n\t\tAs you walk through this establishment you relish at the wealth of those included here.");
    puts("\n\t\tGarnering some attention due to being a newcomer, you strode forward to achieve your goals.");

    puts("\n========================================================================================================================");

    printf("\n\t\t\t\tPress [Enter] to Continue . . .");
    getch();
    system("cls");

    puts("\n========================================================================================================================");

    puts("\n\t\t\t\t  <•>==========<•> MERCHANT LORE <•>==========<•>");
    puts("\n\t\tTo be fair, being in this environment is challenging due to sudden shift of environment");
    puts("\n\t\tHowever, those who emerged victorious from this trials are more likely to succeed.");
    puts("\n\t\tHonestly you don't have a choice, it's your decision to come here.");
    puts("\n\t\tWhile having an internal monologue, you approach a table and you converse with the dealer....");

    puts("\n========================================================================================================================");

    int betnum, bet;
    while (1)
    {
        printf("\n\t\t<ATTENDANT>: Dear Guest, please choose among the numbers to bet on [1-10]: ");
        if (scanf("%d", &betnum) != 1)
        {
            printf("\n\t\t<ATTENDANT>: Invalid input. Please enter a valid bet number.\n");
            fflush(stdin);
            continue;
        }
        if (betnum >= 1 && betnum <= 10)
        {
            break;
        }
        printf("\n\t\t<ATTENDANT>: Sorry to inform you, but please understand the instructions first before playing.");
    }

    while (1)
    {
        printf("\n\t\t<ATTENDANT>: Indicate the amount you wish to bet [Min = 1250 | Max = 3000]: ");
        if (scanf("%d", &bet) != 1)
        {
            printf("\n\t\t<ATTENDANT>: Invalid input. Please enter a valid bet amount.\n");
            fflush(stdin);
            continue;
        }
        if (bet >= 1250 && bet <= 3000 && bet <= money)
        {
            break;
        }
        printf("\n\t\t<ATTENDANT>: Insufficient Balance or Input Below/Above [ 1250 - 3000] \n");
    }

    int winProb = 55;
    int loseProb = 45;

    int totalProb = winProb + loseProb;
    int randNum = rand() % totalProb;

    int betgen;
    double betwon;

    if (randNum < winProb)
    {
        betgen = betnum;
    }
    else
    {
        do
        {
            betgen = rand() % 10 + 1;
        } while (betgen == betnum);
    }

    if (betgen == betnum)
    {
        betwon = bet * 2;
        printf("\n\t\t<ATTENDANT>: Congrats Dear Guest, you earned %.2f Auros", betwon);
        fprintf(sb, "\n\n\t\t %.2f Auros [Merchant]", betwon);
        money += betwon;
    }
    else
    {
        printf("\n\t\t<ATTENDANT>: It seems your luck is dry Dear Guest, you lost -=[-%d Auros]=-", bet);
        money -= bet;
    }

    fclose(sb);
}




void Noble() // Noble Function Game Mode //
{
    system("cls");

    FILE *sb;
    sb = fopen("Scoreboard.txt", "a");

    if (money <= 6999)
    {
        puts("\n========================================================================================================================");
        printf("\n\t\t Butler: Esteemed One, you currently lack the funds to engage in the activities here\n");
        getch();
        printf("\n\t\t %s: I'll return when I acquired some funds.\n", username);
        getch();
        printf("\n\t\t Butler: Duly noted, do come back to play once again our esteemed guest.\n");
        puts("\n========================================================================================================================");
        getch();
        fclose(sb);
        MainModes();
    }

    srand(time(NULL));

    // Starting from here is the Lore/Plot of the Program [START] //

    puts("\n========================================================================================================================");

    puts("\n\t\t\t\t  <•>==========<•> NOBLE LORE <•>==========<•>");
    puts("\n\t\tFrom rags to riches, you have managed to overcome the hardships that stood in your path to prosperity.");
    puts("\n\t\tWith incredible skill and luck you ascended to being one of the elites but that is not enough.");
    puts("\n\t\tChoosing this mode, embodying the will to pursue greatness, you venture into the illustrious Noble's Casino. ");
    puts("\n\t\tThe casino's interior filled with grandeur and gold allures ");
    puts("\n\t\tyou to come and play in one of their meticulously crafted gaming tables.");

    puts("\n========================================================================================================================");

    printf("\n\t\t\t\tPress [Enter] to continue . . .");
    getch();
    system("cls");

    puts("\n========================================================================================================================");

    puts("\n\t\t\t\t  <•>==========<•> NOBLE LORE <•>==========<•>");
    puts("\n\t\tRight now in the palm of your hand lies your success now how much of it will you gamble? ");
    puts("\n\t\tit is not only just a matter of chance anymore this is now a testament to your skill and strategy,");
    puts("\n\t\tpromising rewards as boundless as your ambition awaits. You strode to the dealer to start ....");

    puts("\n========================================================================================================================");

    int betnum, bet;
    while (1)
    {
        printf("\n\t\t<Butler>: Esteemed One, please choose among the numbers to bet on [1-15]: ");
        if (scanf("%d", &betnum) != 1)
        {
            printf("\n\t\t<Butler>: Invalid input. Please enter a valid bet number.\n");
            fflush(stdin);
            continue;
        }
        if (betnum >= 1 && betnum <= 15)
        {
            break;
        }
        printf("\n\t\t<Butler>: Sorry to inform you, but please understand the instructions first before playing.");
    }

    while (1)
    {
        printf("\n\t\t<Butler>: Indicate the amount you wish to bet [Min = 7000 / Max = 15000]: ");
        if (scanf("%d", &bet) != 1)
        {
            printf("\n\t\t<Butler>: Invalid input. Please enter a valid bet amount.\n");
            fflush(stdin);
            continue;
        }
        if (bet >= 7000 && bet <= 15000 && bet <= money)
        {
            break;
        }
        printf("\n\t\t<Butler>: Insufficient Balance or Input Below/Above [0, 7000 / 15000] \n");
    }

    int winProb = 50;
    int loseProb = 50;

    int totalProb = winProb + loseProb;
    int randNum = rand() % totalProb;

    int betgen;
    double betwon;

    if (randNum < winProb)
    {
        betgen = betnum;
    }
    else
    {
        do
        {
            betgen = rand() % 15 + 1;
        } while (betgen == betnum);
    }

    if (betgen == betnum)
    {
        betwon = bet * 2.5;
        printf("\n\t\t<Butler>: Congrats Esteemed One, you earned %.2f Auros", betwon);
        fprintf(sb, "\n\n\t\t %.2f Auros [Noble]", betwon);
        money += betwon;
    }
    else
    {
        printf("\n\t\t<Butler>: It seems your luck is dry Esteemed One, you lost -=[-%d Auros]=-", bet);
        money -= bet;
    }

    fclose(sb);
}


void Emperor() // Emperor Game Function //
{
    system("cls");

    FILE *sb;
    sb = fopen("Scoreboard.txt", "a");

    if (money <= 44999)
    {
        puts("\n========================================================================================================================");
        printf("\n\t\t Minister: My Lord, you currently lack the funds to engage in the activities.\n");
        getch();
        printf("\n\t\t %s: I'll return when I acquired some funds.\n", username);
        getch();
        printf("\n\t\t Minister: As you command, do come back to play once again my lord.\n");
        puts("\n========================================================================================================================");
        getch();
        fclose(sb);
        MainModes();
    }

    srand(time(NULL));

    // Starting from here is the Lore/Plot of the Program [START] //

    puts("\n========================================================================================================================");

    puts("\n\t\t\t\t  <•>==========<•> EMPEROR LORE <•>==========<•>");
    puts("\n\t\tThe Pinnacle of Power, where countless subjects are under your rule.");
    puts("\n\t\tChoosing this mode, you find yourself in an luxurious hall filled with gold and wealth.");
    puts("\n\t\tAs you walk through this establishment you relish at the kneeled image of those beneath you.");
    puts("\n\t\tGarnering some attention due to your status, you walk with pride.");

    puts("\n========================================================================================================================");

    printf("\n\t\t\t\tPress [Enter] to continue . . .");
    getch();
    system("cls");

    puts("\n========================================================================================================================");

    puts("\n\t\t\t\t  <•>==========<•> EMPEROR LORE <•>==========<•>");
    puts("\n\t\tEven with the mightiest influence and power in the whole kingdom, you still didn't throw away");
    puts("\n\t\tYour love for gambling, many would say it's a bad habit, but to you who bears the weight of the strong.");
    puts("\n\t\tYou disregard the useless notion of those beneath you, you strode with dignity and find a well lit table.");
    puts("\n\t\tThe table is designed with the finest materials, ranging from refined ores and oak of the sacred tree.");
    puts("\n\t\tSeeing your nigh-infinite wealth, you approach the dealer who's reputation preceeds him.");
    puts("\n\t\tAwe-inspiring dexterity with cards, you command him to shuffle and start the game....");

    puts("\n========================================================================================================================");

    int betnum, bet;
    while (1)
    {
        printf("\n\t\t<Minister>: My Lord, please choose among the numbers to bet on [1-20]: ");
        if (scanf("%d", &betnum) != 1)
        {
            printf("\n\t\t<Minister>: Invalid input. Please enter a valid bet number.\n");
            fflush(stdin);
            continue;
        }
        if (betnum >= 1 && betnum <= 20)
        {
            break;
        }
        printf("\n\t\t<Minister>: Sorry to inform you, but please understand the instructions first before playing.");
    }

    while (1)
    {
        printf("\n\t\t<Minister>: Indicate the amount you wish to bet [Min = 45000 | Max = 100000]: ");
        if (scanf("%d", &bet) != 1)
        {
            printf("\n\t\t<Minister>: Invalid input. Please enter a valid bet amount.\n");
            fflush(stdin);
            continue;
        }
        if (bet >= 45000 && bet <= 100000 && bet <= money)
        {
            break;
        }
        printf("\n\t\t<Minister>: Insufficient Balance or Input Below/Above [0, 4999 / 15000] \n");
    }

    int winProb = 30;
    int loseProb = 70;

    int totalProb = winProb + loseProb;
    int randNum = rand() % totalProb;

    int betgen;
    double betwon;

    if (randNum < winProb)
    {
        betgen = betnum;
    }
    else
    {
        do
        {
            betgen = rand() % 20 + 1;
        } while (betgen == betnum);
    }

    if (betgen == betnum)
    {
        betwon = bet * 3;
        printf("\n\t\t<Minister>: Congrats My Lord, you earned %.2f Auros", betwon);
        fprintf(sb, "\n\n\t\t %.2f Auros [Emperor]", betwon);
        money += betwon;
    }
    else
    {
        printf("\n\t\t<Minister>: It seems your luck is dry My Lord, you lost -=[-%d Auros]=-", bet);
        money -= bet;
    }

    fclose(sb);
}




void Scholar() // TUP EXCLUSIVE GAME MODE //
{
    if(specialtry <= 0) // If the tries of the user reaches zero(0), they won't be able to enter the gamemode until game termination //
    {
        system("cls");
        puts("\n========================================================================================================================");

        puts("\n\t\t\t\t  <•>==========<•> THE ACADEMIA | NOTIFICATION <•>==========<•>");

        printf("\n\t\t\t<Part-Timer>: You struck out huh, unfortunately it's the last iteration for you.");
        getch();
        printf("\n\t\t\t<%s>: That's too bad, I suppose it went well one way or another.", username);
        getch();
        printf("\n\t\t\t<Part-Timer>: Glad to see you in good spirits! Hope you had fun!.");
        puts("\n\n========================================================================================================================");
        printf("\n\t\t\tPress any key to continue . . .");
        getch();
        specialtry = 0; // Sets the specialtry(tries) variable to zero for display on main menu //
        MainModes();
    }

    sb = fopen("Scoreboard.txt", "a"); // Opens and Appends the lines of code specific for this syntax //

    int moneyRock, guessRock, playAgain, prize = 15000;
    srand(time(NULL));
    char rulistic, starting;
    system("cls");

    // Starting from here is the Lore/Plot of the Program [START] //

    puts("\n========================================================================================================================");

    puts("\n\t\t\t\t  <•>==========<•> THE ACADEMIA <•>==========<•>");
    puts("\n\t\tRegarded as the Greatest Institution of learning, the Technological Univesity of Scholars.");
    puts("\n\t\tChoosing this mode, you find yourself surrounded by the calm gusts of wind.");
    puts("\n\t\tSerene rivers, lakes and trees marking this remarkable landscape.");
    puts("\n\t\tTall imposing structures declaring their dominance and pride.");
    puts("\n\t\tStudents wearing astounding uniforms, indicating their social status.");

    puts("\n========================================================================================================================");

    printf("\n\t\t\t\tPress [Enter] to Continue . . .");
    getch();
    system("cls");

    puts("\n========================================================================================================================");

    puts("\n\t\t\t\t  <•>==========<•> THE ACADEMIA <•>==========<•>");
    puts("\n\t\tMoving forward, you encounter an expansive auditorium filled with various stalls.");
    puts("\n\t\tOne of which has a betting game, though you wonder how the department allows this.");
    puts("\n\t\tEven with a confused mind, you still walked to the betting stall");
    puts("\n\t\tFinding a bespectacled man, manning the stall, you approach him.");
    puts("\n\t\tSeeing you, he waves his hand while calling you out.");

    puts("\n========================================================================================================================");

    printf("\n\t\t\t\tPress [Enter] to Continue");
    getch();
    system("cls");

    // Starting from here is the Lore/Plot of the Program [END] //

    while(1)
    {
        puts("\n========================================================================================================================");
        printf("\n\t\t<Part-Timer>: Heya customer, wanna try out my game? [Yes(Y) / No(N)]: ");

        getchar();

        scanf("%c", &starting);
        if (starting == 'Y' || starting == 'y')
        {
            printf("\n\t\t<%s>: Sure, I ain't got nothing to lose\n", username);
            getch();
            printf("\n\t\t<Part-Timer>: Aight! Let's start.."); break;
        }
        else if(starting == 'N' || starting == 'n')
        {
            printf("\n\t\t<Part-Timer>: That's too bad, you can still try it out next time!");
            getch();
            MainModes(); break;
        }
        else
            printf("\n\t\t<Part-Timer>: You sure you entered a valid input? [Enter Yes(Y) or No(N)");
    }
    getch();

    // Starting from here is the lines of code for the TUP Game Mode//
    // The Game used here is the Rock mode where the user chooses between 3 rocks, if they pick the right one they earn [Auros]//
    specialtry--; // Reduces the tries if the user chooses this mode //
    do{
        system("cls");
        moneyRock = rand() %3+1;

        puts("\n========================================================================================================================");

        puts("\n\t\t\t\t  <•>==========<•> THE ACADEMIA | ROCK GAME <•>==========<•>");
        puts("\n\t\tGood day to you! Welcome to the Rock Game!");
        puts("\n\t\tThe Rules are simple, you pick 1 of the 3 rocks and if you win you earn loads of [Auros]!");
        puts("\n\t\tIf you lose, you still have 3 retries for this session! Pretty neat huh?");

        puts("\n========================================================================================================================");

        printf("\n\t\t\t\t<Part-Timer>: Let's Begin! Choose a rock [1-3]: ");
        scanf("%d", &guessRock);

        while (guessRock < 1 || guessRock > 3){
            printf("\n\t\t\t\t<Part-Timer>: Um, we only have 6 rocks on the table silly. Try again!");
            scanf("%d", &guessRock);
        }

        if(guessRock == moneyRock)
        {
            money = money + prize;
            printf("\n\t\t\t\t<Part-Timer>: Oh snap, Congrats on getting the rock! you earned [%d Auros]", prize);
            fprintf(sb, "\n\n\t\t %d Auros [Scholar Event]", prize);
        }
        else
            printf("\n\t\t\t\t<Part-Timer>: Oof, better luck next time fella!");
            getch();

    }while(playAgain == 'Y');

    fclose(sb);
}




void MiniGame1()
{
    system("cls");

    int shifts, hours, repetition = 0;
    double profit = 0;

    srand(time(0));

    puts("\n========================================================================================================================");

    puts("\n\t\t\t\t  <•>==========<•> WORKER'S MUNDANE LIFE <•>==========<•>");
    puts("\n\t\tSidetracking due to repeated losses in the game, you resort to rebuild your funds slowly.");
    puts("\n\t\tChoosing this mode, you find yourself in a general store where the amount of work done equates to profit.");
    puts("\n\t\tAs you walk through this establishment you motivate yourself in acquiring what you need.");

    puts("\n\t\t-=- [ NOTE ] -=-: You can only work for 3 times in one session.");
    puts("\n\t\t-=- [ NOTE ] -=-: You can only enter a maximum of 5 shifts (hours).");

    puts("\n========================================================================================================================");

    while (repetition < 3)
    {
        printf("\n\t\t<Employer>: How many shifts (hour/s) would you like? [0 = Exit]: ");
        if (scanf("%d", &hours) != 1)
        {
            printf("\n\t\t<Employer>: Invalid input. Please enter a valid number of shifts.\n");
            fflush(stdin);
            continue;
        }

        if (hours == 0)
        {
            break;
        }
        else if (hours < 0)
        {
            printf("\n\t\t<Employer>: Negative values are not accepted. Please enter a valid number of shifts.\n");
            continue;
        }
        else if (hours > 5)
        {
            printf("\n\t\t<Employer>: Hold your horses, we only accept up to 5 shifts (hours).\n");
            continue;
        }

        shifts = rand() % (30 - 25 + 1) + 25;
        profit += (shifts * hours);
        repetition++;

        printf("\n\t\t<Employer>: Nicely done! That's %d hour/s and here's your paycheck! -=- [ %.2f Auros ] -=-\n", hours, profit);
        money += profit;
    }

    if (repetition == 3)
    {
        printf("\n\t\t<System>: Maximum iteration has been reached.\n");
    }

    printf("\n\t\t<Employer>: That's from me for now. Go use that money on something useful!\n");
    hour--;
}



void MiniGame2()
{
    system("cls");
    int shifts, hours, repetition = 0;
    double profit = 0;

    srand(time(0));

    puts("\n========================================================================================================================");

    puts("\n\t\t\t  <•>==========<•> REDLIGHT DISTRICT'S RELENTLESS NIGHTS <•>==========<•>");
    puts("\n\t\tSidetrack due to repeated losses in the game, you resort to rebuild your funds slowly.");
    puts("\n\t\tChoosing this mode, you find yourself in the sleepless nights of the redlight district.");
    puts("\n\t\tFilled with promiscuity of its inhabitants you stroll to find customers to assign them their");
    puts("\n\t\tPurchased services from your establishment.");

    puts("\n\t\t-=- [ NOTE ] -=-: You can only work for 2 times in one session.");
    puts("\n\t\t-=- [ NOTE ] -=-: You can only enter a maximum of 3 shifts (hours).");

    puts("\n========================================================================================================================");

    while (repetition < 2)
    {
        printf("\n\t\t<Oiran>: Manager, how many shifts (hour/s) would you like to take? [0 = Exit]: ");
        if (scanf("%d", &hours) != 1)
        {
            printf("\n\t\t<Oiran>: Invalid input. Please enter a valid number of shifts.\n");
            fflush(stdin);
            continue;
        }

        if (hours == 0)
        {
            break;
        }
        else if (hours < 0)
        {
            printf("\n\t\t<Oiran>: Negative values are not accepted. Please enter a valid number of shifts.\n");
            continue;
        }
        else if (hours > 3)
        {
            printf("\n\t\t<Oiran>: Excuse me Manager, we only accept up to 3 shifts (hours).\n");
            continue;
        }

        shifts = rand() % (40 - 25 + 1) + 25;
        profit += (shifts * hours);
        repetition++;

        printf("\n\t\t<Oiran>: Bless you, %s! That's %d hour/s and here's your paycheck! -=- [ %.2f Auros ] -=-\n", username, hours, profit);
        money += profit;
    }

    if (repetition == 2)
    {
        printf("\n\t\t<System>: Maximum iteration has been reached.\n");
    }

    printf("\n\t\t<Oiran>: That's from me for now. Go use that money on something useful, %s!\n", username);
    hour--;
}












int main()
{
    loading();
    WelcomeMessage();
}

void loading() // Loading Screen //
{
    system("cls");
    system("color E4");
     puts("\n\n\n\n\n\n\n\t\t\t\t====================================================\n");
    printf("\t\t\t\t\t AN ENTERTAINMENT GAME: FORTUNA QUEST \n");
     puts("\n\t\t\t\t====================================================");

    for(int i =1; i<= 120; i++)
    {
        Sleep(5);
        printf("%c", 219);
    }
}

void WelcomeMessage() // Displays the Welcome Message //
{
    system("cls");
    system("color E4");
    printf("\n\t\t\t===========================================================================\n");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############        AN ENTERTAINMENT GAME: FORTUNA QUEST       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t===========================================================================\n");
    printf("\n");
    printf("\n\t\t\t\t ***********************************************************\n");
    printf("\t\t\t\t        ==============================================");
    printf("\n\t\t\t\t        =                                            =");
    printf("\n\t\t\t\t        =                   WELCOME                  =");
    printf("\n\t\t\t\t        =                 TO OUR GAME                =");
    printf("\n\t\t\t\t        =                FORTUNA QUEST               =");
    printf("\n\t\t\t\t        =                                            =");
    printf("\n\t\t\t\t        ==============================================\n");
    printf("\n\t\t\t\t ***********************************************************\n");
    printf("\n\n\n\t Press any key to continue.....");
    getch();
    Intro();
}


void Intro()
{
    system("cls");
    system("color E4");
    int choice;

    puts("\n\n\t\t    [>•<]======================================================================[>•<]");
    puts("\n\t\t\t\t          | * [>•<] * FORTUNA QUEST * [>•<] * |      ");
    puts("\n\t\t    [>•<]======================================================================[>•<]");
    puts("\n\t\t\t\t                | Press [1] to START |");
    puts("\n\t\t\t\t                | Press [0] to LEAVE |");
    puts("\n\t\t          ======================================================================");
    puts("\n\t\t                            |Prepared By: TEAM F - ESQUEJO| ");
    puts("\n\t\t          ======================================================================");

    printf("\n\t\t\t\t\t     Enter your choice: ");

    while (scanf("%d", &choice) != 1) {

        printf("\n\t\t\t\t[SYSTEM] Detecting Errors: Input is Invalid.");
        printf("\n\n\t\t\t\t[SYSTEM] Enter a Number [1 or 0]: ");

        // Clear the input buffer
        while (getchar() != '\n')
            continue;
    }

    switch (choice)
    {
        case 1: Username(); break;
        case 0: exit_game(); break;
        default: Intro(); break;
    }
}



void Username()
{
    system("cls");
    srand(time(NULL));
    puts("\n\t\t\t\t<==================================================>");
    printf("\n\t\t\t\t\t [><] Create Username: ");
    scanf("%s", &username);

    sb = fopen("Scoreboard.txt", "w");
    fprintf(sb,"\n\n\t\tWinnings of [Player: %s]", username);

    fclose(sb);
    StartBal();

}

void StartBal()
{
    int op;
    system("cls");
    puts("\n\t\t\t\t<====================================================>");

    printf("\n\t\t\t\t             Player: -=- | [%s] | -=-", username);

    puts("\n\n\t\t\t\t<====================================================>");

    printf("\n\t\t\t\t To begin your quest for wealth, you need some money.");
    printf("\n\t\t\t\t   The currency of this world is termed as [Auros].");

    puts("\n\n\t\t\t\t<====================================================>");

    printf("\n\t\t\t\t\t[1] Starting balance [500 Auros] [Stable]");
    printf("\n\n\t\t\t\t\t[2] Starting balance [0-750 Auros] [RISKY]");

    puts("\n\n\t\t\t\t<====================================================>\n");

    printf("\n\t\t\t\t\t    [><] Stable or Risky? [><] : ");

    while (scanf("%d", &op) != 1) {

        printf("\n\t\t\t\t[SYSTEM] Detecting Errors: Input is Invalid.");
        printf("\n\n\t\t\t\t[SYSTEM] Enter a Number [1 or 2]: ");

        // Clear the input buffer
        while (getchar() != '\n')
            continue;
    }

    if(op == 1)
    {
        system("cls");
        money += 500;
        printf("\n\n\t\t\t <•>==========<•> Your starting balance is [%d] Auros <•>==========<•>", money);
        getch();
        MainModes();
    }
    else if (op == 2)
    {
        system("cls");
        money = rand()%751;
        printf("\n\n\t\t\t <•>==========<•> Your starting balance is [%d] Auros <•>==========<•>", money);
        getch();
        MainModes();
    }
    else{

        printf("\n\n\t\t\t-[System Error]-: Input not available in the matrix");
        getch();
        StartBal();
    }
}

void Scoreboard()
{
    char buffer[BSIZE];
    FILE *sb = fopen("Scoreboard.txt", "r");
    if (sb == NULL)
    {
        printf("\n\t\t\t[System Error] File is corrupted.\n");
        return;
    }

    system("cls");

    puts("\n========================================================================================================================");
    printf("\n\t\t\t\t<•>==========<•> SCOREBOARD <•>==========<•>");

    while (fgets(buffer, BSIZE, sb) != NULL)
    {
        printf("\t\t\t%s", buffer);
    }

    fclose(sb);

    puts("\n\n========================================================================================================================");
    getch();
}

void Instructions()
{
    system("cls");
    puts("\n========================================================================================================================");

    puts("\n\t\t\t\t<•>==========<•> GAME MODES <•>==========<•>");

    puts("\n\n\t\t\t\t(!) Users can choose among the available [Game Modes].");
    puts("\n\t\t\t\t(?) Commoner: Considered as the average human of Society.");
    puts("\n\t\t\t\t(?) Merchant: Considered as the trade experts of Society.");
    puts("\n\t\t\t\t(?) Noble: Considered as the higher-ups of Society.");
    puts("\n\t\t\t\t(?) Emperor: Considered as the ruling class of Society.");

    puts("\n========================================================================================================================");

    printf("\n\t\t\t\tPress [Enter] to continue . . .");
    getch();
    system("cls");

    puts("\n========================================================================================================================");

    puts("\n\t\t\t\t<•>==========<•> MINI GAMES <•>==========<•>");

    puts("\n\n\t\t\t\t(!) Users can choose among the available [Minigames].");
    puts("\n\t\t\t\t(?) A Worker's Day: Earn money by doing mundane tasks ");
    puts("\n\t\t\t\t(?) The Entertainment District: Considered as the higher-ups of Society.");

    puts("\n========================================================================================================================");

    printf("\n\t\t\t\tPress [Enter] to continue . . .");
    getch();
    system("cls");

    puts("\n========================================================================================================================");

    puts("\n\t\t\t\t<•>==========<•> MERCHANICS <•>==========<•>");

    puts("\n\n\t\t\t\t(?) Users can start the modes by entering numerical inputs.");
    puts("\n\t\t\t\t(?) Stakes and Multipliers varies as the user progresses through the program.");
    puts("\n\t\t\t\t(?) When the users balance reaches zero(0) the game is terminated (Game Over).");
    puts("\n\t\t\t\t(?) Scoreboard is accessible in the Menu section of the program.");

    puts("\n========================================================================================================================");
}



void exit_game()
{
    system("cls");
    puts("\n\t\t\t\t<==================================================>");

    puts("\n\t\t\t\t   It seems you have decided to part. Very Well, \n\t\t\t\t   May you find purpose in your journeys.");

    puts("\n\t\t\t\t<==================================================>");

    printf("\n\t\t\t\t\t=====================================");
    printf("\n\t\t\t\t\t=                                   =");
    printf("\n\t\t\t\t\t=          [ GAME OVER! ]            =");
    printf("\n\t\t\t\t\t=          Thank you for            =");
    printf("\n\t\t\t\t\t=         playing Fortuna           =");
    printf("\n\t\t\t\t\t=              Quest!               =");
    printf("\n\t\t\t\t\t=                                   =");
    printf("\n\t\t\t\t\t=====================================\n\n");
    exit(0);
}
