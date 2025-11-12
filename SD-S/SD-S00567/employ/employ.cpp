#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=505;
int n,m;
string s;
const ll MOD=998244353;
ll ans;
int c[N];
int isDifficult[N];
int theOrder[N];
int check() {
//	for(int i=1; i<=n; i++) {
//		cout<<theOrder[i]<<" ";
//	}
//	cout<<endl;
	int sumRun=0;
	int sumLu=0;
	for(int i=1; i<=n; i++) {
		//第i天，来了 theOrder[i]这个人
		if(isDifficult[i]==0) {
			sumRun++;
		} else {
			if(sumRun>=c[theOrder[i]]) {
				sumRun++;
			} else {
				sumLu++;
			}
		}
	}
//	cout<<"LU:"<<sumLu<<endl;
	return sumLu;
}
int check2() {
	int sumRun=0;
	int sumLu=0;
	for(int i=1; i<=n; i++) {
		if(sumRun>=c[theOrder[i]]) {
			sumRun++;
		} else {
			sumLu++;
		}
	}
	return sumLu;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		isDifficult[i+1]=s[i]-'0';
		//cout<<isDifficult[i]<<" ";
	}
	for(int i=1; i<=n; i++) {
		cin>>c[i];
		theOrder[i]=i;
	}
	if(n>18) {
		//特殊性质全是简单的，全排列的个数-不符合
		ll ans=1;
		for(int i=n; i>0; i--) {
			ans=(ans*i)%MOD;
		}
		sort(c+1,c+n+1);
		ll ans2=0;
		if(check2()<m) {
			ans2=(ans2+1)%MOD;
		}
		while(next_permutation(c+1,c+n+1)) {
			if(check2()>=m) {
				ans2=(ans2+1)%MOD;
			}
		}
		cout<<(ans%MOD-ans2%MOD+MOD)%MOD<<endl;
		//cout<<ans<<endl;
	} else {
		if(check()>=m) {
			ans=(ans+1)%MOD;
		}
		while(next_permutation(theOrder+1,theOrder+n+1)) {
			if(check()>=m) {
				ans=(ans+1)%MOD;
			}
		}
		cout<<ans<<endl;
	}

	return 0;

}

