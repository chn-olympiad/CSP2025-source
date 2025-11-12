#include<bits/stdc++.h>
using namespace std;

long long T,n;
long long a1[100005],a2,a3;
long long ans;

bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2>>a3;
		}
		sort(a1+1,a1+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=a1[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}

