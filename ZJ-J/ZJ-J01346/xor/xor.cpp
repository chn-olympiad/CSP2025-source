#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,k;
long long a[maxn];
long long x[maxn];
long long t=1;
long long ans=0;
int flag=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
	}
	long long l=1,r=1;
	long long nowx=a[l];
	while(r<=n){
		flag=0;
	     if(nowx==k){
	     	ans++;
	     	l=++r;
	     	nowx=a[l];
	     	continue;
		 }
		 for(int i=l;i<r;i++){
		 	if((nowx^(x[i]^x[l-1]))==k){
		 		ans++;
		 		l=++r;
		 		nowx=a[l];
		 		flag=1;
		 		break;
			 }
		 }
		 if(!flag)nowx^=a[++r];
	}
	cout<<ans<<"\n";
	return 0;
}
