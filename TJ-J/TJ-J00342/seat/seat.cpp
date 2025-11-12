#include<bits/stdc++.h>
using namespace std;
int n,m,grade[101] = {},target;
bool flag = 1;
int h = 0,l = 1;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i <= n*m;i++){
        cin >> grade[i];
    }
    target = grade[1];
    sort(grade+1,grade+(n*m)+1);
    for(int i = n*m;i >= 1;i--){
        (flag ? h++ : h--);
        if(h > n){
            h = n;
            flag = false;
            l++;
        }
        else if(h < 1){
            h = 1;
            flag = true;
            l++;
        }
        if(grade[i] == target)cout << l << " " << h;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
