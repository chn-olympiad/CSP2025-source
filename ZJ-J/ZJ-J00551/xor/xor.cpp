#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
long long f[500005];
long long sum(long long l,long long r){
	long long cnt=0;
	for(long long i=l;i<=r;++i){
		cnt=cnt^a[i];
	}
	return cnt;
}
long long solve3(){
	long long ans=0;
	long long tmpl=1;
	for(long long r=1;r<=n;++r){
		for(long long l=tmpl;l<=r;++l){
			if(sum(l,r)==k){
				//cout<<l<<" "<<r<<endl;
				tmpl=r+1;
				ans++;
				break;
			}
		}
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;++i){
		cin>>a[i];
	}
	cout<<solve3();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

