#include<bits/stdc++.h>
using namespace std;
const int N=1e7+520;
string s;
int a[N];
long long cnt=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9') a[cnt++]=s[i]-'1'+1;
	}
	sort(a+1,a+cnt);
	for(int i=cnt-1;i>=1;i--) cout<<a[i]; 
	
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 

