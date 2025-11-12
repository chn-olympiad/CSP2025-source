#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string a;
int arr[N];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> a;
    int m = 0;
    for (int i = 0; i < a.size(); i++){
        if (a[i] >= '0' && a[i] <= '9'){
            if (a[i] == '0'){
                arr[m] = 0;
                m++;
            }else if (a[i] == '1'){
                arr[m] = 1;
                m++;
            }else if (a[i] == '2'){
                arr[m] = 2;
                m++;
            }else if (a[i] == '3'){
                arr[m] = 3;
                m++;
            }else if (a[i] == '4'){
                arr[m] = 4;
                m++;
            }else if (a[i] == '5'){
                arr[m] = 5;
                m++;
            }else if (a[i] == '6'){
                arr[m] = 6;
                m++;
            }else if (a[i] == '7'){
                arr[m] = 7;
                m++;
            }else if (a[i] == '8'){
                arr[m] = 8;
                m++;
            }else if (a[i] == '9'){
                arr[m] = 9;
                m++;
            }
        }else if (a[i] >= 'a' && a[i] <= 'z'){
            continue;
        }
    }
    sort(arr, arr + m, greater<int>());
    for (int i = 0; i < m; i++){
        cout << arr[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
} 	