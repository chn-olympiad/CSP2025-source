#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
string s1;
int c[510];
bool vis[510];
ll ans=0;
ll mod=998244353;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	ans=1;
	for (int i=n;i>=1;i++){
		ans*=i;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
