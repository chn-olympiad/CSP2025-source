#include<bits/stdc++.h>
#define forf(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int N=5005;
int a[N],ans;
bool cmp(int a,int b){
	return a>b;
}
long long e(int a){
	long long sum=1;
	while(a){
		sum*=a;
		a--;
	}
	return sum;
}
long long C(int a,int b){
	long long ans=e(a)/e(b)/e(b);
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	forf(i,1,n) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(n<=3){
		forf(i,1,n){
			cnt+=a[i];
		}
		if(cnt > 2*a[1]) ans=1;
	}
	else{
		int jur=3;
		while(jur<=n){
			cnt+=C(n,jur);
			jur++;
		}
		ans=jur;
	}
	cout<<ans;
	return 0;
}

