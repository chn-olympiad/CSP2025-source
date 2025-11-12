#include<bits/stdc++.h>
using namespace std ;
//xdvipdfmx (20250205)?
const int N=2e5+10;
int a[N][5];
int nxt[N][5];
int tot[4];
int pos[N],sec[N];
int getw(int x){
	return a[x][pos[x]]-a[x][sec[x]];
}
struct comp {
	bool operator()(int x,int y) {
		int wx=getw(x),wy=getw(y);
		return wx>wy;

	}

};

void solve() {
	priority_queue<int,vector<int>,comp>pq[4];
	int n;
	cin>>n;
	memset(tot,0,sizeof tot);
	for(int i=1; i<=n; i++) {
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		a[i][0]=-0x3f3f3f3f;
		nxt[i][1]=1;
		nxt[i][2]=2;
		nxt[i][3]=3;
	}
	for(int i=1; i<=n; i++) {
		sort(nxt[i]+1,nxt[i]+4,[&](int x,int y) {
			return a[i][x]>a[i][y];
		});
		pos[i]=nxt[i][1],sec[i]=nxt[i][2];
	}
	for(int i=1; i<=n; i++) {
		int fi=pos[i];
		if(tot[fi]>=n/2) {
			int j=pq[fi].top();
			if(getw(j)>getw(i)){
			pos[i]=nxt[i][2];
			sec[i]=nxt[i][3];
				
			}
			else{
			tot[fi]--;
			pq[fi].pop();
			pos[j]=nxt[j][2];
			sec[j]=nxt[j][3];
			pq[pos[j]].push(j);
			tot[pos[j]]++;
			}



		}
		 fi=pos[i];
		tot[fi]++;
		pq[fi].push(i);
	}
	int ans=0;
//	cout<<tot[1]<<"|"<<pq[1].size()<<endl;
//	cout<<tot[2]<<"|"<<pq[2].size()<<endl;
//	cout<<tot[3]<<"|"<<pq[3].size()<<endl;
	while(pq[1].size())ans+=a[pq[1].top()][1],pq[1].pop();
	while(pq[2].size())ans+=a[pq[2].top()][2],pq[2].pop();
	while(pq[3].size())ans+=a[pq[3].top()][3],pq[3].pop();
	cout<<ans<<endl;




}
int main() {
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
//	cout<<greater<int>{}(1,3);
	int t;
	cin>>t;
	while(t--)solve();
}
