#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[10]={};
	string s;
	cin>>s;
	for(int i=0;i<(int)s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9'){
			int b=s[i]-'0';
			a[b]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--)cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
