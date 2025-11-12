#include<bits/stdc++.h>
using namespace std;
long long n,p,a[500005],t,sum,s,m;
bool hh[555555];
long long nm(long long  x){
	long long t,c=0;
	while(x>0){
		t=(-x)&x;
		c++;
		x-=t;
	}
	return c;
}
bool check(long long x){
	if(nm(x)<3)return 0;
	else{
		long long t,c=0,p;
		while(x>0){
			t=(-x)&x;
			p=log2(t)+1;
			c+=a[p];
			x-=t;
		}
		if(c>a[p]*2)return 1;
		else return 0;
	}
}
long long cc(long long x,long long y){
	long long u=1;
	memset(hh,0,sizeof(hh));
	for(long long i=x-y+1;i<=x;i++){
		u*=i;
		for(long long j=1;j<=y;j++){
			if(hh[j]==0&&u%j==0){
				u/=j;
				hh[j]=1;
			}
		}
	}u%=998244353;
	return u;
} 
int main(){
	//zhuangtaiyasuopianfen
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<500){
		
	
		for(long long i=1;i<=n;i++)cin>>a[i];
		sort (a+1,a+n+1);
		p=pow(2,n);
		for(long long i=1;i<p;i++){
			if(check(i))sum++;
		}cout<<sum%998244353;
	
	}
	else {
		sum=0;
		for(int i=3;i<=n;i++){
			sum%=998244353;
			sum+=cc(n,i);
		}cout<<sum%998244353;
	}
	return 0;
}
