#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long l=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[l]=int(s[i]-'0');
			l++;
		}
	}
	sort(a+1,a+l);
	for(int i=l-1;i>=1;i--) cout<<a[i];
	return 0;
}