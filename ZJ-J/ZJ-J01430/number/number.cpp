#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
string s;
int a[N],cnt;
signed main(){
//	system("fc number.out number4.ans");
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(isdigit(s[i])){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
