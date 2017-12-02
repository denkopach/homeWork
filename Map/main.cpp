#include <iostream>

using namespace std;

class Map{
private:
    char* array;
    const int SIZE_ARRAY = 1000000;
public:
    Map(){
        array = new char[SIZE_ARRAY];
    }

    unsigned hashFunc(const char *s){
      unsigned hash;
      (void) ((hash =        toupper(s[0]), s[1]) &&
              (hash = hash*3+toupper(s[1]), s[2]) &&
              (hash = hash*2+toupper(s[2]), s[3]) &&
              (hash = hash*2+toupper(s[3]), s[4]) &&
              (hash = hash*2+toupper(s[4]), s[5]) &&
              (hash = hash*2+toupper(s[5]), s[6]) &&
              (hash = hash*2+toupper(s[6]),
               hash = hash*2+toupper(s[7]))
             );
      return hash;
    }

    void add(char* name, int data){
        array[hashFunc(name)] = data;
    }

    int get(char* name){
        int data = array[hashFunc(name)];
    }
};

int main()
{
    Map map;
    map.add("Vasya", 28);
    map.add("Dima", 18);
    map.add("Igor", 15);
    map.add("Den", 30);
    cout<<map.get("Vasya")<<endl;
    cout<<map.get("Dima")<<endl;
    cout<<map.get("Igor")<<endl;
    cout<<map.get("Den")<<endl;
}
