#include<bits/stdc++.h>
using namespace std;
const int q=1e6+10;
int a[q],ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans++;
			a[ans]=s[i]-'0';
		}
	}
	sort(a+1,a+ans+1,greater<int>());
	if(a[1]==0) cout<<0;
	else
		for(int i=1;i<=ans;i++) cout<<a[i];
	return 0;
}
//#Shang4Shan3Ruo6Shui4
