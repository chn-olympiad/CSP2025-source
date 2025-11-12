#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,a[N],vis[N],s[N][25],ans;
bool check(int x,int y){
	for(int i=0;i<=20;i++)
		if(s[y][i]^s[x][i]!=(k&(1<<i))>>i)
			return false;
	return true;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]&&vis[i-1]==0){
				ans++;
				vis[i]=1;
			}
		}
		cout<<ans<<'\n';
	}
	else if(k==1){
		for(int i=1;i<=n;i++)
			if(a[i]==1)ans++;
		cout<<ans<<'\n';
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<=20;j++)
				s[i][j]=s[i-1][j]^((a[i]&(1<<j))>>j);
		}
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if(check(i-1,j))
					ans++,i=j+1;
		cout<<ans<<'\n';
	}
	return 0;
}