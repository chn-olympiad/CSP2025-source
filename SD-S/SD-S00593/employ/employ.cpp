#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000,mod=998244353;
int br[N],n,m,cnt=0,p=0;
bool used[N],f=1,cd[N];
char c;
ll dfs(int d,int lot,int on){
	ll res=0;
	if(on>=m) res=1;
	if(d==n) return res;
	for(int i=0;i<n;i++){
		if(lot>=br[i]&&!used[i]){
			used[i]=1;
			res+=dfs(d+1,lot+1,on);
			res%=mod;
			used[i]=0;
		}else if(!used[i]){
			used[i]=1;
			res+=dfs(d+1,lot+int(cd[d]==0),on+int(cd[d]==1));
			res%=mod;
			used[i]=0;
		}
	}
	return res;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> c;
		if(c=='0'){
			f=0;
			cd[i]=0;
		}else{
			cnt++;
			cd[i]=1;
			if(cnt==m){
				p=cnt;
			}
		}
	}
	int cntbr=0;
	for(int i=0;i<n;i++){
		cin >> br[i];
		if(br[i]!=0) cntbr++;
	}
	if(cnt<m||cntbr<0){
		cout << 0;
		return 0;
	}
	cout << dfs(0,0,0);
	return 0;
} 
/*
3 2
101
1 1 2
*/
