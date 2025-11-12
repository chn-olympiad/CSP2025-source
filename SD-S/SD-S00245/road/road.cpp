#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,pre[N],K,u,v,w,c[N],cnt_check,point_check,cou=1,f[N];
struct node{int from,to,len;}a[N];
void add(int u,int v,int w){
	a[++K]={u,v,w};
}
bool cmp(node x,node y){
	return x.len>y.len;
}
bool check(int X){
	f[X]=1;
	bool fl=0;
	if(cnt_check==3)return 1;
	for(int i=1;i<=m;i++){
		if(a[i].from==X&&f[a[i].to]==0){
			if(a[i].to<=n){
				cnt_check++;
				fl=1;
			}
			f[a[i].to]=1;
			check(a[i].to);
			if(fl==1){
				cnt_check--;
				fl=0;
			}
			f[a[i].to]=0;
		}
		if(a[i].to==X&&f[a[i].from]==0){
			if(a[i].from<=n){
				cnt_check++;
			}
			f[a[i].from]=1;
			check(a[i].from);
			if(fl==1){
				cnt_check--;
				fl=0;
			}
			f[a[i].to]=0;
		}
	}return 0;
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
	}int ss=n+1,k1=k;
	while(k1--){
		for(int i=1;i<=n+1;i++){
			cin>>c[i];
			if(i!=1){
				add(i-1,ss,c[i]+c[1]);
			}
		}
		ss++;
	}sort(a+1,a+1+K,cmp);m+=(n+1)*k;
	for(int i=1;i<=m;i++){
		cnt_check=0;
		int xx=a[i].from,yy=a[i].to,zz=a[i].len;
		a[i].from=0,a[i].to=0,a[i].len=0;
		if(check(1)==0){
			a[i].from=xx;
			a[i].len=zz;
			a[i].to=yy;
		}
	}
	long long answer=0;
	for(int i=1;i<=m;i++){
		answer+=a[i].len;
	}cout<<answer;
	return 0;
}
