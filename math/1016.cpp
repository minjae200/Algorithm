#include <iostream>
using namespace std;

const int numberMAX = 1000000 + 1;
const int prinumMAX = 10000 + 1;
long long numbers[numberMAX];
long long prinum[prinumMAX];
long long maxNumber, minNumber, num;
int prinum_num, count;
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> minNumber >> maxNumber;
    for (long long i = 2; i*i <= maxNumber; i++) {
        long long x = minNumber / (i*i);
        if (minNumber % (i*i) != 0)
            x++;
        while (x*(i*i) <= maxNumber){
            numbers[x*(i*i) - minNumber] = 1;
            x++;
        }
    }
    for (int i = 0; i <= maxNumber - minNumber; i++){
        if (numbers[i] == 0)
            count++;
    }
    cout << count << '\n';
    return 0;
}