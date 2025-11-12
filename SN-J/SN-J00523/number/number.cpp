#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[10*10*10*10*10*10+10];
	cin>>s;
	long long l=strlen(s);
	sort(s,s+l);
	if(s[l-1]<='9'){
		for(long long i=0;i<l;i++){
			cout<<s[l-1-i];
		}
	}
	else{
		for(long long i=0;i<l;i++){
			if(s[l-1-i]<='9'){
				cout<<s[l-1-i];
			}
		}
	}
	return 0;
}
