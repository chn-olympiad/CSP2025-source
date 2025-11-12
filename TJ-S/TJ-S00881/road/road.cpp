#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,b,a) for(int i=(b);i>=(a);i--)
#define mem(a,b) memset(a,b,sizeof(a));

using namespace std;


typedef long long ll;
typedef unsigned long long ull;


const int N=1e4+5;
ll n,m,k,u[N],v[N],w[N],maxn,sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	rep(i,1,n){
		cin>>u[i]>>v[i]>>w[i];
		maxn=max(maxn,w[i]);
		sum+=w[i];
	}
	cout<<sum-maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

