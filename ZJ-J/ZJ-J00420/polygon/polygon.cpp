#include<bits/stdc++.h>
using namespace std;
long long n,a[10001],b[10001],t,v=0,ans;
const long long x=998244353;
void dfs(int y){
	if(y==n+1)
	return;
	if(y>=3){
		if(ans>2*v)
		t++;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			int s=v;
			v=max(v,a[i]);
			ans+=a[i];
			dfs(y+1);
			b[i]=0;
			v=s;
			ans-=a[i];
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f=max(a[i],f);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2){
			cout<<"1"<<endl;
		}else{
			cout<<"0"<<endl;
		}
		return 0;
	}
	if(f==1){
		cout<<"1"<<endl;
		return 0;
	}
	t=0;
	sort(a+1,a+n+1);
	dfs(0);
	cout<<t<<endl;
	return 0;
}