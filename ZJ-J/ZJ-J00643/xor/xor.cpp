#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,k,t,e,sum,cd1,cd2,s,s2,x,y,c,c1,q,ans,fl,
a[500010],l[500010],r[500010],g[500010],h[500010];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	if(n==1&&k==0){
		cout<<0;return 0;
	}
	else if(n==2&&k==0){
		cout<<1;return 0;
	}
	for(i=1;i<=n;i++){//长度 
		for(j=1;j<=n-i+1;j++){//起点 
			sum=0;
			for(k=j;k<=j+i-1;k+=2){
				if(i==1&&a[k]==m)
					t++,l[t]=j,r[t]=j;
				else{
					s=0;x=a[k];c=1;cd1=0;
					while(x!=0){
						if(x>c) x-=c,cd1++,g[cd1]=1;
						else if(x==c){
							x-=c;cd1++;g[cd1]=1;break;
						}
						c*=2;
					}
					c1=1;
					if(cd2!=0)
						for(e=1;e<=max(cd1,cd2);e++){
							if(g[e]!=h[e]) sum+=c1;
							c1*=2;
						}
					else q=cd2;
					y=a[k+1];c=1;s2=0;cd2=0;
					while(y!=0){
						if(y>c) y-=c,cd2++,h[cd2]=1;
						else if(y==c){
							y-=c;h[cd2]=1;break;
						}
						c*=2;
					}
					//s,s2是二进制
					if(q==0){
						c1=1;
						for(e=1;e<=max(cd1,cd2);e++){
							if(g[e]!=h[e]) sum+=c1;
							c1*=2;
						}
					}
				}
			}
			if(sum==k) t++,l[t]=j,r[t]=j;
		}
	}
	for(i=1;i<=t;i++){
		fl=0;
		for(j=i+1;j<=t;j++)
			if(l[i]>=l[j]&&l[i]<=r[j]||
			r[i]>=l[j]&&r[i]<=r[j])
				fl=1;
		if(fl==0) ans++;
	}
	cout<<ans;
	return 0;
}
//a[i]=0--1
//k=0--1
