#include<bits/stdc++.h>
using namespace std;
int a[6000];
bool f[6000];
int n,m,maxday=-1;
unsigned long long ans=0;
void dfs(int day,int now,int pe){
	f[pe]=1;
	//cout<<"h";
	//cout<<day<<" "<<pe<<endl;
	if(now==m){
		cout<<ans;
		ans++;
		ans%=998244353;
		f[pe]=0;
		return;
	}
	if(day>maxday){
		f[pe]=0;
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(f[i]==0&&a[i]>day)dfs(day+1,now+1,i);
	} 
	f[pe]=0;
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxday=max(maxday,a[i]);
	}
	for(int i=1;i<=n;i++)
	dfs(1,1,i);
	cout<<ans;
	return 0;
} 
