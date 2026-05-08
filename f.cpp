#include<fstream>
using namespace std;

int main()
{
    ofstream file("data.txt");
    file<<"Hello, this is a test file."<<endl;
 // file.close(); // No need to explicitly close the file, it will be closed automatically when the ofstream object goes out of scope.
    return 0;
}