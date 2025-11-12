#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,bj[N],ans,cnt[5],siz[5];
pair<int,int>pq[5][N*2];
void init(){
	memset(bj,0,sizeof bj),ans=0;
	for(int i=0;i<=2;i++)cnt[i]=siz[i]=0;
}
void MAIN(){
	cin>>n;init();
	for(int i=1,a,b,c;i<=n;i++){
		cin>>a>>b>>c;
		if(a>=b&&a>=c)
			pq[0][++siz[0]]={b-a,i},
			pq[0][++siz[0]]={c-a,i},
			ans+=a,cnt[0]++;
		else if(b>=c)
			pq[1][++siz[1]]={a-b,i},
			pq[1][++siz[1]]={c-b,i},
			ans+=b,cnt[1]++;
		else
			pq[2][++siz[2]]={a-c,i},
			pq[2][++siz[2]]={b-c,i},
			ans+=c,cnt[2]++;
	}
	int tmp=3;
	if(cnt[0]>n/2)tmp=0;
	if(cnt[1]>n/2)tmp=1;
	if(cnt[2]>n/2)tmp=2;
	if(tmp==3){cout<<ans<<"\n";return ;}
	sort(pq[tmp]+1,pq[tmp]+siz[tmp]+1);
	for(int j=siz[tmp];j>=1&&cnt[tmp]>n/2;j--){
		if(!bj[pq[tmp][j].second])
			ans+=pq[tmp][j].first,
			bj[pq[tmp][j].second]=1,
			cnt[tmp]--;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;cin>>T;while(T--)MAIN();
	return 0;
}