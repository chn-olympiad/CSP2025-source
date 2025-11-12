#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int s[4],cnt[4];
int c[N],d[N];
struct node{
	int x,y,z;
	int fi,se,th;
}a[N];
void solve(){
	memset(c,0,sizeof(c));
	cnt[1]=cnt[2]=cnt[3]=0;
	int n,sum=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		s[1]=x,s[2]=y,s[3]=z;
		sort(s+1,s+4);
		a[i].x=s[3],a[i].y=s[2],a[i].z=s[1];
		if(s[3]==x)
		  a[i].fi=1;
		if(s[3]==y)
		  a[i].fi=2;
		if(s[3]==z)
		  a[i].fi=3;
		if(s[2]==x)
		  a[i].se=1;
		if(s[2]==y)
		  a[i].se=2;
		if(s[2]==z)
		  a[i].se=3;
	}
	for(int i=1;i<=n;i++){
		int k=a[i].fi;
		c[++ans]=a[i].x;
		cnt[k]++;
		if(cnt[k]>n/2){
			bool f=true;
			int l,r,maxn=0;
			for(int j=1;j<=ans;j++){
				if(a[j].y+a[i].x>a[j].x+a[i].y){
					if(a[j].y+a[i].x-a[j].x+a[i].y>maxn)
						l=j,maxn=a[j].y+a[i].x-a[j].x+a[i].y;
					f=false;
				}
			}
			if(!f){
				c[l]=a[l].y;
				c[i]=a[i].x;
				cnt[a[l].fi]--;
				cnt[a[l].se]++;
			}
			if(f){
				c[i]=a[i].y;
				cnt[k]--;
				cnt[a[i].se]++;
			}
		}
	}
	for(int i=1;i<=ans;i++)
		sum+=c[i];
	cout<<sum<<"\n";
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
