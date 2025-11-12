#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN=100005;
int t,n,sum[4],ind,d[MAXN],len,ans;
struct node{
	int a[4],ma,mi,mid;
	bool b;
} l[MAXN],l2[MAXN];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		sum[1]=sum[2]=sum[3]=0;
		ans=0,len=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> l[i].a[1] >> l[i].a[2] >> l[i].a[3];
			int ma=1,mi=1;
			if(l[i].a[2]>=l[i].a[1] && l[i].a[2]>=l[i].a[3]) ma=2;
			if(l[i].a[3]>=l[i].a[1] && l[i].a[3]>=l[i].a[2]) ma=3;
			if(l[i].a[3]<=l[i].a[1] && l[i].a[3]<=l[i].a[2]) mi=3; // 调换顺序，防止筛掉三个一样的 
			if(l[i].a[2]<=l[i].a[1] && l[i].a[2]<=l[i].a[3]) mi=2;
			int mid=6-ma-mi;
			l[i].ma=ma, l[i].mi=mi, l[i].mid=mid;
			if(l[i].a[ma]==l[i].a[mid]){
				l[i].b=1;
				continue; // 去哪都一样，不参与统计
			}
			l[i].b=0; // 多组数据，没初始化就这里就必须改 
			sum[ma]++;
		}
		for(int i=1;i<=n;i++) ans+=l[i].a[l[i].ma]; // 全取最大 
		
		if(sum[1]<=n/2 && sum[2]<=n/2 && sum[3]<=n/2){ 
			cout << ans << '\n';
		}
		else{
			if(sum[1]>n/2) ind=1;
			if(sum[2]>n/2) ind=2;
			if(sum[3]>n/2) ind=3;
			
			for(int i=1;i<=n;i++){
				if(l[i].b || l[i].ma!=ind){continue;}
				d[++len]=l[i].a[l[i].ma]-l[i].a[l[i].mid];
			}
			sort(d+1,d+len+1);
			for(int i=1;i<=sum[ind]-n/2;i++)
				ans-=d[i];
			cout << ans << '\n';
		}
	}
	
	
	return 0;
}
