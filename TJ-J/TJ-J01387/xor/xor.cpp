#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,k;
ll a[500005];
int f[500005][996];
ll gcd(ll a,ll b){
    ll cnt=0,sum=1;
    if (a < b){
        swap(a,b);
    }
    while (a!=0){
        cnt += !((a%2)==(b%2))*sum;
        sum *= 2;
        a /= 2;
        b /= 2;
    }
    return cnt;
}
int dfs(int step,int num){
    //cout << 0 << endl;
    if (step > n){
        //printf("when choose %d,perfect\n",num);
        return num;
    }
    if (num < 996 && f[step][num] != -1e9){
        return f[step][num];
    }
    int maxn = 0;
    for (int i=step;i<=n;i++){
        int now = gcd(a[step-1],a[i]);
        if(now == k){
            //printf("choose [%d,%d]\n",step,i);
            for (int j=i+1;j<=n+1;j++){
                maxn = max(dfs(j,num+1),maxn);
            }
        }else{
            for (int j=i+1;j<=n+1;j++){
                maxn = max(dfs(j,num),maxn);
            }
        }
    }
    maxn = max(dfs(step+1,num),maxn);
    if (num < 996){
        f[step][num] = maxn;
    }
    return maxn;
}
/*bool cmp(stu a,stu b){
    return a.m < b.m;
}*/
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    for (int i=0;i<500005;i++){
        for (int j=0;j<996;j++){
            f[i][j] = -1e9;
        }
    }
    cin >> n >> k;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }
    a[0] = 0;
    for (ll i=1;i<=n;i++){
        a[i] = gcd(a[i],a[i-1]);
    }
    cout << dfs(1,0);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

