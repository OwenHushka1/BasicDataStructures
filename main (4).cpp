#include "addEmployee.hpp"

int main(int argc, char *argv[])
{
    // check for number of arguments
    if (argc < 2)
    {
        cout << "file name missing" << endl;
        return -1;
    }

    string fileName = "employees.csv"; // TODO 1: collect the correct argument
    employee array[4];

    // open the file
    ifstream myfile;
    myfile.open(fileName);

    string line;
    string name;
    string emailid;
    string birthday;
    int length = 0;
    string arr[3];
    int num = 0;
    int numSplits = 0;
    int first = 0;
    int last = 0;

    if (myfile.is_open()) // check existance of the file
    {
        while(getline(myfile, line)){

            if(line.length() > 0){
                for(int i=0; i < line.length(); i++){
                    if(line[i] == ','){

                        arr[numSplits] = line.substr(first, i-1); 
                        numSplits++;
                        first = i + 1; 
                    }
                }
            }
       }


        // TODO 2:  Read each line from the file
        //           for each line do the following
        //               extract name, extract email, exract birthday
        //               call the addAemployee function to add them in the array
        numSplits = 0;
        length = addAnEmployee( array, arr[0], arr[1], arr[2], length);
       
    }
    else
    {
        cout << "err: can not open file" << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << "name:" << array[i].name << " email:" << array[i].email << " bday:" << array[i].birthday << endl;
    }

    return 0;
}