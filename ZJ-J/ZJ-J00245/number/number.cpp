#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10;
int a[N],sum;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++sum]=s[i]-'0';
	}
	sort(1+a,1+a+sum);
	while(a[sum]==0&&sum>1) sum--;
	for(int i=sum;i>=1;i--) cout<<a[i];
	return 0;
}
