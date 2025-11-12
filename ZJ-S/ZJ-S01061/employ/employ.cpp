#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e4+10;
const int MOD = 998244353;
i64 n,m;
i64 ans = 0;
string s;
bool S[N];
i64 C[N];
bool book[N];
//i64 path[N];
//bool PBook[N];
i64 dfs(i64 day,i64 Bad){
	
	if(day>n){
		if((n-Bad)>=m){
			return 1;
		}
		return 0;
	}
	i64 temp = 0;
	for(int i=1;i<=n;i++){
		if(!book[i]){
			book[i] = true;
			if(Bad<C[i] && S[day]){
				temp+=dfs(day+1,Bad);
				temp%=MOD;
			}
			else{
				temp+=dfs(day+1,Bad+1);
				temp%=MOD;
			}
			book[i] = false;
		}
	}
	return temp%=MOD;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++) S[i] = (s[i-1]=='0'?false:true);
	//for(int i=1;i<=n;i++) cout<<S[i];
	//cout<<endl;
	for(int i=1;i<=n;i++) cin >> C[i];
	cout << dfs(1,0);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}