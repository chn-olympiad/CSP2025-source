#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int T,n;
int a[N][5],id[N];
int cnt[N];
priority_queue<int>q;
signed main(){
//	system("fc club.out club.ans");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		int ans=0;
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]){
				id[i]=1;
			}
			else{
				id[i]=2;
			}
			if(a[i][3]>=a[i][id[i]]){
				id[i]=3;
			}
		}
		for(int i=1;i<=n;i++){
			cnt[id[i]]++;
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			for(int i=1;i<=n;i++){
				ans+=a[i][id[i]];
			}
		}
		else{
			int p;
			if(cnt[1]>n/2){
				p=1;
			}
			if(cnt[2]>n/2){
				p=2;
			}
			if(cnt[3]>n/2){
				p=3;
			}
			while(!q.empty()){
				q.pop();
			}
			for(int i=1;i<=n;i++){
				if(id[i]==p){
					int now;
					if(p==1){
						if(a[i][2]>a[i][3]){
							now=2;
						}
						else{
							now=3;
						}
					}
					if(p==2){
						if(a[i][1]>a[i][3]){
							now=1;
						}
						else{
							now=3;
						}
					}
					if(p==3){
						if(a[i][1]>a[i][2]){
							now=1;
						}
						else{
							now=2;
						}
					}
					q.push(a[i][now]-a[i][p]);
				}
			}
			for(int i=n/2+1;i<=cnt[p];i++){
				ans+=q.top();
				q.pop();
			}
			for(int i=1;i<=n;i++){
				ans+=a[i][id[i]];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
