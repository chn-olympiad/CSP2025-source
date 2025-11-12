#include<bits/stdc++.h>
#define pii pair<int,pair<int,int> >
#define x first
#define y second
using namespace std;
const int C0=1e3+10,C1=1e6+10;
int n,m,k,u,v,c[C0],cnt,ans;
int flag[C0],mpt[C0][C0],bk[C0];
priority_queue<pii,vector<pii>,greater<pii> >f;
void add(int u,int v,int w){
	f.push({w,{u,v}});
}
int main(){
	int i,s;
	int bk[C0];
	memset(bk,0,sizeof(bk));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&u,&v,&s);
			add(u,v,s);
		}
		for(int j=1;j<=k;j++){
			cin>>c[j];
			memset(flag,0,sizeof(flag));
			for(int i=1;i<=n;i++){
				scanf("%d",&mpt[j][i]);
				if(mpt[j][i]==0)flag[i]=1;
			}
			for(int i=1;i<=n;i++)
				if(flag[i])
					for(int I=1;I<=n;I++)if(i!=I)add(i,I,mpt[j][I]);
			
		}
		pii ptmp=f.top();
		s=ptmp.x,u=ptmp.y.x,v=ptmp.y.y;
		f.pop();bk[u]=bk[v]=1;cnt+=2;
		ans+=s;
		while(cnt<n){
			pii ptmp=f.top();
			s=ptmp.x,u=ptmp.y.x,v=ptmp.y.y;
			if(!bk[u]||!bk[v]){
				if(!bk[u])bk[u]=1,cnt++;
				if(!bk[v])bk[v]=1,cnt++;
				ans+=s;
			}
			f.pop();
		}
		cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
