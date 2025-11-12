#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s,c,d[5000005],z[5000005]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i = 1;i<=n;++i){
		cin>>a[i];
	}
	for(long long i = 1;i<=n;++i){
		z[i] = z[i-1]+d[i];
	}
	for(long long i = 1;i<=n;++i){
		for(long long j = i;j<=n;++j){
			long long l = i;
			long long r = j;
			s = a[l];
			while(l!=r){
				l++;
				s^=a[l];
			}
			if(s == k){
				if(z[j]-z[i-1] == 0){
					c++;
					for(long long x = i;i<=j;++i){
						d[x] = 1;
						z[i] = z[i-1]+d[x];
					}
				}
				break;
			}
		}
	}
	cout<<c;
	return 0;
}
