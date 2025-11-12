#include<bits/stdc++.h>
using namespace std;
long long a[1000005],l=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s[i]=s[i]-'0';
			a[l]=s[i];
			l+=1;
		}
	}
	sort(a+1,a+l);
	for(int i=1;i<l;i++){
		cout<<a[l-i];
	}
	return 0;
}


