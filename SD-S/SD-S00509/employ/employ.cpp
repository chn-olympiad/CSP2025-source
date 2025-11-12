//rp++
//love CCF 
#include<bits/stdc++.h>
using namespace std;
const int N=510,MOD=998244353;
int n,m,c[N],p[N];
bool s[N];
bool cmp(int x,int y){return x>y;}
bool check(){
	int cnt=0,f=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0||f>=c[p[i]]) f++;
		else cnt++;
	}
	return cnt>=m;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool flag=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		p[i]=i;
		char x;cin>>x;
		s[i]=x-'0';
		if(!s[i]) flag=0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(flag){
		sort(c+1,c+n+1,cmp);
		long long res=1;
		for(int i=1;i<=n;i++){
			if(c[i]) res=res*i%MOD;
			else break;
		}
		cout<<res;
		return 0;
	}
	int ans=0;
	do{
		ans+=check();
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
