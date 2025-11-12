#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	int a[3];
	int rkf,rks,rkt;
	int fs,st;
}num[N];

struct edge{
	int u,w;
};
bool cmp(edge x,edge y){
	return x.w>y.w;
}
int T,n,cnt[3];
ll ans;
edge s[3][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			num[i].a[0]=a,num[i].a[1]=b,num[i].a[2]=c;
			if(a>=b){
				if(a>=c){
					if(b>=c) num[i].rkf=0,num[i].rks=1,num[i].rkt=2;
					else num[i].rkf=0,num[i].rks=2,num[i].rkt=1;
				}else num[i].rkf=2,num[i].rks=0,num[i].rkt=1;
			}else{
				if(b>=c){
					if(a>=c) num[i].rkf=1,num[i].rks=0,num[i].rkt=2;
					else num[i].rkf=1,num[i].rks=2,num[i].rkt=0;
				}else num[i].rkf=2,num[i].rks=1,num[i].rkt=0;
			}
			num[i].fs=num[i].a[num[i].rkf]-num[i].a[num[i].rks];
			num[i].st=num[i].a[num[i].rks]-num[i].a[num[i].rkt];
		}
		ans=0;
		cnt[0]=0,cnt[1]=0,cnt[2]=0;
		for(int i=1;i<=n;i++){
			int k=num[i].rkf;
			s[k][++cnt[k]]={i,num[i].fs};
			ans+=num[i].a[k];
		}
		for(int i=0;i<3;i++){
			if(cnt[i]<=n/2) continue;
			sort(s[i]+1,s[i]+cnt[i]+1,cmp);
			for(int j=n/2+1;j<=cnt[i];j++){
				ans-=num[s[i][j].u].fs;
			}
		}
		cout<<ans<<"\n"; 
	}
	
	return 0;
}
//Ren5Jie4Di4Ling5%
