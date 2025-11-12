#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7,M=300,inf=1e18,mod=1e9+7;
string s;
int a[N],k;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--)cout<<a[i];
	return 0;
} 
