#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int T,n,x,y,z,ans,sum,f,t,k,cnt;
struct node{
	int a,b,c,maxx,minn,d,id;
}d[100010];
bool cmp(node a,node b){
	return a.maxx-a.d<b.maxx-b.d;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
			d[i].maxx=max(d[i].a,max(d[i].b,d[i].c));
			d[i].minn=min(d[i].a,min(d[i].b,d[i].c));
			d[i].d=d[i].a+d[i].b+d[i].c-d[i].maxx-d[i].minn;
			if(d[i].maxx==d[i].a){
				x++;
				d[i].id=1;
			}else if(d[i].maxx==d[i].b){
				y++;
				d[i].id=2;
			}else{
				z++;
				d[i].id=3;
			}
		}
		ans=f=0;
		if(x>n/2) f++;
		if(y>n/2) f++;
		if(z>n/2) f++;
		if(f==0){
			for(int i=1;i<=n;i++){
				ans+=d[i].maxx;
			}
			cout<<ans<<endl;
			x=y=z=0;
		}else{
			sort(d+1,d+n+1,cmp);
			t=max(x,max(y,z));
			if(t==x){
				k=1;
			}else if(t==y){
				k=2;
			}else{
				k=3;
			}
			cnt=0;
			for(int i=1;i<=n;i++){
				if(k==d[i].id){
					if(cnt<max(x,max(y,z))-(n/2)){
						cnt++;
						ans+=d[i].d;
					}else{
						ans+=d[i].maxx;
					}
				}else{
					ans+=d[i].maxx;
				}
			}
			cout<<ans<<endl;
		}
		x=y=z=0;
	}
	return 0;
}/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/