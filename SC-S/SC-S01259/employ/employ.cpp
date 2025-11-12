#include<bits/stdc++.h>
using namespace std;
int book[100000],a[100000],n,sum,c[100000],p[100000],sun,pro,m,summ;
char t[100000];
void dfs(int step){
	if(step==n+1){
		sun=0,sum=0;
		for(int i=1;i<=n;i++){
			//cout<<a[i]<<" ";
			if(sun>=c[a[i]]) sun++,continue;
			//cout<<t[a[i]]<<endl;
			if(t[a[i]]=='1') sum++;
			else sun++;
		}
		//cout<<sum;
		//cout<<endl;
		if(sum>=m){
			pro++;
//			for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//			cout<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0){
		//	summ++;
			book[i]=1;
			a[step]=i;
			dfs(step+1);
			book[i]=0;
		}
	}
}
int main(){
	freopen("employ","r",stdin);
	freopen("employ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>t[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<pro<<endl;
}