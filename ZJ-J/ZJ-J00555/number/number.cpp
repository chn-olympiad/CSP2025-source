#include<bits/stdc++.h>
using namespace std;
string str; 
int n;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		char s=str[i];
		if(s>='0'&&s<='9') a[++n]=s-'0';
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

