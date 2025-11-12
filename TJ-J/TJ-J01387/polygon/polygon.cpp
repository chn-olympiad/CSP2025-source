/*#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 998244353;
int n,cnt,a[5005];
void dfs(int step,int num,int l,int maxn){
    if (step > n){
        if (num < 3){
            return ;
        }
        if (l > maxn*2){
            cnt++;
            cnt %= MAXN;
        }
        return ;
    }
    dfs(step+1,num+1,l+a[step],max(maxn,a[step]));
    dfs(step+1,num,l,maxn);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    dfs(1,0,0,0);
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 998244353;
int n,cnt,a[5005],f[5005];
/*struct node{
    int q,m;
}a[5005];*/
bool cmp(int a,int b){
    return a>b;
}
void dfs(int step,int num,int l,int maxn){
    if (n-step+1+num < 3){
        return ;
    }
    if (step > n){
        if (num < 3){
            return ;
        }
        if (l > maxn*2){
            cnt++;
            cnt %= MAXN;
        }
        return ;
    }
    if (l+f[n]-f[step-1] <= maxn*2){
        return ;
    }
    dfs(step+1,num+1,l+a[step],max(maxn,a[step]));
    dfs(step+1,num,l,maxn);
}
int main(){
    /*freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
*/
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];//.m;
    }
    /*sort(a+1,a+n+1,cmp);
    a[1].q = a[1].m;
    a[0].q = 0;
    for (int i=2;i<=n;i++){
        a[i].q = a[i-1].q+a[i].m;
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++)
    }*/
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++){
        f[i] = f[i-1]+a[i];
    }
    dfs(1,0,0,0);
    cout << cnt;
    /*fclose(stdin);
    fclose(stdout);*/
    return 0;
}


