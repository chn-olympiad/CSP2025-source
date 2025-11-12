#include<bits/stdc++.h>
using namespace std;
int t,n;
int d1=0,d2=0,d3=0,ans=0,mmax=0;
int a[100005],b[100005],c[100005],all[100005];
void dfs(int x){
	if(x>n){
		if(d1>n/2||d2>n/2||d3>n/2)return;
		for(int i=1;i<=n;i++){
			ans+=all[i];
		}
		mmax=max(mmax,ans);
		ans=0;
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			d1++;
			all[x]=a[x];
			dfs(x+1);
			all[x]=0;
			d1--;
		}
		if(i==2){
			d2++;
			all[x]=b[x];
			dfs(x+1);
			all[x]=0;
			d2--;
		}
		if(i==3){
			d3++;
			all[x]=c[x];
			dfs(x+1);
			all[x]=0;
			d3--;
		}
		
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>t;
while(t--){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(all,0,sizeof(all));
	d1=0;d2=0;d3=0;ans=0;mmax=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	dfs(1);
	cout<<mmax<<endl;
}
return 0;
} 
