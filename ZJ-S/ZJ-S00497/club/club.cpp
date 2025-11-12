#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,wz;
}tmp[16];
struct cord{
	int bh,x,y,cz;
	bool operator <(const cord& cyh) const{
		return cz>cyh.cz;
	}
};
int T,n,ans,w[16],a[100005][5];
bool used[100005];
bool cmp(node q,node h){
	return q.x>h.x;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		priority_queue <cord> q;
		ans=0;
		memset(w,0,sizeof(w));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				tmp[j].x=a[i][j],tmp[j].wz=j;
			sort(tmp+1,tmp+4,cmp);
			w[tmp[1].wz]++;
			ans+=tmp[1].x;
			q.push({i,tmp[1].wz,tmp[2].wz,tmp[1].x-tmp[2].x});
			q.push({i,tmp[1].wz,tmp[3].wz,tmp[1].x-tmp[3].x});
	//		q.push({i,tmp[2].wz,tmp[3].wz,tmp[2].x-tmp[3].x});
	//		this mistake has been solved by:15:50
	//		oh no,where is my time!
		}
		memset(used,0,sizeof(used));
		while(max(w[1],max(w[2],w[3]))>n/2){
			cord t=q.top();q.pop();
			if(w[t.x]>n/2&&w[t.y]<n/2&&used[t.bh]==0){
				used[t.bh]=1;
				w[t.x]--;w[t.y]++;
				ans-=t.cz;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}