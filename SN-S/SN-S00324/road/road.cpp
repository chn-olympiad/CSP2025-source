//李兴辰 SN-S00324 安康高新技术产业开发区九年制学校
#include<bits/stdc++.h>
using namespace std;
const int N=3500;
const int M=0x3f3f3f3f;
long long n,m,k;
long long F[N][N],f[N],d[N][N];
vector<int>v[N];

typedef pair<int,int> PII;
struct T{
	int x,y,p;
}e[N];
bool cmp(T a,T b){
	return a.p<b.p;
} 
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	int tx=find(x),ty=find(y);
	if(tx!=ty)f[ty]=tx;
}
void getother(){
	for(int i=0;i<k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int u;
			cin>>u;
			e[m+i+j]={j,n+j+i,c+u};
		}
	}
}
bool Fi(){
	for(int i=1;i<n;i++){
		if(find(i)!=find(i+1))return 0;
	}return 1;
}

void bingchaji(){
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int t,g,q;
		cin>>t>>g>>q;
		if(t>g)swap(t,g);
		e[i].x=t,e[i].y=g,e[i].p=q;
	}
	sort(e+1,e+m+1,cmp);
	getother();
	int i=1,ans=0;
	while(!Fi()&&i<=n){
		T t=e[i++];
		while(find(t.x)==find(t.y)){
			t=e[i++];
		}
		merge(t.x,t.y);
		ans+=t.p;
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k; 
	if(!k){
		bingchaji();
	}
	memset(F,0x3f,sizeof(F));
	for(int i=1;i<=m;i++){
		int t,g,q;
		cin>>t>>g>>q;
		F[t][g]=F[g][t]=q;
		d[t][g]=-1;
	}
	for(int i=1;i<=k;i++){
		int t;
		cin>>t;
		for(int j=1;j<=n;j++){
			int l;
			cin>>l;
			l+=t;
			F[j][m+i]=F[m+i][j]=l;
			d[j][m+i]=-1;
		}
	}
	for(int i=1;i<=n+k;i++){
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				if(F[x][y]>F[x][i]+F[i][y]){
					d[x][y]=i;
					F[x][y]=F[x][i]+F[i][y];
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i!=j){
				if(d[i][j]==-1){
					ans+=F[i][j];
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
