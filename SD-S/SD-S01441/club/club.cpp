#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[100005],c[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1,cmp);
		long long ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=a[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}

