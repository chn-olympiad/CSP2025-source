#include<bits/stdc++.h>
using namespace std;

const int M=500,MOD=998244353;
char eaxm[M+10];
long long n,m,c[M+10],ans=0;
bool hsh[M+10];

void dfs(long long num,long long l){
	if(num==n){
		if(l>=m){
			ans++;
			ans%=MOD;
		}
		return;
	}
	for(int i=1; i<=n; i++){
		if(hsh[i]==0 && num<=c[i]){
			num++;
			hsh[i]=1;
			if(eaxm[num]=='1'){
				l++;
			}
			//cout<<i<<" "<<l<<endl;
			dfs(num,l);
			num--;
			hsh[i]=0;
			if(eaxm[num]=='1'){
				l--;
			}
		}
	}
}

int main(){

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>eaxm[i]; 
	}
	for(int i=1; i<=n; i++){
		cin>>c[i];
	}
	
	memset(hsh,0,sizeof(hsh));
	dfs(0,0);
	
	cout<<ans;
	
	return 0;
}
//我如果真的会做我就不会在这里写这种东西，哪怕我只会骗点分
//今年普及没进，真没招了，今年S组太难了，第一道估计是绿题起步，DP状态转移方程难想，贪心推一下就直接pass
//NOI这一块真的越来越深了啊……
//希望不要把我玩身份证当成是作弊，毕竟我是真的手贱，身份证本来也没撕膜（
//这题也骗不了两分啊…… 