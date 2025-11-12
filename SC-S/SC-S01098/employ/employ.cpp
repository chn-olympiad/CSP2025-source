#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e2+10,Mod=998244353;
int n,m,c[N];
int ans,tol,sum,check[N];
string s;
int cal(int num){
	int res=1;
	for(int i=2;i<=num;i++){
		res*=i;
		res%=Mod;
	}
	return res;
}
void solve(int step){// 纯暴力写法+剪枝优化：预估8~20pts
/*

考虑优化：
1.当录取人数已经满足条件，显然往后无论如何排列都为合理；（可行性剪枝） 
2.若当前tol值已经可以使往后无论如何排列都不合理；（可行性剪枝） 

*/
	if(sum==m){
		ans=(ans+cal(n-step+1))%Mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(check[i]==true) continue;
		check[i]=true;
		if(s[step]=='0' or (s[step]=='1' and c[i]-tol<=0)){
			tol++;
			solve(step+1);
			tol--;
		}else{
			sum++;
			solve(step+1);
			sum--;
		}
		check[i]=false;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	solve(1);
	cout<<ans%Mod;
	return 0;
}
/*

3 2
101
1 1 2
2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
2204128
*/