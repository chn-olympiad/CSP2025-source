#include<bits/stdc++.h>

using namespace std;

string s;
int a[1000001],t=1;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' and s[i]>='0'){
			a[t]+=s[i]-'0';
			t++;
		}
	}
	sort(a+1,a+t);
	for(int i=t-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
	
 } 
