#include<bits/stdc++.h>
using namespace std;
const int N=3e5+11;
long long a[N][4],b[N],suma[N];
long long T,n,cnt,sum[4],maxn;
priority_queue<int>q;
void dfs(int dep){
	if(maxn-sum[dep]>cnt)return;
	if(dep>n){
		maxn=max(maxn,cnt);
		return;
	}
	for(int i=1;i<=3;i++){
		if(sum[i]<n/2){
			cnt+=a[dep][i];
			sum[i]++;
			dfs(dep+1);
			sum[i]--;
			cnt-=a[dep][i];
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--) {
		maxn=0,cnt=0,sum[1]=sum[2]=sum[3]=0;
		scanf("%lld",&n);
		for(int i=1; i<=n; i++) {
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		suma[n+1]=0;
		for(int i=n;i>=1;i--)suma[i]=suma[i+1]+max(max(a[i][1],a[i][2]),a[i][3]);
		if(n<=10){dfs(1);printf("%lld\n",maxn);}
		else{
			for(int i=1;i<=n;i++){
				maxn+=a[i][1];
				b[i]=a[i][1]-a[i][2];
			}
			sort(b+1,b+n+1);
			for(int i=1;i<=n/2;i++){
				maxn-=b[i];
			}
			printf("%lld\n",maxn);
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

2
2
10 9 8
4 0 0
4
0 1 0
0 1 0
0 2 0
0 2 0

1
30
6090 4971 4101
14495 19657 10011
6294 14948 17496
3266 18897 6963
3129 14412 12639
5331 7102 7590
12533 15635 16270
2339 16892 11211
6980 3113 19980
16859 13322 9404
16742 1573 8946
1285 5253 2697
18072 16412 5595
15870 17311 7711
19194 4644 11192
1306 6558 10317
11128 16814 5947
1603 6202 15251
4014 5797 2498
1557 4235 12431
1561 16149 16433
9399 1760 809
13383 18379 10169
7679 4131 17310
2900 8148 13627
14783 19510 17642
19717 4666 6335
9868 5451 19561
11196 1774 11436
10753 10148 6994
*/
/*#include<bits/stdc++.h>
using namespace std;
const int N=3e5+11;
int T,n,x,y,z,sum[N],ans;
bool vis[N];
pair<int,int>a[N],b[N];
int main() {
	freopen("club3.in","r",stdin);
	freopen("club3.out","w",stdout);
	cin>>T;
	while(T--) {
		memset(vis,false,sizeof vis);
		int fr1=1,fr2=1;
		ans=0,sum[1]=sum[2]=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>x>>y>>z;
			a[i]={x-y,i};
			b[i]={x-z,i};
			ans+=x;
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		while(sum[1]+sum[2]<n/2&&fr1<=n&&fr2<=n){
			while(vis[fr1]&&fr1<=n)fr1++;
			while(vis[fr2]&&fr2<=n)fr2++;
			if(fr1>n||fr2>n)break;
			if(a[fr1].first>b[fr2].first){
				ans-=b[fr2].first;
				sum[2]++;
				vis[b[fr2].second]=true;
				fr2++;
			}else{
				ans-=a[fr1].first;
				sum[1]++;
				vis[a[fr1].second]=true;
				fr1++;
			}
			if(sum[1]==n/2||sum[2]==n/2)break;
			
		}
		while(fr1<=n&&sum[1]<n/2&&(a[fr1].first<0||sum[1]+sum[2]<2/n)){
			if(vis[a[fr1].second]==false)ans-=a[fr1].first,sum[1]++,vis[a[fr1].second]=true;
			fr1++;
		}
		while(fr2<=n&&sum[2]<n/2&&(b[fr2].first<0||sum[1]+sum[2]<2/n)){
			if(vis[b[fr2].second]==false)ans-=b[fr2].first,sum[2]++,vis[b[fr2].second]=true;
			fr2++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+11;
int T,n,x,y,z,sum[N],ans;
bool vis[N];
pair<int,int>a[N],b[N];
int main() {
	cin>>T;
	while(T--) {
		memset(vis,false,sizeof vis);
		int fr1=1,fr2=1;
		ans=0,sum[1]=sum[2]=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>x>>y>>z;
			a[i]={x-y,i};
			b[i]={x-z,i};
			ans+=x;
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)cout<<a[i].first<<' ';
		cout<<'\n';
		for(int i=1;i<=n;i++)cout<<b[i].first<<' ';
		cout<<'\n';
		while(sum[1]+sum[2]<n/2&&fr1<=n&&fr2<=n){
			while(vis[fr1]&&fr1<=n)fr1++;
			while(vis[fr2]&&fr2<=n)fr2++;
			if(fr1>n||fr2>n)break;
			cout<<a[fr1].first<<' '<<b[fr2].first<<'\n';
			if(a[fr1].first>b[fr2].first){
				cout<<b[fr2].first<<' '<<b[fr2].second<<'\n';
				ans-=b[fr2].first;
				sum[2]++;
				vis[b[fr2].second]=true;
				fr2++;
			}else{
				cout<<a[fr1].first<<' '<<a[fr1].second<<'\n';
				ans-=a[fr1].first;
				sum[1]++;
				vis[a[fr1].second]=true;
				fr1++;
			}
			if(sum[1]==n/2||sum[2]==n/2)break;
			
		}
		while(fr1<=n&&sum[1]<n/2&&(a[fr1].first<0||sum[1]+sum[2]<2/n)){
			if(vis[a[fr1].second]==false)ans-=a[fr1].first,sum[1]++,vis[a[fr1].second]=true;
			cout<<a[fr1].first<<'\n';
			fr1++;
		}
		while(fr2<=n&&sum[2]<n/2&&(b[fr2].first<0||sum[1]+sum[2]<2/n)){
			if(vis[b[fr2].second]==false)ans-=b[fr2].first,sum[2]++,vis[b[fr2].second]=true;
			cout<<b[fr2].first<<'\n';
			fr2++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
*/
