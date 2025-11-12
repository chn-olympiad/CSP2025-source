#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    char s;

    char a[1001];
    int n = 0;
    for(int i = 0; i< 100; i++)
    {
        cin >> s;
        if(s >= '0' && s <= '9'){
            a[n] = s;
            n++;
        }
    }
    sort(a, a + n);
    for(int i = n - 1;i >= 0; i--){
        cout << a[i];
    }

    return 0;
}
