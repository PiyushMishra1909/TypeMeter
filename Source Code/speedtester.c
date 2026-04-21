// In this program i build a beginner level typing speed tester yea that's it xd lol

// ---   header   ---
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
HANDLE console;

#define MAX_LENGTH 1000 // sample_para ko store karne k liye
#define MAX_INPUT 500   // user_para ko store karne k liye
#define MAX_PARA 3

//---------------COLOR CODES---------------------

// SetConsoleTextAttribute(console, 7)  ;  WHITE
// SetConsoleTextAttribute(console,11)  ;  CYAN
// SetConsoleTextAttribute(console,14)  ;  YELLOW
// SetConsoleTextAttribute(console, 12) ;  RED
// SetConsoleTextAttribute(console, 10) ;  GREEN

char Sample_para[MAX_LENGTH];
char user_para[MAX_INPUT];
char paragraphs[3][3][MAX_LENGTH];

void user_instruction() // It will show user some basic instructions
{

    // printf("\n=======  WELCOME TO TYPEMETER  =======\n");

    printf("\n");
    printf("W   W  EEEEE  L      CCCCC  OOOOO  M   M  EEEEE\n");
    printf("W   W  E      L      C      O   O  MM MM  E    \n");
    printf("W W W  EEEE   L      C      O   O  M M M  EEEE \n");
    printf("WW WW  E      L      C      O   O  M   M  E    \n");
    printf("W   W  EEEEE  LLLLL  CCCCC  OOOOO  M   M  EEEEE\n");

    printf("\n");

    printf("TTTTT  OOOOO     TTTTT  Y   Y  PPPP   EEEEE  M   M  EEEEE  TTTTT  EEEEE  RRRR\n");
    printf("  T    O   O       T     Y Y   P   P  E      MM MM  E        T    E      R   R\n");
    printf("  T    O   O       T      Y    PPPP   EEEE   M M M  EEEE     T    EEEE   RRRR \n");
    printf("  T    O   O       T      Y    P      E      M   M  E        T    E      R  R \n");
    printf("  T    OOOOO       T      Y    P      EEEEE  M   M  EEEEE    T    EEEEE  R   R\n");
    printf("\n");

    printf("\n----------     USER INSTRUCTIONS     -----------\n");

    printf("\n>> A sample paragraph will be shown\n");
    printf(">> When you start writing the timer will start.\n");
    printf(">> Press Enter when finished to stop timer.\n");
    printf(">> Your typing speed and accuracy will be calculated.\n");
}

