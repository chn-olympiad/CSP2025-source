#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5010],mod=998244353,flag=1,cnt;
int fl[2][5010];
vector<int>v;
void dfs(int ch,int t,int sum,int la){
	if(t>ch){
		cnt++;
		cnt%=mod;
		return;
	}
	for(int i=la+1;i<=n-ch+t;i++){
		if(t==ch){
			if(sum<=a[i])break;
		}
		v.push_back(a[i]);
		dfs(ch,t+1,sum+a[i],i);
		v.pop_back();
	}
	return; 
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	sort(a+1,a+n+1);
	if(flag){
		fl[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++){
				fl[i%2][j]=fl[!(i%2)][j]+fl[!(i%2)][j-1];
			}
		}
		for(int i=3;i<=n;i++){
			cnt+=fl[n%2][i];
			cnt%=mod;
		}
		cout<<cnt;
	}else{
		for(int i=3;i<=n;i++){
			dfs(i,1,0,0);
		}
		cout<<cnt;
	}
	return 0;
}
