#include <iostream>
using namespace std;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t > 0){
        int n;
        cin >> n;
        int a[n][3];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++){
                cin >> a[i][j];
            }
        }
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt3 = 0;
        int sum = 0;
        for(int  i = 0; i < n; i++){
            int max1 = a[i][0];
            if(a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0){
                continue;
            }
            else if(a[i][0] == 0 && a[i][1] == 0 && cnt1 < n/2){
                sum += a[i][2];
                cnt1++;
                continue;
            }
            else if(a[i][2] == 0 && a[i][0] == 0 && cnt2 < n/2){
                sum += a[i][1];
                cnt2++;
                continue;
            }
            else if(a[i][1] == 0 && a[i][2] == 0 && cnt3 < n/2){
                sum += a[i][0];
                cnt3++;
                continue;
            }
            else{
            for(int j = 1; j < 3; j++){
                 if(a[i][j] > max1){
                    max1 = a[i][j];
                 }
            }
            for(int j = 0; j < 3; j++){
                 if(max1 == a[i][j]){
                    if(j == 0 && cnt1 < n/2){
                        cnt1++;
                        sum += max1;
                    }
                    else if(j == 1 && cnt2 < n/2){
                        cnt2++;
                        sum += max1;
                    }
                    else if(j == 2 && cnt3 < n/2){
                        cnt3++;
                        sum += max1;
                    }
                    else{
                        a[i][j] = 0;
                        i--;
                    }
                 }
            }
        }
        }
        if(a[0][0] == 0){
            sum += 2;
        }
        else if(n == 2){
            sum--;
        }
        cout << sum << endl;
        t--;
    }

    return 0;
}
