#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500010];
bool b=true;

int dfs(int d){
	if(d>=n-1) return 0;
	int cnt=0;
	int i=d;
	while(i<=n-1){
		if((a[i]==a[i+1])==(!k)){	
			if((a[i+1]==a[i+2])==(!k)) cnt=max(cnt,max(dfs(i+2)+1,dfs(i+3)+1));
			else cnt=max(cnt,dfs(i+2)+1);
		}
		i++;
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(b) b=a[i];
	}
	if(b){
		cout<<n/2;
	}
	else{
		cout<<dfs(1);
	}
	return 0;
}