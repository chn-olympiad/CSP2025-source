#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000009];
long long c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0')a[++c]=s[i];
	}
	sort(a+1,a+c+1);
	for(int i=c;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
