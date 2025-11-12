#include<bits/stdc++.h>
using namespace std;
long long n,a[5100],v[11000],s;
long long md=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	v[0]=1;
	for(int i=1;i<=n;i++){
		for(int i2=5000;i2>=0;i2--){
			if(v[i2]){
				v[i2+a[i]]+=v[i2];
				if(a[i]<i2){
					s+=v[i2];
					s%=md;
				}
			}
		}
	}
	cout<<s;
	return 0;
}
