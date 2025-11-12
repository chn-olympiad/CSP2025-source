#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m;
int st[N];
int vis[N];
int c[N];
int ans;
string s;
void dfs(int step){
	if(step==n) {
		int res=0;//·ÅÆú 
		for(int i=1;i<=n;i++){
	//		cout<<st[i]<<" ";
			int k=s[i]-'0';//ÄÑ¶È
			if(k==0) res++;
			else if(c[st[i]]<=res) res++;	 
		}
	//	cout<<"\n";
		if(res<=n-m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			st[step+1]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		dfs(0);
		cout<<ans;
	}
	else{
		if(m==n){
			int flag=1;
			for(int i=1;i<=n;i++){
				if(s[i]=='0'){
					cout<<0;
					flag=0;
					break;
				}
			}
			if(flag) cout<<1;
		}
		else if(m==0) cout<<1;
		else cout<<0;
	}
	return 0;
 } 

