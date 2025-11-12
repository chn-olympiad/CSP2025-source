#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
priority_queue<pair<long long,pair<int,int> > ,vector<pair<long long,pair<int,int> > >,greater<pair<long long,pair<int,int> > > > pq;
int father[1005];
long long tu[1005][1005];
int in(){
	char c=getchar();
	int f=1,num=0;
	while(c>'9' && c<'0'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c<='9' && c>='0'){
		num=(num<<3)+(num<<1)+(c-'0');
		c=getchar();
	}
	return num*f;
}
int query(int x){
	if(father[x]==x){
		return x;
	}
	return father[x]=query(father[x]);
}
bool merge(int x,int y){
	int fx=query(x),fy=query(y);
	if(fx==fy){
		return false;
	}
	else{
		father[fx]=fy;
		return true;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(tu,0x3f,sizeof tu);
	int n=in(),m=in(),k=in();
	for(int i=1;i<=m;i++){
		int u=in(),v=in(),w=in();
		tu[u][v]=w;
		tu[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		int c=in(),money[1005];
		for(int j=1;j<=n;j++){
			money[j]=in();
			for(int g=1;g<j;g++){
				if(0ll+money[g]+money[j]+c<tu[j][g]){
					tu[j][g]=tu[g][j]=money[g]+money[j]+c;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			pq.push(make_pair(tu[i][j],make_pair(i,j)));
		}
	}
	int cnt=0;
	long long ans=0;
	while(cnt<n-1 && !pq.empty()){
		int a=pq.top().second.first,b=pq.top().second.second,c=pq.top().first;
		pq.pop();
		bool flag=merge(a,b);
		if(flag){
			cnt++;
			ans+=c;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

