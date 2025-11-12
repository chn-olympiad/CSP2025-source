#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w,kk,su,conk;
}a[1100005];
vector<node>ve[20005];
int n,m,k,cnt,fl;
int father[20005];
int val[20005];
int flag[20005];
int flagsum[20005];
//
bool cmp(node x,node y){
	return x.w<y.w;
}
int getf(int x){
	if(x==father[x])return x;
	return father[x]=getf(father[x]);
}
void solve1(){
	int x,y,z,ans=0;
	for(int i=1;i<=n;i++)father[i]=i;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[i].u=x;
		a[i].v=y;
		a[i].w=z;
	}
	sort(a+1,a+m+1,cmp);
	int d=n;
	for(int i=1;i<=m;i++){
		int uu=a[i].u;
		int vv=a[i].v;
		int ww=a[i].w;
		x=getf(uu);
		y=getf(vv);
		if(x!=y){
			father[x]=y;
			d--;
			ans+=ww;
		}
	}
	cout<<ans<<endl;
}
//
void solve2(){
	int x,y,z,ans=0;
	cnt=n;
	for(int i=1;i<=n+k+1;i++)father[i]=i;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[i].u=x;
		a[i].v=y;
		a[i].w=z;
	}
	for(int i=1;i<=k;i++){
		cin>>x;
		cnt++;
//		int mins=INT_MAX,minid=0;
		for(int j=1;j<=n;j++){
			cin>>val[j];
			m++;
			a[m].kk=a[m].conk=i;
			a[m].u=cnt;
			a[m].v=j;
			a[m].w=val[j]+x;
			a[m].su=x;
//			if(val[j]<mins){
//				mins=val[j];
//				minid=j;
//			}
		}
//		for(int j=1;j<=n;j++){
//			m++;
//			a[m].kk=i;
//			if(j!=minid){
//				a[m].u=cnt;
//				a[m].v=j;
//				a[m].w=val[j];
//			}
//			else{
//				
//			}
//		}
	}
	sort(a+1,a+m+1,cmp);
	int d=n;
	for(int i=1;i<=m;i++){
		if(d<=1)break;
//		cout<<d<<endl;
		if(i==1){
//			cout<<"----------------\n";
//			for(int i=1;i<=m;i++){
//				cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<" "<<a[i].kk<<" "<<a[i].su<<endl;
//			}
//			cout<<"----------------\n";
		}
		int uu=a[i].u;
		int vv=a[i].v;
		int ww=a[i].w;
		x=getf(uu);
		y=getf(vv);
		if(x!=y){
			father[x]=y;
			d--;
			ans+=ww;
			a[i].w=INT_MAX;
			int kkk=a[i].kk;
			if(a[i].conk){
				flag[a[i].conk]++;
				flagsum[a[i].conk]=kkk+ww;
			}
			if(a[i].kk>0){
				d++;
				for(int j=1;j<=m;j++){
					if(a[j].kk==kkk){
						a[j].w-=a[j].su;
						a[j].kk=0;
					}
				}
				sort(a+1,a+m+1,cmp);
				i=0;
				continue;
			}
		}
//		cout<<i<<" "<<ans<<endl;
	}
//	for(int i=1;i<=k;i++){
//		if(flag[i]==1){
//			ans-=flagsum[i];
//		}
//	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		solve1();
	}
	else{
		solve2();
	}
	return 0;
}
