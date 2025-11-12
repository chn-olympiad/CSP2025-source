#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("Î´ÃüÃû4.in","r",stdin);
	freopen("Î´ÃüÃû4.out","w",stdout);
	string s[1882];	
	int a;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>s[i];
	}
	for(int i=1;i<=a;i++){
		if(s[i]<s[i+1]){
			s[i]=s[i+1];
			s[i+2]=s[i];
			s[i+1]=s[i+2];
			
		}
	}
	cout<<a;
	return 0;
}
