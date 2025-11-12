#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000001],num,ans[10000001];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int j=9;j>=0;j--){
		for(int i=1;i<=a[j];i++){
			ans[num]=j;
			num++;
		}
	}
	for(int i=0;i<num;i++){
		cout<<ans[i];
	}
	
	return 0;
}
