#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>
//CBIF - Console Based: Interface Framework, A Story based with extra functions framework for console based interfaces.
namespace cbif { 
    using namespace std;
    //Declaration
    inline map<string, string> memory;

    /*CBIF Definition Helper: CBIF_CLRSCRN()
    --
    The following function is simply to clear the terminal as there is no default
    function to do so; simply use it as normal.

    Requirements:

    N/A (Non requirement function)
    */
    inline void CBIF_CLRSCRN(){
        int endn = 100; 
        for (int i = 0; i<endn;i++){
        cout<<"\n";
        }
    }

    /*CBIF Definition Helper: CBIF_textbox()
    --
    The following function is to provide a textbox with a wrapping function
    and a style. It has a name and a dialogue but nothing else, a simple textbox.

    Requirements:

    string& name -- text between the brackets.
    string& dialogue -- text that wraps and is free form.
    
    Extra Notes:

    Typing '@' will act as a \n / endl.
    you can change the scn to ask how many spaces before it line ends
    */
    void CBIF_textbox(string& name, string& dialogue){
    int sc = 0; int scn = 20;
    cout<<'['<<name<<']'<<"\n";int tbdiv = 60;
    for (int i = 0; i<tbdiv;i++){cout<<'=';} cout<<"\n"<<"[:] ";
        for (int i = 0;i<dialogue.length();i++){cout<<dialogue[i];
        if (dialogue[i] == ' '){sc++;} if (sc == scn){cout<<"\n[:] ";sc=0;}
        if (dialogue[i] == '@'){cout<<"\n"; continue;}
        }
        cout<<"\n";
    }

    /*CBIF Definition Helper
    --
    This function is a little harder.
    Simply checks if the value of point is what its specified number is and will output
    a textbox alongside clearing the screen.

    Requirements:

    int& numberspecified -- what the number must be for this function to trigger
    int& point -- checking the number / input
    string& choicednm -- name for the choice textbox
    string& choicedtb -- dialogue for the choiced textbox

    Notes:

    the point is a predefined, it must be defined then redefined by CBIF_choice
    the point must be different for each interaction
    */
    inline void CBIF_choice(int numberspecified, int&point, string choicednm, string choicedtb){
        if (point == numberspecified){CBIF_CLRSCRN(); CBIF_textbox(choicednm, choicedtb); }
    }

    /*CBIF Definition Helper
    --
    This function simply changes the point, with a specified min and maximum number.
    it also provides an input requirement that's number based ... I dont know what will happen if you
    put letters... dont try that please.

    Requirements:

    int& point -- same point as CBIF choice
    int min -- minimum number
    int max -- maximum number

    Notes:

    use 404 to exit the program.
    re requests for input
    */
    inline void CBIF_getinput(int& point, int min, int max){
        cout<<"\n[!]";cout<<" INPUT:"; int inp; cin>>point;
        if (point == 404404){exit(0);} if (point > max || point < min)
        {cout<<"\n"<<"INVALID POINT; USE NUMS BTWN:"<<min<<'-'<<max;cin.clear();CBIF_getinput(point,min,max);}
    }

    /*CBIF Definition Helper
    --
    A simple console output, outputs the numberspecified and the text.

    Requirements:

    int& numberspecified -- the number that'll show between the brackets
    string& text -- the text that'll show as the choice
    */
    inline void CBIF_showchoice(int numberspecified, string text){
        cout<<'['<<numberspecified<<']';cout<<text<<"\n";
    }

    /*CBIF Definition Helper
    --
    too lazy to type this.. just ask me ill know... :c

    randomizes with the point value + max + min

    remember that index starts with 0, always.
    */
    inline void CBIF_Ext_randomchoice(int& point, int max, int shiftmax){
        srand(time(0)); point = rand() % max + shiftmax;
    }

    /*CBIF Definition Helper
    --
    too lazy to type this.. just ask me... again... :(

    averages out an array, input is predefined, the size is the size of the array, also predefined
    totald is the total, predefined too
    */
    void CBIF_Ext_average(int array[], int size, int& totald){
        int total = 0;
        for (int i = 0; i<size; i++){total+=array[i];}
        totald = total/size;
    }

    /*CBIF Definition Helper
    --
    too lazy to define, either way its not much q.q

    provides a small little console output, saying the endtext besde the XXX and the shutdown message before
    requesting user input then exiting

    prob useful for ending of paths
    */
    void CBIF_EndText(string endtext, string sdmsg){
        string goodbye; CBIF_CLRSCRN();
        cout<<"[XXX]"<<endtext<<"\n";
        cout<<sdmsg;cin.ignore();
        exit(0);
    }

    /*No helper, just type whatever you'd like*/
    inline void CBIF_NAMovement(string text){
        cout << "\n" << text << "\n(Press Enter to continue...)";
        cin.ignore();
        cin.get();
    }
}