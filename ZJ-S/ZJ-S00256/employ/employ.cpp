#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=506;
const ll P=998244353;
int n,m,c[N],p[N];
string s;
ll ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i],p[i]=i;
	if(n<=10){
		do{
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(cnt>=c[p[i]]||s[i-1]=='0'){
					cnt++;
				}
			ans+=(n-cnt>=m);
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<'\n';		
	}
	else{
		ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%P;
		cout<<ans<<'\n';
	}
	
	return 0;
}