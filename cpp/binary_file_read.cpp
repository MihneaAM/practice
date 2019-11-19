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

    fstream b_file (argv[1], ios::binary | ios::in);

    b_file.seekg (0, ios_base::beg);

    b_file.read (reinterpret_cast<char *> (&rec.age), sizeof (rec.age));
    b_file.read (reinterpret_cast<char *> (&rec.score), sizeof (rec.score));
    b_file.read (reinterpret_cast<char *> (&len), sizeof (len));

    char *p_str = new char[len + 1];
    b_file.read (p_str, len + 1);
    rec.name = string(p_str);
    delete p_str;

    cout << rec.age << endl;
    cout << rec.score << endl;
    cout << rec.name << endl;
}
