#include<bits/stdc++.h>
using namespace std;

const int maxx=1e3;
int n,m,c[maxx],a[maxx],ans;
bool flag[maxx];
string s;

void cheak(){
	int sum1=0,sum2=0;
	for (int i=1;i<=n;i++){
		if (s[i-1]=='1'&&sum2<c[a[i]]) sum1++;
		else sum2++;
	}
	if (sum1>=m) ans++;
}

void dfs(int k){
	if (k>n){
		cheak();
		return;
	}
	for (int i=1;i<=n;i++){
		if (!flag[i]){
			flag[i]=1;
			a[k]=i;
			dfs(k+1);
			flag[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for (int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
