#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+20;
const int N=1e4+20;
int n,m,k;
struct node{
	int u,v,w;
}e[M];
struct TT{
	int val,j;
};
int fa[N];
int c[11];
int K[11][N];
int Ans;
vector<int> v[11];
int tot[11];
vector<int> V;
bool flag;
bool cmp(node x,node y){
	return x.w<y.w;
}
bool Cmp(TT x,TT y){
	return x.val<y.val;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
TT val[N][11];
int lst[11][N];
bool CMP(int x,int y){
	return tot[x]<tot[y];
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(false);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;i++){
	//
	//	cin>>e[i].u>>e[i].v>>e[i].w; 
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	//cocout<<"Y";ut<<n<<"\n";	
	flag=1;
	for(int i=1;i<=k;++i){
		scanf("%lld",&c[i]);
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;++j){
			scanf("%lld",&K[i][j]);
			if(K[i][j]!=0) flag=0;
			//cout<<j<<"\n";
			//cout<<p[i][j]<<"\n";
			
			val[j][i].val=K[i][j],val[j][i].j=i;
			//cout<<p[i][j]<<" "<<val[j][i].val<<"\n";
		} 
		//cout<<i<<" "<<k<<"\n";
	}
	//

	if(flag){
		cout<<"0\n";
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			val[i][j].val=K[j][i];
			val[i][j].j=j;
		}
	}
	
	for(int i=1;i<=n;i++) sort(val[i]+1,val[i]+1+k,Cmp);
	
	for(int i=1;i<=n;i++){
		
		tot[val[i][1].j]++;
		Ans+=val[i][1].val;
		v[val[i][1].j].push_back(i);
		if(tot[val[i][1].j]==1){
			Ans+=c[val[i][1].j];
			V.push_back(val[i][1].j);
		}
	} 
	sort(V.begin(),V.end(),CMP);
	
	
	for(int i=0;i<V.size();i++){
		int x=V[i];
		int s=0;
		for(int j=0;j<v[x].size();j++){
			int y=v[x][j];
			for(int q=1;q<=k;q++){	
				if(tot[val[y][q].j]!=0&&val[y][q].j!=x){
					s+=val[y][q].val-K[x][y];
					break;
				}
			}
		}
	//	cout<<s<<" "<<x<<"\n"; 
		if(s<c[x]&&s>0){
			Ans-=c[x];
			Ans+=s;
			for(int j=0;j<v[x].size();j++){
				int y=v[x][j];
				for(int q=1;q<=k;q++){
					if(tot[val[y][q].j]!=0&&val[y][q].j!=x){
						tot[val[y][q].j]++;
						v[val[y][q].j].push_back(y);
						break;
					}
				}
			}
			tot[x]=0;
		}
	}
	sort(e+1,e+1+m,cmp);
//	cout<<Ans<<"\n";
//	puts("Ye");
	int cnt=0,S=0;
	for(int i=1;i<=m;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y){
			cnt++;
			S+=e[i].w;
			for(int j=1;j<=k;j++){
				tot[j]=0;
				K[j][x]=min(K[j][x],K[j][y]);
			}
			V.clear();
			fa[y]=x;
			int ans=0;
			for(int j=1;j<=k;j++){
				v[j].clear();
			}
			for(int j=1;j<=n;j++){
				if(fa[j]!=j) continue;
			//	if(j==28) cout<<val[1][3].j<<"\n"; 
				
				for(int q=1;q<=k;q++){
					val[j][q].j=q;
					val[j][q].val=K[q][j];
				}
				sort(val[j]+1,val[j]+1+k,Cmp);
			//	if(j==1){
				//	cout<<val[1][3].j<<"\n";
				//	if(val[1][3].j!=5) cout<<j<<"\n";
				//}
				int t=1;
				ans+=val[j][1].val;
				tot[val[j][1].j]++;
				if(tot[val[j][1].j]==1) ans+=c[val[j][1].j],V.push_back(val[j][1].j);
				v[val[j][1].j].push_back(j);
			}
			//cout<<ans<<"\n";
		//	cout<<val[1][3].j<<"\n";
			for(int j=1;j<=n;j++){
				if(fa[j]!=j) continue;
				int t=val[j][1].j;
			//	cout<<t<<"\n";
				for(int q=2;q<=k;q++){
					//cout<<t<<" "<<val[j][q].j<<"\n";
					if(tot[t]<tot[val[j][q].j]){
					//	cout<<"Y\n";
						lst[t][j]=val[j][q].j;
						t=val[j][q].j;
					}
				//	cout<<t<<" "<<q<<"\n";
				}
			//	cout<<j<<" "<<k<<"\n";
			}
			//puts("Y");
			sort(V.begin(),V.end(),CMP);
			for(int j=0;j<V.size();j++){
				int x=V[j];
				int s=0;
				for(int q=0;q<v[x].size();q++){
					int y=v[x][q];
					int t=lst[x][y];
					s+=K[t][y]-K[x][y];
				}
			//	cout<<s<<" "<<c[x]<<" "<<ans<<"\n";
				if(s>0&&s<c[x]){
					ans-=c[x];
					ans+=s;
					for(int q=0;q<v[x].size();q++){
						int y=v[x][q];
						int t=lst[x][y];
						v[t].push_back(y);
						tot[t]++;
					}
				}
			}
		//	cout<<S<<" "<<ans<<"\n";
			Ans=min(Ans,ans+S);
		//	cout<<Ans<<"\n";
			if(cnt==n-1) break;
		}
	} 
	cout<<Ans;
}
