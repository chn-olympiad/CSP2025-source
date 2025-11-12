#include<bits/stdc++.h>
using namespace std;
long long s[1000000];
long long m[1000000];
long long mx=-100;
long long ms;
long long rn,q=0,ans=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>s[i];
	}
	for(long long i=1;i<=n*m;i++){
		mx=-100;
		for(long long j=1;j<=n*m;j++){
			if(s[j]>mx&&s[j]!=-1){
				mx=s[j];
				ms=j;
			}
		}
		if(ms==1){
			rn=ans;
		}
		s[ms]=-1;
		if(ans==n*m){
			break;
		}else{
			ans++;
		}
	}
	for(long long i=1;i<=m;i++){
		if(i%2==1){
			for(long long j=1;j<=n;j++){
				q++;
				if(q==rn){
					cout<<i<<" "<<j;
					return 0;
				}
			
			}
		}else{
			for(long long j=n;j>=1;j--){
				q++;
				if(q==rn){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
}
