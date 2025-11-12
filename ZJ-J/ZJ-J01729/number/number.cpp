#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fi first
#define se second
#define lc (u<<1)
#define rc ((u<<1)|1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const ll N=1e6+10;
ll a[20];
string s,t;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			t+=(char)(i+'0');
		}
	}
	cout<<t;
	return 0;
}
