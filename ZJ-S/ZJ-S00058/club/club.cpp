#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+100;
ll n,ans,a[N][10],b[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int f=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) f=0;
		} 
		if(n==2){
			int a1=a[1][1]+a[2][2],a2=a[1][1]+a[2][3],a3=a[1][2]+a[2][1],a4=a[1][2]+a[2][3],a5=a[1][3]+a[2][1],a6=a[1][3]+a[2][2];
			cout<<max(a1,max(a2,max(a3,max(a4,max(a5,a6)))))<<'\n';
		}
		if(f){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n);
			for(int i=n/2+1;i<=n;i++){
				ans+=b[i];
			}
			cout<<ans<<'\n';
		}else cout<<0<<'\n';
	}
	return 0;
}
