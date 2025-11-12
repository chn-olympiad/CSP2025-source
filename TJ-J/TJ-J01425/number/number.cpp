#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[1000006],top;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0')
			a[++top]=s[i]-'0';
	}
	sort(a+1,a+top+1);
	for(int i=top;i>0;i--)
		cout<<a[i];
	return 0;
}//#Shang4Shan3Ruo6Shui4
