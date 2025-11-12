#include<bits/stdc++.h>
using namespace std;
string s;
int cnt=0;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
