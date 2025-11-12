#include <bits/stdc++.h>
using namespace std;
int n,m,h,x1=0,x2=0,e1=0,e2=0;
string s;
long long ans=0;
int c[510],t[510];
void dfs(int s){
	if(s==n+1){
		int v=0;
		for(int i=1;i<=n;i++)
			if(t[i]==1)
				v++;
		if(v>=m) ans++;
		return;
	}
	for(int i=1;i<=2;i++){
		if(i==1){
			if(e1<x1 && t[s]==0){
				e1++;
				t[s]++;
				dfs(s+1);
				t[s]--;
				e1--;
			}
		}else{
			if(e2<x2){
				e2++;
				for(int j=s+1;j<=n;j++){
					c[j]--;
					if(c[j]<0) t[j]=-1;
				}
				dfs(s+1);
				for(int j=s+1;j<=n;j++){
					c[j]++;
					if(c[j]>=0) t[j]=0;
				}
				e2--;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n==m){
		cout<<"1";
		return 0;
	}
	h=s.size();
	for(int i=0;i<h;i++)
		if(s[i]=='1') x1++;
		else x2++;
	dfs(1);
	cout<<ans-1;
	return 0;
}