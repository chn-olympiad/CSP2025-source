#include<bits/stdc++.h>
using namespace std;
int n, m, number, num[200];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    cin >> number;
    num[1] = number;
    for (int i = 2; i <= n * m;i++){
        cin >> num[i];
    }
    sort(num + 1, num + 1 + n * m,cmp);
    for (int i = 1,cnt=1; i <= n;i++){
        if(i%2==0){
            for (int j = m;j>=1;j--,cnt++){
                if(num[cnt]==number){
                    cout << i << " " << j;
                    return 0;
                }
            }
        }else{
            for (int j = 1; j <= m; j++,cnt++){
                if(num[cnt]==number){
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
    }
    return 0;
}