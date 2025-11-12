#include<bits/stdc++.h>
using namespace std;

int n,m,k,mmid;
int fa[50100];
long long f[15][50100],ans=0;
long long dian[15];
struct id{
	int to;
	long long w;
	bool shi;
};
vector<id>v[50100];

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void he(int x,int y){
	int rootx=find(x);
	int rooty=find(y);
	if(rootx!=rooty){
		fa[rootx]=rooty;
	}
}

queue<int> q,qq;

void di(int y){
	q.push(y);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int min_di=0x3f3f3f;
		int u=-1;
		for(int i=0;i<v[x].size();i++){
			if(find(v[x][i].to)!=find(x)){
				q.push(v[x][i].to);
				for(int k=1;k<=mmid;k++){
					if(k>n){
						f[x][v[x][i].to]=min(f[x][v[x][i].to],f[x][k]+f[k][v[x][i].to]+dian[k]);
					}else{
						f[x][v[x][i].to]=min(f[x][v[x][i].to],f[x][k]+f[k][v[x][i].to]);
					}
				}
				if(f[x][v[x][i].to] < min_di){
					u=i;
					min_di=f[x][v[x][i].to];
				}
			}
		}
		ans+=f[x][u];
		he(u,x);
		if(u==-1) return;
		cout<<ans<<"\n";
	}
}

bool vis[50050];
void di1(int y){
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			for(int j=0;j<v[i].size();j++){
				if(find(i)!=find(v[i][j].to)){
					qq.push(v[i][j].to);
					ans+=v[i][j].w;
					he(i,j);
					vis[v[i][j].to]=1;
				}
			}
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int s1,s2,s3;
		cin>>s1>>s2>>s3;
		dian[s1]=dian[s2]=0;
		id s4,s5;
		s4.to=s2;
		s4.w=s3;
		s4.shi=0;
		s5.to=s1;
		s5.w=s3;
		s5.shi=0;
		f[s1][s2]=s3;
		f[s2][s1]=s3;
		v[s1].push_back(s4);
		v[s2].push_back(s5);
	}
	mmid=n+1;
	for(int i=1;i<=k;i++){
		int s1;
		cin>>s1;
		id nam;
		dian[mmid]=s1;
		nam.shi=1;
		for(int j=1;j<=n;j++){
			long long s2;
			cin>>s2;
			id s3;
			s3.to=mmid;
			s3.w=s2;
			s3.shi=0;
			nam.to=j;
			nam.w=s2;
			f[j][mmid]=s2;
			f[mmid][j]=s2;
			v[j].push_back(nam);
			v[mmid].push_back(s3);
		}
		mmid++;
	}
	mmid--;
	for(int i=1;i<=mmid;i++){
		for(int j=1;j<=mmid;j++){
			f[i][j]=0x3f3f3f;
			f[j][i]=0x3f3f3f;
		}
	}
	for(int i=1;i<=mmid;i++){
		fa[i]=i;
		f[i][i]=0;
	}
	
	di1(1);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
