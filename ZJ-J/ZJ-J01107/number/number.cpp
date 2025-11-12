#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int tot;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++tot]=s[i];
	}
	sort(a+1,a+1+tot);
	for(int i=tot;i>=1;i--)
		cout<<a[i];
	return 0;
}
