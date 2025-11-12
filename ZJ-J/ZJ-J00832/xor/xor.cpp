#include<bits/stdc++.h>
using namespace std;
long long n,k,i,a[500010],j,b[500010],p,bao,s;
struct no{
	int t,w;
}t[500010];
bool cmp(no x,no y){
	return x.w<y.w;
	return x.w==y.w&&x.t<y.t;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	b[1]=a[1];
	for(i=2;i<=n;i++)b[i]=b[i-1] xor a[i];
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++){
			if((b[j] xor b[i-1])==k){
				t[++p].t=i;
				t[p].w=j;
				break;
			}
		}
	sort(t+1,t+1+p,cmp);
	s=1;bao=1;
	for(i=2;i<=p;i++){
		if(t[i].t>t[bao].w)s++,bao=i;
	}
	cout<<s;
}
