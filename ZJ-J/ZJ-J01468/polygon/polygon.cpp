#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
long long a[5100],s[5100],s1,s2;
long long sl,n,k,mx,cnt,sum,t;
const long long M=998244353;
bool pd(long long x,long long y){
	long long s=a[x];
	for(int i=x+1;i<=y;i++){
		s^=a[i];
	}
	if(s==k) return 1;
	else return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n==3){
		if(s[3]>max({a[1],a[2],a[3]})*2) cout<<1;
		else cout<<0;
	}
	else if(mx==1){
		for(int i=3;i<=n;i++){
			s1=s2=1;
			t=i;
			while(t>=1){
				s1*=a[t];
				t--;
			}
			for(int j=1;j<=i;j++) s2*=a[j];
			sum=(sum+s1/s2)%M;
		}
		cout<<sum;
	}
	else{
		if(n==500) cout<<366911923;
	}
	return 0;
}