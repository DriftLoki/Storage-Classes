/*
Storage class specifiers: auto, register, extern, static
- the indentifier's storage class determines duration, scope and linkage
-duration is the time it exists in memory
-scope where it can be referenced in a program
-linkage determines for a muliutple-source-file program

automatic storgae duration = variables are created when the block they're in is entered(exist when block is active)
local variables = automatic storgae duration by default (automatic variables)

static storage start when program starts(exist through out the entire execution)
*/

#include<stdio.h>

void useLocal(void);  //prototypes
void useStaticLocal(void);
void useGlobal(void);

int x = 1; //global varialbe

int main(void){
    int x = 5; //local variable in main
    printf("local x in outer scope of main is %d\n", x);

    { //new scope
        int x = 7; //new scope local variable
        printf("local x in inner scope of main is %d\n", x);
    }

    printf("local x in outer scope of main is %d\n", x);

    useLocal();  //autmoatic local (calls function which prints 25 then 26)
    useStaticLocal();  //static local (calls function which prints 50 then 51)
    useGlobal();  //global ()
    useLocal();  //reinitializes automatic local
    useStaticLocal();  //retains prior value
    useGlobal();  //retains prior value

    printf("\nlocal x in main is %d\n", x);
}

void useLocal(void){  //reinitializes x during each call so prints 25 26 then 25 26
    int x = 25;  //initialized eaxh time useLocal is called

    printf("\nlocal x in useLocal is %d after entering useLocal\n", x);
    ++x;
    printf("local x in useLocal is %d before exiting useLocal\n", x);
}

void useStaticLocal(void){  //Only initializes once so prints 50 51 then 51 52
    static int x = 50;  //initialized once

    printf("\nlocal static x is %d on entering useStaticLocal\n", x);
    ++x;
    printf("local static x is %d on exiting useStaticLocal\n", x);
}

void useGlobal(void){
    printf("\nglobal x is %d on entering useGlobal\n", x);
    x *=10;
    printf("global x is %d on exiting useGlobal\n", x);
}


/*
FINAL CONCLUSIONS

-useLocal (uses local vairalbes inside of itself and reinitializes each variable every time its called apon)
USAGE
    void useLocal(void);  //define prototype outside of main
    useLocal();  //calling prototype
    void useLocal(void){}  //prototype define

-useStaticLocal (uses local vairalbes inside of itself but it only initializes variables once not each time called apon)
USAGE
    void useStaticLocal(void);  //define prototype outside of main
    useStaticLocal();  //calling prototype
    void useStaticLocal(void){}  //prototype define

-useGlobal (uses global vairalbes that are defined outisde of main and variables are only initialized once not each time called apon)
USAGE
    void useGlobal(void);  //define prototype outside of main
    useGlobal();  //calling prototype
    void useGlobal(void){}  //prototype define
*/