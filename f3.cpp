
#include<fstream>
using namespace std;

int main()
{
    ofstream file("data.txt",ios::app); // Open the file in append mode to add content without overwriting
    file<<"\n benjamin netanyahu loved it"<<endl;
 // file.close(); // No need to explicitly close the file, it will be closed automatically when the ofstream object goes out of scope.
    return 0;
}