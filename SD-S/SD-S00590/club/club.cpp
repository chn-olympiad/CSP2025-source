#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e6+10,M=410;
ll t,n,a[N][5],f[M][M][M],ans;
struct dazhao{
	ll id,x;
	bool operator <(const dazhao &op) const{
		return x<op.x;
	}
};
multiset<dazhao> st[4];
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return ;
}
void init(){
	ans=0;
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=n;j++){
			for(ll k=0;k<=n;k++){
				f[i][j][k]=0;
			}
		}
	}
}
ll check(ll i){
	if(a[i][1]>a[i][2] and a[i][1]>a[i][3]) return 1;
	if(a[i][2]>a[i][1] and a[i][2]>a[i][3]) return 2;
	return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		bool p=true;
		n=read();
		for(ll i=1;i<=n;i++){
			a[i][1]=read();a[i][2]=read();a[i][3]=read();
			if(a[i][2]!=0 or a[i][3]!=0) p=false;
		}
		if(n<=400){
			init();
			for(ll i=1;i<=n;i++){
				for(ll x=0;x<=i;x++){
					for(ll y=0;x+y<=i;y++){
						ll z=i-x-y;
						if(x) f[i][x][y]=max(f[i][x][y],f[i-1][x-1][y]+a[i][1]);
						if(y) f[i][x][y]=max(f[i][x][y],f[i-1][x][y-1]+a[i][2]);
						if(z) f[i][x][y]=max(f[i][x][y],f[i-1][x][y]+a[i][3]);
					}
				}
			}
			for(ll x=0;x<=n/2;x++){
				for(ll y=0;y<=n/2;y++){
					ll z=n-x-y;
					if(z>n/2) continue;
					ans=max(ans,f[n][x][y]);
				}
			}
			write(ans);
			putchar('\n');
		}
		else if(p==true){
			ans=0;
			priority_queue<ll,vector<ll>,greater<ll> > dela;
			for(ll i=1;i<=n;i++){
				dela.push(a[i][1]);
				ans+=a[i][1];
				if(dela.size()>n/2) ans-=dela.top(),dela.pop();
			}
			write(ans);
			putchar('\n');
		}
		else{
			ans=0;
			st[1].clear();st[2].clear();st[3].clear();
			for(ll i=1;i<=n;i++){
				if(check(i)==1){
					if(st[1].size()<n/2){
						st[1].insert({i,a[i][1]});
						ans+=a[i][1];
					}
					else{
						ll id=(*st[1].begin()).id;
						ll ans2=ans+a[i][2],ans3=ans+a[i][3],ans12=ans-a[id][1]+a[i][1]+a[id][2],ans13=ans-a[id][1]+a[i][1]+a[id][3];
						ll mx=max(ans2,max(ans3,max(ans12,ans13)));
						if(ans2==mx){
							ans+=a[i][2];
							st[2].insert({i,a[i][2]});
						}
						else if(ans3==mx){
							ans+=a[i][3];
							st[3].insert({i,a[i][3]});
						}
						else if(ans12==mx){
							ans-=a[id][1];ans+=a[i][1];ans+=a[id][2];
							st[1].erase(st[1].begin());
							st[1].insert({i,a[i][1]});
							st[2].insert({id,a[id][2]});
						}
						else{
							ans-=a[id][1],ans+=a[i][1],ans+=a[id][3];
							st[1].erase(st[1].begin());
							st[1].insert({i,a[i][1]});
							st[3].insert({id,a[id][3]});
						}
					}
				}
				else if(check(i)==2){
					if(st[2].size()<n/2){
						st[2].insert({i,a[i][2]});
						ans+=a[i][2];
					}
					else{
						ll id=(*st[2].begin()).id;
						ll ans1=ans+a[i][1],ans3=ans+a[i][3],ans12=ans-a[id][2]+a[i][2]+a[id][1],ans23=ans-a[id][2]+a[i][2]+a[id][3];
						ll mx=max(ans1,max(ans3,max(ans12,ans23)));
						if(ans1==mx){
							ans+=a[i][1];
							st[1].insert({i,a[i][1]});
						}
						else if(ans3==mx){
							ans+=a[i][3];
							st[3].insert({i,a[i][3]});
						}
						else if(ans12==mx){
							ans-=a[id][2];ans+=a[i][2];ans+=a[id][1];
							st[2].erase(st[2].begin());
							st[2].insert({i,a[i][2]});
							st[1].insert({id,a[id][1]});
						}
						else{
							ans-=a[id][2],ans+=a[i][2],ans+=a[id][3];
							st[2].erase(st[2].begin());
							st[2].insert({i,a[i][2]});
							st[3].insert({id,a[id][3]});
						}
					}
				}
				else{
					if(st[3].size()<n/2){
						st[3].insert({i,a[i][3]});
						ans+=a[i][3];
					}
					else{
						ll id=(*st[3].begin()).id;
						ll ans1=ans+a[i][1],ans2=ans+a[i][2],ans13=ans-a[id][3]+a[i][3]+a[id][1],ans23=ans-a[id][3]+a[i][3]+a[id][2];
						ll mx=max(ans1,max(ans2,max(ans13,ans23)));
						if(ans1==mx){
							ans+=a[i][1];
							st[1].insert({i,a[i][1]});
						}
						else if(ans2==mx){
							ans+=a[i][2];
							st[2].insert({i,a[i][2]});
						}
						else if(ans13==mx){
							ans-=a[id][3];ans+=a[i][3];ans+=a[id][1];
							st[3].erase(st[3].begin());
							st[3].insert({i,a[i][3]});
							st[1].insert({id,a[id][1]});
						}
						else{
							ans-=a[id][3],ans+=a[i][3],ans+=a[id][2];
							st[3].erase(st[3].begin());
							st[3].insert({i,a[i][3]});
							st[2].insert({id,a[id][2]});
						}
					}
				}
				//cout<<st[1].size()<<" "<<st[2].size()<<" "<<st[3].size()<<" "<<ans<<endl;
			}
			write(ans);
			putchar('\n');
		}
	}
	return 0;
}
