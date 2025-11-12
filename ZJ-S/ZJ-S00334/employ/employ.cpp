#include<bits/stdc++.h>
using namespace std;
char a[544];
int s[544],ss[544],sss[544],d[44];
const int p=998244353;
long long ans=0;
int pd=1,sl=0,res=0;
int z,x;
long long fac[544];
void dfs(int q,int w,int e,long long r){
	if(q==z){
		if(e>=x)ans+=r,ans%=p;
		return;
	}
	for(int i=0;i<=z;i++){
		if(s[i]==0)continue;
		if(a[q+1]=='0'){
			s[i]--;
			dfs(q+1,w+1,e,r*(s[i]+1)%p);
			s[i]++;
			continue;
		}
		if(i>w){
			s[i]--;
			dfs(q+1,w,e+1,r*(s[i]+1)%p);
			s[i]++;
		}
		else{
			s[i]--;
			dfs(q+1,w+1,e,r*(s[i]+1)%p);
			s[i]++;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>z>>x;
	fac[0]=1;
	for(int i=1;i<=z;i++){
		fac[i]=fac[i-1]*i%p;
	}
	for(int i=1;i<=z;i++){
		cin>>a[i];
		if(a[i]=='0')pd=0;
	}
	int c;
	for(int i=1;i<=z;i++){
		cin>>c;
		s[c]++;
	}
	if(pd==1){
		cout<<fac[z];
		return 0;
	}
	if(x==z){
		cout<<0;
		return 0;
	}
	dfs(0,0,0,1);
	cout<<ans;
	return 0;
}
