#include<bits/stdc++.h>
using namespace std;
long long a[1000005],n,y;
string s,x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)x+=a[i]+'0';
	cout<<x;
	return 0;
}
