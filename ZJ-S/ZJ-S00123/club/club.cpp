#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int n,ans;
int a[maxn],b[maxn],c[maxn],taila,tailb,tailc;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		taila=tailb=tailc=0;
		ans=0;
		for(int i=1;i<=n;i++){
			int ea,eb,ec;
			cin>>ea>>eb>>ec;
			if(ea>=eb&&ea>=ec){
				ans+=ea;
				a[++taila]=min(ea-eb,ea-ec);
			}else if(eb>=ea&&eb>=ec){
				ans+=eb;
				b[++tailb]=min(eb-ea,eb-ec);
			}else if(ec>=ea&&ec>=eb){
				ans+=ec;
				c[++tailc]=min(ec-eb,ec-ea);
			}
		}
		if(taila>n/2){
			sort(a+1,a+taila+1);
			for(int i=1;i<=taila-n/2;i++){
				ans-=a[i];
			}
		}else if(tailb>n/2){
			sort(b+1,b+tailb+1);
			for(int i=1;i<=tailb-n/2;i++){
				ans-=b[i];
			}
		}else if(tailc>n/2){
			sort(c+1,c+tailc+1);
			for(int i=1;i<=tailc-n/2;i++){
				ans-=c[i];
			}
		}
		cout<<ans<<"\n";
	}
}
