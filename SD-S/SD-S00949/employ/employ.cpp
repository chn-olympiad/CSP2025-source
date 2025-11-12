#include <bits/stdc++.h>
using namespace std;
#define N 505
#define MOD 998244353
int n,m;
char a[N];
int b[N];
long long ans[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    ans[0]=1;
    for(int i=1;i<N;i++){
        ans[i]=ans[i-1]*i%MOD;
    }
    cout<<ans[n];
	return 0;
}

