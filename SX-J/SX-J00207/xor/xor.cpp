#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=5e5+10;
ll n,k;
ll a[N],p[N];
int su=0;
int ans=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]^a[i];
	}
	for(int j=2;j<=n;j++){
		int start=j;
		su=0;

		for(int i=start-1;i>0;i--){
			if((p[start-1]^p[i-1])==k){

				su++;
				//start=i;
			}
		}
		for(int i=start;i<=n;i++){
			if((p[i]^p[start-1])==k){

				su++;
				//start=i+1;
			}
		}

		ans=max(ans,su);
	}

	cout<<ans;

	return 0;
}

