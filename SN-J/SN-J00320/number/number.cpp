#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
const int maxn=1e6+10;
const int inf=1e18;
string s;
int t[20];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int siz=s.size();
	s=" "+s;
	for(int i=0;i<=10;i++){
		t[i]=0;
	}
	for(int i=1;i<=siz;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(t[i]>0){
			t[i]--;
			cout<<i;
		}
	}
	return 0;
}
//8min
