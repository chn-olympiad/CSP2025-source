#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
int b[100005];
int c[100005];
int t[5];
void solve(){
	int n;
	cin>>n;
	int tt=0;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		int x=max(u,max(v,w));
		int y=min(u,min(v,w));
		y=u+v+w-x-y;
		tt+=x;
		if(x==u){
			a[i]=1;
		}else
		if(x==v){
			a[i]=2;
		}else
		if(x==w){
			a[i]=3;
		}
		b[i]=x-y;
		t[a[i]]++;
	}
	if(t[1]>n/2){
		int g=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				g++;
				c[g]=b[i];
			}
		}
		sort(c+1,c+1+g);
		for(int i=1;i<=t[1]-n/2;i++){
			tt-=c[i];
		}
	}
	if(t[2]>n/2){
		int g=0;
		for(int i=1;i<=n;i++){
			if(a[i]==2){
				g++;
				c[g]=b[i];
			}
		}
		sort(c+1,c+1+g);
		for(int i=1;i<=t[2]-n/2;i++){
			tt-=c[i];
		}
	}
	if(t[3]>n/2){
		int g=0;
		for(int i=1;i<=n;i++){
			if(a[i]==3){
				g++;
				c[g]=b[i];
			}
		}
		sort(c+1,c+1+g);
		for(int i=1;i<=t[3]-n/2;i++){
			tt-=c[i];
		}
	}
	for(int i=1;i<=n;i++){
		a[i]=0;
		b[i]=0;
		c[i]=0;
	}
	for(int i=1;i<=3;i++){
		t[i]=0;
	}
	cout<<tt<<endl;;
	tt=0;
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} /*
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