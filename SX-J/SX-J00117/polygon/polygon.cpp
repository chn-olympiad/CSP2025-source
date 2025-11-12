#include<iostream>
#include<cmath>
#include<cstring>
#define int long long
using namespace std;
const int N=5001;
int a[N],sum,num[N],ans,mmax[N],tot,n;
bool v[N];
void dfs(int st,int ii){
	for(int i=1;i<=ii;i++){
		if(v[i]==0){
			v[i]=1;
			num[st]=i;
			sum+=a[st];
			mmax[++tot]=max(mmax[tot-1],a[st]);
			if(mmax[tot]*2<sum&&i>2) ans++;
			else dfs(st+1);
			v[i]=0;
			num[st]=0;
			sum-=a[st];
			tot--;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(mmax,-1,sizeof(mmax));
	for(int i=3;i<=n;i++) dfs(1,i);
	cout<<ans;
	return 0;
}