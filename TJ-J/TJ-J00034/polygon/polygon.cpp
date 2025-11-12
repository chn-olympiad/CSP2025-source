#include <bits/stdc++.h>

using namespace std;

int ans = 0;
short o[50001];
short n;

bool get(int n,int& top){
	short sum=0;
	short maxn=0;
	short u;
	int i=0;
	while(n!=0){
		u = (n&1)*o[i];
		sum+=u;
		maxn = max(maxn,u);
		n=n>>1;
		i++;
	}
	top = i;
	return sum > maxn*2;
}

void dfs(int sum){
	int top;
	ans+=get(sum,top);
	ans = ans%998244353;
	//ut<<top<<endl;
	//cout<<leng<<" "<<sum<<endl;
	if(top>=n)return;
	for(short i = top;i <  n;i++){
		dfs((sum|(1<<i)));
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	
	cin>>n;
//out<<n<<endl;
	for(int i = 0;i < n;i++){
		cin>>o[i];
	}

	//bool s[5001]={1,1,1,1,1};
	//cout<<get(14,ans);
	dfs(0);
	cout<<ans;
	return 0;
}
