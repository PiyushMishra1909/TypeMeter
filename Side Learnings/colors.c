#include <stdio.h>
#include <windows.h>

int main()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console,11) ;
    
    printf("HELLO") ;

return 0 ;
}