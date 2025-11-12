#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(isdigit(s[i])){
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
