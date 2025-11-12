#include<bits/stdc++.h>
using namespace std;
int a[1000007];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num=0;
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++num]=s[i]-48;
		}
	}
	sort(a+1,a+1+num);
	for(int i=num;i>=1;i--){
		cout << a[i];
	}
	//#Shang4Shan3Ruo6Shui4
	return 0;
}