void difficulty()
{
    int choice;

    printf("\nSelect difficulty\n");

    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");

    printf("\nChoose difficulty : ");

    scanf("%d", &choice);
    while (getchar() != '\n')
        ; // removes scanf buffer

    while (choice < 1 || choice > 3)
    {
        printf("Invalid! Enter again (1-3) : ");
        scanf("%d", &choice);
        while (getchar() != '\n')
            ;
    }

    strcpy(paragraphs[0][0], "i like to eat food and drink water i go to school every day i read books and write words my mom cooks rice and my dad drinks tea we have a small cat at home it is white and soft i love my family");

    strcpy(paragraphs[0][1], "the boy kicked the ball the girl drew a red flower the bus stopped at the gate we sat under a big tree and ate our lunch the shop had toys books and pens i bought a blue pen and went back home");

    strcpy(paragraphs[0][2], "the cat sat on the mat the dog ran in the park the bird sang in the tree the sun is bright and the sky is blue the fish swim in the pond and the kids play in the yard life is good and fun");

    strcpy(paragraphs[1][0], "Learning to type faster requires daily practice and focus. Proper finger placement on the keyboard helps improve both speed and accuracy. Many typists aim for at least sixty words per minute to be considered proficient. With patience and consistent effort, anyone can become a skilled typist over time.");

    strcpy(paragraphs[1][1], "The internet has changed the way people communicate and share information. Social media platforms allow users to connect with friends and family across the world. However, it is important to use technology responsibly and be aware of online privacy. Spending too much time on screens can affect both mental and physical health.");

    strcpy(paragraphs[1][2], "Exercise plays a vital role in maintaining a healthy lifestyle. Even a thirty minute walk each day can significantly improve your mood and energy levels. Drinking enough water and eating balanced meals are equally important habits to develop. Small changes in daily routine can lead to major improvements in overall well being.");

    strcpy(paragraphs[2][0], "The quintessential challenge of high-velocity typing lies not merely in dexterity, but in sustaining cognitive synchronization between lexical recognition and motor execution. Proficient typists subconsciously leverage muscle memory, allowing their fingers to traverse the keyboard with minimal conscious deliberation, achieving extraordinary precision even under considerable psychological pressure.");

    strcpy(paragraphs[2][1], "Epistemological frameworks that underpin contemporary scientific methodology have evolved considerably since the Enlightenment era. Philosophers such as Kant and Hegel fundamentally restructured our understanding of perception, knowledge, and objective reality. The reconciliation of empirical observation with theoretical abstraction remains a formidable intellectual pursuit that continues to challenge researchers across disciplines.");

    strcpy(paragraphs[2][2], "Cryptographic algorithms form the foundational infrastructure of modern cybersecurity, employing sophisticated mathematical transformations to safeguard sensitive transmissions against unauthorized interception. Asymmetric encryption protocols, particularly RSA and elliptic-curve cryptography, exploit computational asymmetry to render brute-force decryption virtually infeasible, thereby ensuring confidentiality, integrity, and authenticity across distributed networks.");

    int index = rand() % 3;
    strcpy(Sample_para, paragraphs[choice - 1][index]);
}

void start()
{

    printf("\n");

    // This loop will print Enter statement with a blinking animation
    while (1)
    {

        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(console, 11);

        printf("\rPress any key to start : "); // \r it prints the same line from the start

        SetConsoleTextAttribute(console, 7);

        fflush(stdout); // fflush removes the current output buffer
        Sleep(500);     // sleep will give us time gap

        printf("\r                         "); // match the exceed length
        fflush(stdout);
        Sleep(500);

        printf("\r");

        if (
            _kbhit())
        {
            _getch(); // consume the key pressed

            printf("\n----------   START   ----------\n");
            printf("\n");

            break;
        }
    }
}

void user_input(char user_para[], int size) // this will take user input and store it in user_para[]
{

    fgets(user_para, size, stdin);
    user_para[strcspn(user_para, "\n")] = '\0';
}

void grade(float wpm, double accuracy)
{

    if (wpm >= 80 && accuracy >= 95)
    {
        SetConsoleTextAttribute(console, 11);
        printf("Grade : S - Pro Typist!");
        SetConsoleTextAttribute(console, 7);
    }

    else if (wpm >= 60 && accuracy >= 85)
    {
        SetConsoleTextAttribute(console, 10);
        printf("Grade : A - Excellent!");
        SetConsoleTextAttribute(console, 7);
    }

    else if (wpm >= 40 && accuracy >= 75)
    {
        SetConsoleTextAttribute(console, 14);
        printf("Grade : B - Good job!");
        SetConsoleTextAttribute(console, 7);
    }

    else if (wpm >= 20 && accuracy >= 60)
    {
        SetConsoleTextAttribute(console, 7);
        printf("Grade : C - Keep practicing!");
        SetConsoleTextAttribute(console, 7);
    }

    else
    {
        SetConsoleTextAttribute(console, 12);
        printf("Grade : D - Needs improvement!");
        SetConsoleTextAttribute(console, 7);
    }
}

void printResults(double seconds, float wpm, double accuracy, int mistakes, int correct, double no_of_words)
{

    printf("\n----------     YOUR RESULT     ----------\n");

    printf("\nTime taken : %.2lf sec \n", seconds);
    printf("\nYour wpm is : %.2f words per minute\n", wpm);
    printf("\n");
    grade(wpm, accuracy);
    printf("\n");
    printf("\nAccuracy : %.2f%%\n", accuracy);
    printf("\nYou typed : %.0f words\n", no_of_words);
    printf("\nCorrect characters : %d\n", correct);
    printf("\nWrong characters : %d\n", mistakes);
}

