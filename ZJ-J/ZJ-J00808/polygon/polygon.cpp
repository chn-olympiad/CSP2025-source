#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N=5005;
int n;
int a[N];
int b[N];
int ans;

void solve(int k){
	int maxn=0;
	int sum=0;
	for(int i=1;i<=k;i++){
		sum+=b[i];
		maxn=max(maxn,b[i]);
	}
	
	if(sum>2*maxn) ans++;
}

void dfs(int k,int s){
	if(k>3){
		solve(k-1);
	}
	for(int i=s+1;i<=n;i++){
		b[k]=a[i];
		dfs(k+1,i);
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	dfs(1,0);
	
	cout<<ans<<"\n";
	return 0;
}
