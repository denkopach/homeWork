#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    const char SAND = '.'; //a symbol of sand

    int count = 0; //counter of possible base locations
    int nBase, mBase; //base dimensions
    int nPlace, mPlace; //place dimensions

    ifstream input("input.txt");
    if (!input.is_open()){
        cout << "The file can not be opened!\n";
        return 0;
    }

    //read from the file the size of the base
    input >> nBase;
    input >> mBase;

    //create array with plan base
    char base[nBase][mBase];
    for(int i = 0; i < nBase; i ++){
        input >> base[i];
    }

    //read from the file the size of the place
    input >> nPlace;
    input >> mPlace;

    //create array with plan place
    char place[nPlace][mPlace];
    for(int i = 0; i < nPlace; i ++){
        input >> place[i];
    }

    input.close();

    //find base location
    for(int i = 0; i <= nPlace - nBase; i++){
        for(int j = 0; j <= mPlace - mBase; j++){
            if (base[0][0] == place[i][j] || base[0][0] == SAND){
                bool isTrue = true;
                for(int x = 0; x < nBase && isTrue; x++){
                    for(int y = 0; y < mBase; y++){
                        isTrue = false;
                        if (base[x][y] != place[i+x][j+y] && base[x][y] != SAND){
                            break;
                        }
                        else if(y == mBase-1){
                            isTrue = true;
                        }
                    }
                }
                if (isTrue ){
                    count++;
                }
            }
        }
    }

    ofstream output("output.txt", ios_base::out | ios_base::trunc);
    output << count;
    output.close();

    //derivation of possible base locations
    cout<<"count = "<<count<<endl;

    return 0;
}
