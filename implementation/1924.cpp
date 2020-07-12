#include <iostream>
#include <string>
using namespace std;

int daysOfMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
string dayOfWeek[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int month, day;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    cin >> month >> day;
    for (int i=1; i<month; i++) {
        day += daysOfMonth[i];
    }

    cout << dayOfWeek[day % 7] << '\n';
    return 0;
}
