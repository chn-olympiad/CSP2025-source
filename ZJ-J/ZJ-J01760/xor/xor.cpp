#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int xorr(int x,int y){
	int q[25]={0},p[25]={0},ans[25],c=0;
	if(x==0)q[0]=1;
	if(y==0)p[0]=1;
	for(int i=1;i<=22;++i)q[i]=p[i]=ans[i]=0;
	while(x){
		q[++q[0]]=x%2;
		x/=2;
	}
	while(y){
		p[++p[0]]=y%2;
		y/=2;
	}
	ans[0]=max(p[0],q[0]);
	for(int i=1;i<=ans[0];++i){
		if(q[i]==p[i])ans[i]=0;
		else ans[i]=1;
	}
	while(ans[0]){
		c*=2;
		c+=ans[ans[0]];
		ans[0]--;
	}
	return c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int cnt=a[1];
	for(int i=2;i<=n+1;++i){
		if(cnt==k){
			ans++;
			cnt=a[i];
		}else if(a[i-1]==k){
			ans++;
			cnt=a[i];
		}else{
			cnt=xorr(a[i],cnt);
		}
	}
	cout<<ans<<endl;
	return 0;	
}