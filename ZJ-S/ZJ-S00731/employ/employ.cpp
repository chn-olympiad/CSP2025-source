#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,s,md=998244353,c[1100];
int a[1100],f=1,b[1100];
void d(int t,int ss){
	if(t>n){
		if(ss>=m)s++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i])continue;
		b[i]=1;
		if(a[t]==0||t-1-ss>=c[i])d(t+1,ss);
		else d(t+1,ss+1);
		b[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
		if(!a[i])f=0;
	}
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	if(f){
		s=1;
		for(int i=1;i<=n;i++){
			s*=i;
			s%=md;
		}
		cout<<s;
		return 0;
	}
	if(n<=10){
		d(1,0);
		cout<<s;
		return 0;
	}
	return 0;
}
