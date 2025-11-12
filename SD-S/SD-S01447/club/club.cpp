#include<bits/stdc++.h>
using namespace std;
#define re(i,n) for(int i=1;i<=n;i++)
#define pe(i,n) for(int i=n;i>=1;i--)
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
#define CIOO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define lowbit(x) (x & -x)
const int N=1e5+5;
int n,a[N][3];
pair<int,pii> b[N];
int vis[N],tag[N];
int x,y,z;
bool chk(){
	return (x<=n/2&&y<=n/2&&z<=n/2);
}
void Main(){
	cin>>n;
	re(i,n)tag[i]=-1;
	x=0,y=0,z=0;
	ll now=0;
	re(i,n){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		int mx=max({a[i][0],a[i][1],a[i][2]});
		if(a[i][0]==mx)tag[i]=0,x++;
		else if(a[i][1]==mx)tag[i]=1,y++;
		else if(a[i][2]==mx)tag[i]=2,z++;
		now+=mx;
	}
	if(chk()){
		cout<<now<<'\n';
		return;
	}
	re(i,n)vis[i]=0;
	if(y>n/2){
		re(i,n)swap(a[i][0],a[i][1]);
		re(i,n){
			if(tag[i]==0)tag[i]=1;
			else if(tag[i]==1)tag[i]=0;
		}
		swap(x,y);
	}
	if(z>n/2){
		re(i,n)swap(a[i][0],a[i][2]);
		re(i,n){
			if(tag[i]==0)tag[i]=2;
			else if(tag[i]==2)tag[i]=0;
		}
		swap(x,z);
	}
	int tp=0;
	re(i,n){
		if(tag[i]==0){
			b[++tp]=mkp(a[i][1]-a[i][0],mkp(i,1));
			b[++tp]=mkp(a[i][2]-a[i][0],mkp(i,2));
		}
	}
	sort(b+1,b+tp+1);
	pe(i,tp){
		if(chk())break;
		if(vis[b[i].se.fi])continue;
		if(b[i].se.se==1&&y<n/2){
			vis[b[i].se.fi]=1;
			x--;
			y++;
			now+=b[i].fi;
		}
		if(b[i].se.se==2&&z<n/2){
			vis[b[i].se.fi]=1;
			x--;
			z++;
			now+=b[i].fi;
		}
	}
	cout<<now<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	CIOO;
	int T=0;
	cin>>T;
	while(T--)Main();
	return 0;
}
