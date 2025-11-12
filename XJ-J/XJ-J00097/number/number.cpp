#include<bits/stdc++.h>
using namespace std;
const long long int N=1e6+5;
long long int ans[N] , n ;
string s ;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s ;
	long long int len=s.size();
	for(long long int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			int a=0;
			if(s[i]=='1') a=1;
			if(s[i]=='2') a=2;
			if(s[i]=='3') a=3;
			if(s[i]=='4') a=4;
			if(s[i]=='5') a=5;
			if(s[i]=='6') a=6;
			if(s[i]=='7') a=7;
			if(s[i]=='8') a=8;
			if(s[i]=='9') a=9;
			ans[++n]=a;
		}
	}
	sort(ans+1,ans+1+n);
	for(long long int i=n;i>=1;i--)
		cout << ans[i];
	return 0;
}
