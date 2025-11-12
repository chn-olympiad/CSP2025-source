#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int num[N],m,n,c,r;

bool cmp(int a,int b) {
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >> n >> m;
    for(int i = 0 ; i< m*n ; i++){
        cin >> num[i];
    }
    int ar = num[0];

    sort(num,num + m*n,cmp);

    for(int i = 0 ; i< m*n ; i++){
        if (num[i] == ar){
            c = (i/m)+1;
            if((c-1)%2 == 0){
                r = i%m + 1;
            }
            else r = m - i%m ;
            break;
        }
    }

    cout << c << ' '<< r;


    fclose(stdin);
    fclose(stdout);

    return 0;
}

