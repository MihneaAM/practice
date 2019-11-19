#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "binary_file.h"

int main (int argc, char *argv[]) {

    PlayerRecord rec;
    int len;

    if (argc != 2)
    {
        cout << "use " << argv[0] << " <filename>" << endl;
        return 0;
    }
    
    rec.age = 11;
    rec.score = 200;
    rec.name = "Popescu";

    fstream b_file (argv[1], ios::trunc | ios::binary | ios::in | ios::out);

    b_file.write (reinterpret_cast<char *> (&rec.age), sizeof (rec.age));
    b_file.write (reinterpret_cast<char *> (&rec.score), sizeof (rec.score));

    len = rec.name.length();

    b_file.write (reinterpret_cast<char *> (&len), sizeof (len));
    b_file.write (rec.name.c_str(), len + 1);

}
