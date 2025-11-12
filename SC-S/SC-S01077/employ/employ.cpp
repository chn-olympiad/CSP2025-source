#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
int n,m,c[510],_0,x[510],out,y[510],res;
ll ans;//x which y who
bool a[510]; 
char ch;
bool flaga=true;
void subtaska(){
	if(_0&&n-_0+1<m){
		cout<<0<<endl;
		return ;
	}
	
	return;
}
void dfs(int i){
	if(i==n+1){
		out=res=0;
		for(int j=1;j<=n;j++){
			//cout<<y[j]<<' ';
			if(!a[j])out++;
			else{
				//cout<<"patience";
				if(c[y[j]]<=out){
					out++;
				}else res++;
			}
		}
		//cout<<"  res "<<res<<endl;
		if(res>=m)ans++;
		ans%=mod;
		return;
	}
	for(int j=1;j<=n;j++){
		if(!x[j]){
			x[j]=i;
			y[i]=j;
			dfs(i+1);
			x[j]=0;
			y[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		if(ch=='0'){
			flaga=false;
			a[i]=false;
		}else{
			a[i]=true;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(flaga&&c[i]==0)_0++;
	}
	if(flaga&&n>10){
		subtaska();
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
} 