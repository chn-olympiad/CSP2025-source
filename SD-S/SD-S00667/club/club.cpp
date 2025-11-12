#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')  f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1ll)+(x<<3ll)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int const N=1e5+5;
int n,m,ans,cnt;
int a[N][5],b[N],t[5];
vector<int> tmp[5];
vector<int> num;
void Solve(){
	n=read();
	ans=0;
	memset(b,0,sizeof b);
	memset(t,0,sizeof t);
	for(int i=1;i<=3;i++){
		tmp[i].clear();
	}
	for(int i=1;i<=n;i++){
		int res=0,p=1;
		for(int j=1;j<=3;j++){
			a[i][j]=read();
			if(res<a[i][j]){
				res=a[i][j];
				p=j;
			}
		}
		b[i]=p;
		ans+=res;
		t[p]++;
		tmp[p].pb(i);
	}
	if(t[1]<=n/2&&t[2]<=n/2&&t[3]<=n/2){
		cout<<ans<<'\n';
		return;
	} 
	if(t[1]>n/2){
		num.clear();
		for(auto ed:tmp[1]){
			num.pb(a[ed][1]-max(a[ed][2],a[ed][3]));
		}
		sort(num.begin(),num.end());
		for(int i=0;i<t[1]-n/2;i++)  ans-=num[i];
	}
	if(t[2]>n/2){
		num.clear();
		for(auto ed:tmp[2]){
			num.pb(a[ed][2]-max(a[ed][3],a[ed][1]));
		}
		sort(num.begin(),num.end());
		for(int i=0;i<t[2]-n/2;i++)  ans-=num[i];
	}
	if(t[3]>n/2){
		num.clear();
		for(auto ed:tmp[3]){
			num.pb(a[ed][3]-max(a[ed][2],a[ed][1]));
		}
		sort(num.begin(),num.end());
		for(int i=0;i<t[3]-n/2;i++)  ans-=num[i];
	}
	cout<<ans<<'\n'; 
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int T=read();
    while(T--){
    	Solve();
	}
	return 0;
}
