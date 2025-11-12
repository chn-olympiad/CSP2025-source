#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
using namespace std;
const int N=1e5+5;
const int P=1e9+7;
int a[N][4];
inline int read(){
	int x=0,f=1;
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
void solve()
{
	priority_queue<pair<int,int>,vector<pair<int,int> > > q1,q2,q3;
	priority_queue<pair<int,int>,vector<pair<int,int> > > p1,p2,p3;
	int n;
	n=read();
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=3;++j){
			a[i][j]=read();
		}
		int a1=a[i][1],a2=a[i][2],a3=a[i][3];
		if(a1>=a2&&a1>=a3){
			q1.push({max(a2,a3)-a1,i});
			ans+=a1;
		}
		else if(a2>=a1&&a2>=a3){
			q2.push({max(a1,a3)-a2,i});
			ans+=a2;
		}
		else if(a3>=a1&&a3>=a2){
			q3.push({max(a1,a2)-a3,i});
			ans+=a3;
		}
	}
	while((int)q1.size()>(n/2)){
		int maxn=q1.top().first,i=q1.top().second;
		q1.pop();
		ans-=a[i][1];
		if(maxn==a[i][2]-a[i][1]){
			//ans+=maxn;
			p2.push({maxn,i});
		}
		else{
			//ans+=maxn;
			p3.push({maxn,i});
		}
	}
	while((int)q2.size()>(n/2)){
		int maxn=q2.top().first,i=q2.top().second;
		q2.pop();
		ans-=a[i][2];
		if(maxn==a[i][1]-a[i][2]){
			p1.push({maxn,i});
		}
		else{
			//ans+=maxn;
			p3.push({maxn,i});
		}
	}
	while((int)q3.size()>(n/2)){
		int maxn=q3.top().first,i=q3.top().second;
		q3.pop();
		ans-=a[i][3];
		if(maxn==a[i][2]-a[i][3]){
			p2.push({maxn,i});
		}
		else{
			//ans+=maxn;
			p1.push({maxn,i});
		}
	}
	while(p1.size()&&(int)q1.size()<=(n/2)){
		int i=p1.top().second;
		p1.pop();
		ans+=a[i][1];
		q1.push({a[i][1],i});
	}
	while(p2.size()&&(int)q2.size()<=(n/2)){
		int i=p2.top().second;
		p2.pop();
		ans+=a[i][2];
		q2.push({a[i][2],i});
	}
	while(p3.size()&&(int)q3.size()<=(n/2)){
		int i=p3.top().second;
		p3.pop();
		ans+=a[i][3];
		q3.push({a[i][3],i});
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}

