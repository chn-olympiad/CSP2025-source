#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[100005],b[100005],c[100005],a1,a2,a3,b1,b2,b3,c1,c2,c3,cnt,ans;
struct h{
	int id,v;
};
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]==0&&c[i]==0){
				cnt++;
			}
		}
		if(cnt==n){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
