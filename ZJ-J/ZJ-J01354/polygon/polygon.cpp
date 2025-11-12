#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 5e3 + 10;
const ll mod = 998244353;

ll n;

int a[maxn];
int pre[maxn];
ll res;

void dfs(int step,int sum,int maxx){

    if(step == n + 1){
        res += (sum > maxx * 2);
        res %= mod;
        return ;
    }

    dfs(step + 1, sum,maxx);
    dfs(step + 1, sum + a[step], max(maxx,a[step]) );
}

signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

    cin  >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1,a+n+1,less<int>());

    dfs(1, 0, 0);

    cout << res << endl;

	return 0;
}
