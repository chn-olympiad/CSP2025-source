#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T;
int n;

struct node{
	int i,w;
}a[N][4];

bool cmp(node x,node y){
	return x.w>y.w;
}

int b[5],ans;
int d[N],cnt;

signed main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1].w>>a[i][2].w>>a[i][3].w;
			a[i][1].i=1;
			a[i][2].i=2;
			a[i][3].i=3;
		}
		for(int i=1;i<=n;i++){
			sort(a[i]+1,a[i]+4,cmp);
		}
		for(int i=1;i<=n;i++){
			b[a[i][1].i]++;
			ans+=a[i][1].w;
		}
		if(max(b[1],max(b[2],b[3]))<=n/2){
			cout<<ans<<"\n";
		}
		else{
			int o=0;
			if(b[1]>b[2]+b[3])o=1;
			if(b[2]>b[1]+b[3])o=2;	
			if(b[3]>b[1]+b[2])o=3;
			for(int i=1;i<=n;i++){
				if(a[i][1].i==o){
					d[++cnt]=min(a[i][1].w-a[i][3].w,a[i][1].w-a[i][2].w);
				}				
			}
			sort(d+1,d+1+cnt);
			for(int i=1;i<=b[o]-n/2;i++){
				ans-=d[i];
			}
			cout<<ans<<"\n";
		}
		
		ans=b[1]=b[2]=b[3]=cnt=0;
		for(int i=1;i<=n;i++){
			d[i]=0;
			for(int j=1;j<=3;j++){
				a[i][j].w=a[i][j].i=0;
			}
		}
	}
	return 0;
}
