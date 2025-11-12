#include<iostream>
#include<cmath>
using namespace std;
int ans=0;
int n,k,v[1005],f[1005],x,vis[5005][5005];
int a[100005];
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1)return false;
	}
	return true;
}
bool check1(){
	for(int i=1;i<=n;i++){
		if(a[i]>1)return false;
	}
	return true;
}
int done(int x,int y){
	int p=1,ans=0;
	while(true){
		int xx=x%2,yy=y%2;
		if(xx!=yy)ans+=p;
		p*=2;
		x/=2,y/=2;
		if(x==0&&y==0)break;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(check()==true){
		cout<<n/2;
		return 0;
	}
	if(check1()==true){
		if(k==0){
			int x=0;
			ans=1;
			for(int i=2;i<=n;i++){
				if(a[i]==a[i-1])ans++;
				else{
					x+=ans/2;
					ans=0;
				}
			}
			cout<<x;
		}
		else{
			bool flag=true;
			ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==0&&flag==true)ans++,i++,flag=false;
				else if(a[i]==0&&a[i+1]==1&&flag==true)ans++,i++,flag=false;
				else if(a[i]==1)ans++,flag=true;
				else flag=true;
			}
			cout<<ans;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		v[i]=done(a[i],v[i-1]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(abs(v[j]-v[i-1])==k)vis[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=max(f[i-1],f[i]);
		for(int j=i;j<=n;j++){
			if(vis[i][j]==1)f[j]=max(f[j],f[i]+1);
		}
	}
	
	cout<<f[n];
	return 0;
}
