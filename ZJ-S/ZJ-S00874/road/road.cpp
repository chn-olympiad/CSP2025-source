#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,l,mins=INT_MAX,f,t,vis[10000],s,c,ar[1000][100000],br[1000][100000],lr[10000],g=1,d[10000];
struct node{
	int to,le;
}cr[10000];
bool cmp(node x,node y){
	return x.le<y.le;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> u >> v >> l;
		ar[u][v]=l;
		ar[v][u]=l;
		if(l<mins){
			f=u;
			t=v;
			mins=l;
		}
	}
	for(int i=n+1;i<=n+k;i++){
		cin >> d[i];
		for(int j=1;j<=n;j++){
			cin >> br[i][j];
			ar[i][j]=br[i][j];
			ar[j][i]=br[i][j];
			if(br[i][j]<mins){
				f=i+n;
				t=j+n;
				mins=br[i][j];
			}
		}
	}
	n+=k;
	m+=k;
	vis[f]=1;
	vis[t]=1;
	s=mins;
	lr[0]=mins;
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&ar[f][i]){
			cr[c]={i,ar[f][i]};
			c++;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&ar[t][i]){
			cr[c]={i,ar[t][i]};
			c++;
		}
	}
	for(int i=1;i<=n-1;i++){
		sort(cr,cr+c,cmp);
		int p=0;
		while(cr[p].le==0||vis[cr[p].to]){
			p++;
		}
		vis[cr[p].to]=1;
		s+=cr[p].le;
		lr[g]=cr[p].le;
		g++;
		for(int j=1;j<=n;j++){
			if(vis[j]==0&&ar[cr[p].to][j]){
				cr[c]={j,ar[cr[p].to][j]};
				c++;
			}
		}
	}
	sort(lr,lr+g);
	cout << s-lr[0];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
