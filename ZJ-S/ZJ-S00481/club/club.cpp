#include<bits/stdc++.h>
using namespace std;
int n , nn , t;
long long misaki[100010][4];
struct node{
    long long sum , a , b , c;
};
node dp[10010][4];
long long mx[10010];
int main(){
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    cin >> t;
    for(int k = 1 ; k <= t ; k++){
        cin >> n;
        nn = n / 2;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= 3 ; j++){
                cin >> misaki[i][j];
            }
        }
        dp[1][1] = {misaki[1][1] , 1 , 0 , 0};
        
        dp[1][2] = {misaki[1][2] , 0 , 1 , 0};
        dp[1][3] = {misaki[1][3] , 0 , 0 , 1};
        for(int i = 1 ; i <= n ; i++){
            mx[i] = 0;
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= 3 ; j++){
                dp[i][j] = {0 , 0 , 0 , 0};
            }
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1; j < 3; j++){
                
                mx[i] = max({dp[i][1].sum , dp[i][2].sum , dp[i][3].sum});
                if(j == 1){
                    dp[i][j] = {max(mx[i - 1] + misaki[i][j] , dp[i][j].sum) , dp[i][j].a , dp[i][j].b , dp[i][j].c};
                    dp[i][j].a += 1;
                }
                else if (j == 2){
                    dp[i][j] = {max(mx[i - 1] + misaki[i][j] , dp[i][j].sum) , dp[i][j].a , dp[i][j].b + 1 , dp[i][j].c};
                }
                else{
                    dp[i][j] = {max(mx[i - 1] + misaki[i][j] , dp[i][j].sum) , dp[i][j].a , dp[i][j].b , dp[i][j].c + 1};
                }
                if(dp[i][j].a > nn || dp[i][j].c > nn || dp[i][j].b > nn){
                    dp[i][j] = {0 , 0 , 0 , 0};
                }
            }
            
            
        }
        mx[n] = max({dp[n][1].sum , dp[n][2].sum , dp[n][3].sum});
        cout << mx[n] << endl;
    }
    return 0;
}