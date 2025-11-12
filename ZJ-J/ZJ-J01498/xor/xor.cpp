#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
long long n,k,ans;
long long a[maxn],s[maxn];

int axorb(long long a,long long b){
	return (a|b)-(a&b);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long l=0,r=1;
	cin >> n >> k;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		s[i]=axorb(a[i],s[i-1]);
	}
	while(r<=n){
		long long temp=axorb(s[l],s[r]);
		if(temp==k){
			ans++;
			l=r;
			r++;
		}
		else if(temp>k) l++;
		else r++;
	}
	cout << ans;
	return 0;
}
