#include<bits/stdc++.h>
using namespace std;
int n,k,vis[510],ans,a[510],b[510],g;
string s;
const long long M=998244353;
void dfs(int x,int r,int f){
	//cout<<x<<" "<<r<<" "<<f<<"\n";//cout<<r<<"\n";
	if(x>n){
		//for(int i=1;i<=g;i++)cout<<"1234567890 "<<b[i]<<" ";cout<<r<<"\n";
		if(r>=k){
			ans=(ans+1)%M;
			
			
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			//if(i==2&&x==3)cout<<a[i];
			if(s[x]=='0'||f>=a[i]){
				g++;
				b[g]=i;
				dfs(x+1,r,f+1);
				g--;
			}else{
				g++;
				b[g]=i;
				dfs(x+1,r+1,f);
				g--;
			}
			
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	s='0'+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
//	cout<<s[2];
	return 0;
}

