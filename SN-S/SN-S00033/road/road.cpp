#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,k,yuan,fa[N],key=0,xiang[N];
struct node{
	int j1,j2,quan;
}ai[N];
bool cmp(node a,node b){
	return a.quan<b.quan;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void bing(int a,int b){
	fa[find(a)]=find(b);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		cnt++;
		ai[cnt].j1=a;
		ai[cnt].j2=b;
		ai[cnt].quan=c;
		cnt++;
		ai[cnt].j1=b;
		ai[cnt].j2=a;
		ai[cnt].quan=c;
	}
	for(int i=1;i<=k;i++){
		cin>>yuan;
		xiang[n+i]=yuan;
		fa[n+i]=n+i;
		for(int j=1;j<=n;j++){
			int a1;
			cin>>a1;
			cnt++;
			ai[cnt].j1=n+i;
			ai[cnt].j2=j;
			ai[cnt].quan=a1;
			cnt++;
			ai[cnt].j1=j;
			ai[cnt].j2=n+i;
			ai[cnt].quan=a1;
		}
	}
	sort(ai+1,ai+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int flag=1;
		int f1=0;
		for(int m=n+1;m<=n+k;m++){
			if(ai[i].j1==m){
				if(ai[i].quan+xiang[ai[i].j1]>ai[i+1].quan){	
					f1=1;
				}
				else{
					key+=xiang[ai[i].j1];
					xiang[ai[i].j1]=0;
				}
			}
			if(ai[i].j2==m){
				if(ai[i].quan+xiang[ai[i].j2]>ai[i+1].quan){	
					f1=1;
				}
				else{
					key+=xiang[ai[i].j2];
					xiang[ai[i].j2]=0;
				}
			}
		}
		if(f1==1){
			continue;
		}
		if(find(ai[i].j1)!=find(ai[i].j2)){
			bing(ai[i].j1,ai[i].j2);
			key+=ai[i].quan;
		}
		for(int j=1;j<n;j++){
			if(find(j)!=find(j+1)){
				flag=0;
			}
		}
		if(flag==1){
			cout<<key;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
