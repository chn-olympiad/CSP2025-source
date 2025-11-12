#include<bits/stdc++.h>
using namespace std;
int a[1000005],l=0;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9') a[++l]=s[i]-'0';
	}
	sort(a+1,a+l+1);
	for(int i=l;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
