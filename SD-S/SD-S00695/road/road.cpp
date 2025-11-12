#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int xz[12000];
bool xz1[12000]={false};
int fa[12000];
int mp[12000][12000];

 int find(int x){
 	if(fa[x]!=x)fa[x]=find(fa[x]);
 	return fa[x];
 }
 struct node{
 	int x,y,v;
 };
 bool cmp(node x,node y){
 	return x.v>y.v;
 }
 vector<node> mp1; 
int main(){
	for(int i=0;i<12000;i++)fa[i]=i;
	for(int i=0;i<12000;i++)for(int j=0;j<12000;j++)mp[i][j]=0x3f3f3f3f;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
	int a,b,c;
	node tmp;
	cin>>a>>b>>c;
	tmp.x=a;
	tmp.y=b;
	tmp.v=c;
	mp[a][b]=c;
	mp[b][a]=c;
	mp1.push_back(tmp);
	tmp.x=b;
	tmp.y=a;
	mp1.push_back(tmp);
	}
	for(int i=0;i<k;i++){
	cin>>xz[n+i];
	for(int j=0;j<n;j++){
	cin>>mp[j+1][n+i];
	mp[n+i][j+1]=mp[j+1][n+i];
	}
}
	for(int i=n;i<n+k;i++){
		for(int p=0;p<n;p++){
			for(int q=0;q<n;q++){
			mp[p][q]=min(mp[p][q],mp[p][i]+mp[i][q]+xz[i]);
			mp[q][p]=min(mp[q][p],mp[p][q]);
			node tmp;
			tmp.x=p,tmp.y=q,tmp.v=mp[p][q];
			mp1.push_back(tmp); 
			tmp.x=q,tmp.y=p,tmp.v=mp[p][q];
			mp1.push_back(tmp); }
		}
	}
	int ans=0;
	sort(mp1.begin(),mp1.end(),cmp);
	while(!mp1.empty()){
		node tmp=mp1.back();
		if(find(tmp.x)!=find(tmp.y) and tmp.v!=0x3f3f3f3f){
			fa[find(tmp.x)]=find(fa[tmp.y]),ans+=tmp.v;
			
		}
	     mp1.pop_back();
		}
		
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

