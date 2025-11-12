#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
long long a[N],flag=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[flag++]=s[i]-'0';
		}
	}
	sort(a,a+flag);
	for(long long i=flag-1;i>=0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
