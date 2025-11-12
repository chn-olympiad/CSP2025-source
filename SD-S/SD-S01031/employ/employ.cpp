#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n,m,c[N],tot,book[N],a[N],ans;
bool tepan=1;
char s[N];

void dfs(int k){
	if(k==n+1){
		int tot=0,res=n;//101   1 1 2
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){
				res--;
				tot++;
			}
			else if(tot>=a[i]){
				tot++;
				res--;
			}
		}
		if(res>=m){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!book[i]){
			book[i]=1;
			a[k]=c[i];
			dfs(k+1);
			book[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')tepan=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(tot>=c[i]){
			tot++;
		}
	}
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}
/*
3 2
101
1 1 2
*/
