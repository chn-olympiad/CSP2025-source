#include<bits/stdc++.h>
#define int long long 
#define O1145 ios::sync_with_stdio(false);
#define O1919 cin.tie(0),cout.tie(0);
#define mid ((l+r)>>1)
using namespace std;
const int N=1e5+5;
string s;
int n,sum[10];
signed main(){
//	O1145 O1919          
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	cin>>s;n=s.size();
	for(int i=0;i<n;i++)if('0'<=s[i]&&s[i]<='9')sum[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		while(sum[i])cout<<i,sum[i]--;
	}
	return 0;
}
