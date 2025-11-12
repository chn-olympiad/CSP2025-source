#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,t;
int a[3][101000];
int cg(int x,int y){
	return x*101000+y;
}
multiset<int> st[4][4];
int gtid(int k){
	return k%101000;
}
int gtdt(int k){
	return k/101000;
}
struct Man{
	int dat,id;
	bool operator<(const Man k)const{
		return dat>k.dat;
	}
}b[5];
int sum[5];
void ist(int i,int typ){
	sum[typ]++;
	int x=(typ+2)%3;
	int y=(typ+4)%3;
	if(a[typ][i]-a[x][i]>=0){
		st[typ][x].insert(cg(a[typ][i]-a[x][i],i));
	}
	if(a[typ][i]-a[y][i]>=0){
		st[typ][y].insert(cg(a[typ][i]-a[y][i],i));
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		for(int i=0;i<=3;i++){
			for(int j=0;j<=3;j++){
				st[i][j].clear();
			}
		}
		memset(sum,0,sizeof sum);
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[0][i],&a[1][i],&a[2][i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			b[1]={a[0][i],0};
			b[2]={a[1][i],1};
			b[3]={a[2][i],2};
			sort(b+1,b+3+1);
			if(sum[b[1].id]<n/2){
				ans+=b[1].dat;
				ist(i,b[1].id);
			}
			else{
				int res=ans+b[2].dat;
				int x=(b[1].id+2)%3;
				int y=(b[1].id+4)%3;
				auto it1=st[b[1].id][x].begin();
				auto it2=st[b[1].id][y].begin();
				int K1=*it1,K2=*it2;
				int res1=ans-gtdt(K1)+b[1].dat;
				int res2=ans-gtdt(K2)+b[1].dat;
				if(res>=res1&&res>=res2){
					ans=res;
					ist(i,b[2].id);
				}
				else if(res1>=res&&res1>=res2){
					ans=res1;
					st[b[1].id][x].erase(K1);
					if(a[b[1].id][gtid(K1)]-a[y][gtid(K1)]>=0){
						st[b[1].id][y].erase(cg(a[b[1].id][gtid(K1)]-a[y][gtid(K1)],gtid(K1)));
					}
					sum[b[1].id]--;
					ist(i,b[1].id);
					ist(gtid(K1),x);
				}
				else{
					ans=res2;
					st[b[1].id][y].erase(K2);
					if(a[b[1].id][gtid(K2)]-a[x][gtid(K2)]>=0){
						st[b[1].id][x].erase(cg(a[b[1].id][gtid(K2)]-a[x][gtid(K2)],gtid(K2)));
					}
					sum[b[1].id]--;
					ist(i,b[1].id);
					ist(gtid(K2),y);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

