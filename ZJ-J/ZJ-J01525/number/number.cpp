#include <bits/stdc++.h>
#define N 1000006
using namespace std;
string s;
int a[N],len;
int cnt=0,sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			a[++len]=s[i]-'0';
			cnt++;
			if(s[i]=='0')sum++;
		}
	}
	sort(a+1,a+len+1);
	if(cnt!=sum){
		for(int i=len;i>0;--i){
			cout<<a[i];
		}
	}
	else cout<<0;
	return 0;
}//#Shang4Shan3Ruo6Shui4
