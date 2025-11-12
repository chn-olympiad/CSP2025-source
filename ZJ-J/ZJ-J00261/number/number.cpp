#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=1e6+10;
int a[N];
int main(){
	IOS
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=0;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')
			a[++len]=s[i]-'0';	
	sort(a+1,a+len+1);
	if(a[len]==0){
		cout<<0;
		return 0;
	}
	for(int i=len;i>=1;i--)
		cout<<a[i];
	return 0;
}

