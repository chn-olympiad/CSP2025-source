#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[1010];
int vis[1010];
int a[1010];
int c[1010];
string s;
int ans=0;
void cs(string s){
	for(int i=0;i<s.length();i++){
		a[i+1]=s[i]-'0';
	}
	return;
}
void dfs(int t){
	if(t==n){
		cs(s);
		int g=m;
		int fang=0;
		for(int i=1;i<=t;i++){
			//cout<<a[i]<<' '<<fang<<' '<<c[i]<<endl;
			if(a[i]==0||fang>=c[num[i]]){
				fang++;
			}
			else{
				g--;
			}
		}
		if(g<=0){
			ans++;
		}
		//cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			num[t+1]=i;
			dfs(t+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0);
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
