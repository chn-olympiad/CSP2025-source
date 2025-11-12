#include<iostream>
#include<algorithm>
using namespace std;
int a[1000005],jishu=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9){
			jishu++;
			a[jishu]=s[i]-'0';
		}
	}
	sort(a+1,a+jishu+1);
	for(int i=jishu;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
