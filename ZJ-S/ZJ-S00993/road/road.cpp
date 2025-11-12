#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define OpenFile(_) freopen(#_ ".in","r",stdin);freopen(#_ ".out","w",stdout)
#define fi first
#define se second
typedef long long Int;
typedef pair<Int,Int> pir;
typedef pair<Int,pir> edge;

Int n,m,k,fa[20005],g[15],dead[15],cnt=0,sum=0,s,alive,ans;
edge e[2000005],yes[20005],no[2000005];

Int find(Int x){
	return (fa[x]==x)?x:(fa[x]=find(fa[x]));
}

int main(){
	IOS;OpenFile(road);

	cin>>n>>m>>k;
	for(Int i=1;i<=m;i++)cin>>e[i].se.fi>>e[i].se.se>>e[i].fi;
	for(Int i=1;i<=k;i++){
		cin>>g[i];
		sum+=g[i];
		for(Int j=1;j<=n;j++){
			cin>>e[++m].fi;
			e[m].se.fi=j;
			e[m].se.se=n+i;
		}
	}
	for(Int i=1;i<=n+k;i++)fa[i]=i;
	sort(e+1,e+m+1);
	for(Int i=1;i<=m;i++){
		Int fx=find(e[i].se.fi),fy=find(e[i].se.se);
		//cerr<<"Connecting: "<<e[i].se.fi<<"("<<fx<<") "<<e[i].se.se<<"("<<fy<<")\n";
		if(fx==fy||cnt==n+k-1){
			no[i-cnt]=e[i];
		}else{
			//cerr<<"Connected: "<<e[i].se.fi<<" "<<e[i].se.se<<endl;
			yes[++cnt]=e[i];
			fa[fx]=fy;
			sum+=e[i].fi;
			if(e[i].se.se>n)g[e[i].se.se-n]+=e[i].fi;
		}
	}
	ans=sum;
	for(Int i=0;i<(1<<k);i++){
		cnt=s=0;
		alive=n;
		for(Int j=1;j<=k;j++)dead[j]=i&(1<<(j-1)),s-=g[j]*(dead[j]>0),alive+=(dead[j]==0);
		for(Int j=1;j<=n+k;j++)fa[j]=j;
		for(Int j=1;j<=n+k-1;j++){
			if(yes[j].se.se<=n||!dead[yes[j].se.se-n]){
				fa[find(yes[j].se.fi)]=find(yes[j].se.se);
				++cnt;
				//cerr<<"Connected: "<<yes[j].se.fi<<" "<<yes[j].se.se<<endl;
			}
		}
		for(Int j=1;cnt<alive-1;j++){
			Int fx=find(no[j].se.fi),fy=find(no[j].se.se);
			//cerr<<"Connecting: "<<no[j].se.fi<<"("<<fx<<") "<<no[j].se.se<<"("<<fy<<")\n";
			if(fx==fy||(no[j].se.se>n&&dead[no[j].se.se-n]))continue;
			fa[fx]=fy;
			//cerr<<"Connected: "<<no[j].se.fi<<" "<<no[j].se.se<<endl;
			s+=no[j].fi;
			++cnt;
		}
		//cerr<<"ans:"<<sum+s<<endl;
		ans=min(ans,sum+s);
	}
	cout<<ans;

	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
