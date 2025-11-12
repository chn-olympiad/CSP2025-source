#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e6+100;
string st;
LL n,a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>st;
	for(int i=0;i<st.size();i++){
		if('0'<=st[i]&&st[i]<='9') a[++n]=st[i]-'0';
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--) cout<<a[i];
	return 0;
}