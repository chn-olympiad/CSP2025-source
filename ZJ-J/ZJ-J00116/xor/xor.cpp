#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x,s,i,j,s0,s1,ma,a[1010],b[1010],c[1010],p[500010],q[500010];
int yh(int x,int y){
	int i,j,s,f,t=0,w=0,ans=0;
	memset(0,sizeof(a),0);
	memset(0,sizeof(b),0);
	while(x) a[++t]=x%2,x/=2;
	while(y) b[++w]=y%2,y/=2;
	s=min(t,w);f=max(t,w);
	for(i=1;i<=s;i++) c[i]=(a[i]!=b[i]);
	if(t>s) for(i=s+1;i<=t;i++) c[i]=a[i];
	if(w>s) for(i=s+1;i<=w;i++) c[i]=b[i];
	for(i=1,x=1;i<=f;i++,x*=2) ans+=c[i]*x;
	return ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]==0) s0++;
		if(p[i]==1) s1++;
	}
	if(s1==n){
		cout<<n/2;
		return 0;
	}
	if(s0+s1==n){
		if(m==1){
			cout<<s1;
			return 0;
		}
		for(i=1;i<=n;i++)
			if(p[i]==1&&p[i-1]==1)
				s0++,i++;
		cout<<s0;
		return 0;
	}
	for(i=1;i<=n;i++){
		s=p[i];q[i]=2e9;
		if(p[i]==m) q[i]=i;
		for(j=i+1;j<=n;j++){
			s=yh(s,p[j]);
			if(s==m) q[i]=min(q[i],j);
		}
	}
	for(i=n;i>=1;i--){
		x=i;
		while(x<=n){
			
		}
	}
	cout<<ma;
}
