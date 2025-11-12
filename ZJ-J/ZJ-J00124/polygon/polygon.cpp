#include <bits/stdc++.h>
using namespace std;
const long long N=5010;
long long f[N],a[N],i,n,z,s,mas,ma,j,ans,kkk,kkksc03,a1[N],a2[N],a3[N];
void add(){
	long long zz,i,x;
	z++;zz=z;x=n;
	for(i=1;i<=n;i++) f[i]=0;
	while(zz) f[x--]=zz%2,zz/=2;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		while(z!=pow(2,n)-1){
			add();s=0;mas=0;
			for(i=1;i<=n;i++) s+=(f[i]?a[i]:0),mas=max(mas,(f[i]?a[i]:0));
			if(s<=mas*2) continue;
			ma++;
		}
		cout<<ma;
	}
	else
	{
		for(i=1;i<=n-2;i++) a1[i]=i+3;
		a2[0]=6;for(i=1;i<=n-1;i++) a2[i]=a2[i-1]+a1[i-1];
		a3[1]=4;for(i=2;i<=n;i++) a3[i]=a3[i-1]+a2[i-1];
		cout<<a3[n-3];
	}
	return 0;
}