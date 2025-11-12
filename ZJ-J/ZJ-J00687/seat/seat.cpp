#include<bits/stdc++.h>
#define int long long
using namespace std;
int f;
int n,m;
int a[1000001];
int cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n*m;i++){
		scanf("%lld",&a[i]);
	}
	int r=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			f=i;
			break;
		}
	}
	f++;
	int k=floor(1.0*f/n);
	int num=f-k*n;
	if(num==0){
		num=n;
	}
	int q=ceil(1.0*f/n);
	if(q%2==0){
		printf("%lld %lld\n",q,n-num+1);
	}
	else{
		printf("%lld %lld\n",q,num);
	}
	
	
	return 0;
}
