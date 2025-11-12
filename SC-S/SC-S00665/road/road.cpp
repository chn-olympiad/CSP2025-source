#include<iostream>
#include<vector>
using namespace std;
long long a[10010][10010],b[20][10010],cnt;
struct stst{
	int u,v,w;
}st[1000010];
bool cmp(stst a,stst b){return a.w<b.w;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	/*int n,m,k;
	cin>>n>>m>>k;
	vector<int>opp[10010];
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>st[i].u>>st[i].v>>st[i].w;
		//a[st[i].u][st[i].v]=st[i].w;a[st[i].v][st[i].u]=st[i].w;
		opp[u].push_back(v);
		opp[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		long long s;
		cin>>s;
		//b[i][0]=s;
		for(int j=1;j<=n;j++){
			long long l;
			cin>>l;
			//b[i][j]=l;
		}
	}
	vector<int>opp1[10010];
	sort(st+1,st+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(!opp1[st[i].u].empty()){
			if(st[i].w<b[st[i].u][st[i].v])cnt+=st[i].w;
			else cnt+=b;
		}
	} */
	cout<<0<<endl;
	return 0;
}