int main()
{
    console = GetStdHandle(STD_OUTPUT_HANDLE); // used to get access to console
    SetConsoleTextAttribute(console, 11);      // condole color to cyan

    int user_length;
    int sample_length;
    double accuracy;
    int limit;
    float minutes;
    double no_of_words;
    float wpm;
    int play_again = 1;

    srand(time(NULL));

    while (play_again == 1) // this loop will do everything from start if user press 1 means if he wants to play again
    {
        int correct = 0;
        int mistakes = 0;

        user_instruction();

        difficulty();

        SetConsoleTextAttribute(console, 14); // console color to bright yellow
        printf("\n%s\n", Sample_para);        // will print sample_para acc to chosen difficulty
        SetConsoleTextAttribute(console, 7);  // console color to white

        start();

        time_t start, end;

        time(&start); // timer starts

        user_input(user_para, MAX_LENGTH);

        time(&end); // timer stops

        double seconds = difftime(end, start);

        sample_length = strlen(Sample_para); // stores the length of sample para
        user_length = strlen(user_para);     // stroes the lenth of user para

        //--------------------------------------------
        // this will set the limit so that is user input less data limit shift to less

        if (sample_length < user_length)
        {
            limit = sample_length;
        }

        else
        {
            limit = user_length;
        }

        // limit = (sample_length < user_length) ? sample_length : user_length   (Just learnt this)

        //---------------------------------------------

        printf("\n");

        printf("\n----------   ERROR HIGHLIGHT   ----------\n");

        printf("\n");

        for (int i = 0; i < limit; i++)
        {
            if (Sample_para[i] == user_para[i]) // helps to check accuracy
            {
                correct++;
                SetConsoleTextAttribute(console, 10); // changes console colour to green (FOR CORRECT TEXT)
                printf("%c", Sample_para[i]);
                SetConsoleTextAttribute(console, 7); // changes colour back to white
            }

            else
            {
                mistakes++;
                SetConsoleTextAttribute(console, 12); // changes console colour to red (FOR MISTAKES)
                printf("%c", Sample_para[i]);
                SetConsoleTextAttribute(console, 7); // changes colour back to white
            }
        }
        // ---------------- SHOWS WHATEVER USER DIDN'T TYPE -----------
        if (user_length < sample_length)
        {
            for (int i = user_length; i < sample_length; i++)
            {
                SetConsoleTextAttribute(console, 12); // red color
                printf("%c", Sample_para[i]);
                SetConsoleTextAttribute(console, 7); // white color
            }
        }
        // --------------------------------------------------------------

        // ----------------- SHOWS WHAT EXTRA TYPED ---------------------

        if (user_length > sample_length)
        {
            for (int i = sample_length; i < user_length; i++)
            {
                SetConsoleTextAttribute(console, 14); // yellow color
                printf("%c", user_para[i]);
                SetConsoleTextAttribute(console, 7);
            }
        }

        //----------------------------------------------------------------

        accuracy = ((double)correct / sample_length) * 100;

        if (seconds > 0) // converts seconds to minutes , calculate number of words and calculates wpm .
        {
            minutes = seconds / 60.0;
            no_of_words = user_length / 5.0;
            wpm = no_of_words / minutes;
        }

        else
        {
            printf("\nError !\n");
        }

        printf("\n");

        // NOTE :- DATATYPES SIRF DECLARE KARTE HUE LIKHTE H !!!

        printResults(seconds, wpm, accuracy, mistakes, correct, no_of_words); // this line wil prints all the results

        printf("\nPlay again? (1 = Yes, 0 = No) : ");
        scanf("%d", &play_again);
        while (getchar() != '\n')
            ;
    }

    return 0;
}
