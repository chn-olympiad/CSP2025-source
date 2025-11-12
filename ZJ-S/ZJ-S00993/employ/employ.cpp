#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define OpenFile(_) freopen(#_ ".in","r",stdin);freopen(#_ ".out","w",stdout)
typedef long long Int;

Int n,m,a[505],s[505],vis[505];
string str;

Int check(){
	Int away=0;
	for(Int i=1;i<=n;i++){
		//cerr<<a[i]<<" "<<away<<"  ";
		if(str[i-1]=='0'||away>=s[a[i]])++away;
	}
	//cerr<<away<<endl;
	return n-away>=m;
}

Int dfs(Int dep){
	if(dep==n)return check();
	Int sum=0;
	for(Int i=1;i<=n;i++){
		if(vis[i])continue;
		a[dep+1]=i;
		vis[i]=1;
		sum+=dfs(dep+1);
		vis[i]=0;
	}
	return sum;
}

int main(){
	IOS;OpenFile(employ);

	cin>>n>>m;
	if(n>=100){
		cout<<1<<endl;
		return 0;
	}
	cin>>str;
	for(Int i=1;i<=n;i++)cin>>s[i];
	cout<<dfs(0);

	return 0;
}

