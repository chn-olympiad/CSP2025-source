#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define int long long

int T,n,ans;
int sm[5];
int v[5];

struct node{
	int maxx;
	int idx;
	int midd;
}a[N];
node b[N];
bool cmp(node x,node y){
	//if(x.maxx==y.maxx){
		//return x.midd<y.midd;
	//}
	//return x.maxx>y.maxx;
	double q=x.maxx;
	double w=x.midd;
	double e=y.maxx;
	double r=y.midd;
	return (q/w)>(e/r);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		memset(v,0,sizeof(v));
		cin>>n;
		int m=n/2;
		for(int i=1;i<=n;++i){
			int x,y,z;
			cin>>x>>y>>z;
			x+=1;
			y+=1;
			z+=1;
			sm[1]=x;
			sm[2]=y;
			sm[3]=z;
			sort(sm+1,sm+3+1);
			a[i].maxx=sm[3];
			a[i].midd=sm[2];
			//cout<<sm[1]<<" "<<sm[2]<<'\n';
			if(x>=y&&x>=z){
				a[i].idx=1;
			}
			else if(y>=x&&y>=z){
				a[i].idx=2;
			}
			else if(z>=y&&z>=x){
				a[i].idx=3;
			}
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;++i){
			v[a[i].idx]++; 
			if(v[a[i].idx]>m){
				ans+=a[i].midd;
			}
			else{
				ans+=a[i].maxx;
			}
		}
		cout<<ans-n<<'\n';
	}
	return 0;
}
