#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main (int argc, char *argv[]) {
    
    int input_no;
    int random_no;

    if (argc > 1) {
        // do nothing
    }
    else {
        cout << "no arguments for " << argv[0] << endl;
    }
    
    srand (time(NULL));
    random_no = rand() % (100 - 1) + 1;

    while (1)
    {
        cin >> input_no;

        if (input_no > random_no)
        {
            cout << "too high" << endl;
        }
        else if (input_no < random_no)
        {
            cout << "too low" << endl;
        }
        else
        {
            cout << "you guessed" << endl;
            break;
        }
    }

    return 0;
}
