#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,m,ans,mod=998244353;
vector<ll> a,x,c;
string s;
void go(int i,int d,int anss){
	anss=(anss*(c[i]-d+1))%mod;
	if(d>=m){
		(ans+=anss)%=mod;
	}
	//cout<<"<"<<i<<" "<<d<<" "<<anss<<" ";
	for(ll j=i+1;j<=n&&c[j]>=d;j++){
		if(s[j-1]!='0'){
			go(j,d+1,anss);
		}
	}
	//cout<<">";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	x.resize(n+5);//在这一位需要的最小忍耐力
	a.resize(n+5);
	c.resize(n+5);//有多少个人能在这一位
	cin>>s;
	for(int i=0,len=s.length(),cnt=0;i<len;i++){
		x[cnt+1]=i;
		cnt+=s[i]=='0';
	}
	for(int i=1;i<=n&&cin>>a[i];i++) {
		for(int j=1;j<=n&&a[i]>=x[j];j++){
			c[j]++;
		}
	}
	for(int i=1;i<=n-m+1;i++){
		go(i,1,1);
		//cout<<"<"<<ans<<">";
	}
	cout<<ans;
	
	
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 10
1 1 0 1 1 1 1 0 1 1
0 1 2 2 3 3 4 4 5 6
0 6 10 10 10 10 10 10 10 10

*/