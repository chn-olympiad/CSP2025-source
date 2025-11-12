#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+2;
int t,n,sum=0,a[N][5],vis[N][5],b[4];
struct node{
	int id,c[5];
}e[5][N];
bool cmp(node xx,node yy){
	int u=a[xx.id][xx.c[1]]-a[xx.id][xx.c[2]];
	int v=a[yy.id][yy.c[1]]-a[yy.id][xx.c[2]];
	int lu=a[xx.id][xx.c[2]]-a[xx.id][xx.c[3]];
	int lv=a[yy.id][yy.c[2]]-a[yy.id][yy.c[3]];
	if(u!=v) return u>v;
	else return lu>lv;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		int sum=0,mx,m;
		b[1]=b[2]=b[3]=0;
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++) vis[i][1]=vis[i][2]=vis[i][3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			mx=max(a[i][1],max(a[i][2],a[i][3]));
			if(mx==a[i][1]){
				e[1][++b[1]].id=i;
				mx=max(a[i][2],a[i][3]);
				if(mx==a[i][2]){
					e[1][b[1]].c[1]=1;
					e[1][b[1]].c[2]=2;
					e[1][b[1]].c[3]=3;
				}
				else{
					e[1][b[1]].c[1]=1;
					e[1][b[1]].c[2]=3;
					e[1][b[1]].c[3]=2;
				}
			}
			else if(mx==a[i][2]){
				e[2][++b[2]].id=i;
				mx=max(a[i][1],a[i][3]);
				if(mx==a[i][1]){
					e[2][b[2]].c[1]=2;
					e[2][b[2]].c[2]=1;
					e[2][b[2]].c[3]=3;
				}
				else{
					e[2][b[2]].c[1]=2;
					e[2][b[2]].c[2]=3;
					e[2][b[2]].c[3]=1;
				}
			}
			else {
				e[3][++b[3]].id=i;
				mx=max(a[i][2],a[i][1]);
				if(mx==a[i][2]){
					e[3][b[3]].c[1]=3;
					e[3][b[3]].c[2]=2;
					e[3][b[3]].c[3]=1;
				}
				else {
					e[3][b[3]].c[1]=3;
					e[3][b[3]].c[2]=1;
					e[3][b[3]].c[3]=2;
				}	
			}
		}
		while(1){
			bool f=0;
			if(b[1]>m){
				sort(e[1]+1,e[1]+1+b[1],cmp);
				for(int i=1;i<=b[1];i++) cout<<e[1][i].id<<" ";
				for(int i=b[1];i>m;i--){
					int x=e[1][i].c[2];
					e[x][++b[x]].id=e[1][i].id;
					e[x][b[x]].c[1]=e[1][i].c[2];
					e[x][b[x]].c[2]=e[1][i].c[3];
					e[x][b[x]].c[3]=e[1][i].c[1];
				}
				cout<<endl;
				b[1]=m;
				f=1;
			}
			if(b[2]>m){
				sort(e[2]+1,e[2]+1+b[2],cmp);
				for(int i=1;i<=b[2];i++) cout<<e[2][i].id<<" ";
				for(int i=b[2];i>m;i--){
					int x=e[2][i].c[2];
					e[x][++b[x]].id=e[2][i].id;
					e[x][b[x]].c[1]=e[2][i].c[2];
					e[x][b[x]].c[2]=e[2][i].c[3];
					e[x][b[x]].c[3]=e[2][i].c[1];
				}
				cout<<endl;
				b[2]=m;
				f=1;
			}
			if(b[3]>m){
				sort(e[3]+1,e[3]+1+b[3],cmp);
				for(int i=1;i<=b[3];i++) cout<<e[3][i].id<<" ";
				for(int i=b[3];i>m;i--){
					int x=e[3][i].c[2];
					e[x][++b[x]].id=e[3][i].id;
					e[x][b[x]].c[1]=e[3][i].c[2];
					e[x][b[x]].c[2]=e[3][i].c[3];
					e[x][b[x]].c[3]=e[3][i].c[1];
				}
				cout<<endl;
				b[3]=m;
				f=1;
			}
			if(!f) break;
		}
		for(int i=1;i<=b[1];i++)sum+=a[e[1][i].id][1];
		for(int i=1;i<=b[2];i++) sum+=a[e[2][i].id][2];
		for(int i=1;i<=b[3];i++) sum+=a[e[3][i].id][3];
		cout<<sum<<endl;
		
	}
	return 0;
}
/*
z>=x>=y
x>=y>=z
Ren5Jie4Di4Ling5%
*/
