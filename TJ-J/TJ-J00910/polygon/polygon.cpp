#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
int n;
long long int ans = 0;
int arrlen[N];

bool judge(int k,int posi){
    int sum1 = arrlen[posi] + arrlen[posi+1];
    return sum1 > k;
}

bool cmp(int a,int b) {
    return a>b;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> arrlen[i];
    }

    sort(arrlen,arrlen+n,cmp);

    for(int i = 0 ; i<n-2 ; i++){
        for(int j = i+1 ; j<n-1 ; j++){
            if(judge(arrlen[i],j)) {
                ans += (n-j-1)%998244353;
            }
        }
    }

    cout << ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}


