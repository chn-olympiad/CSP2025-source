#include <iostream>
#include <cstring>
int a[10]={0};
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++) cout<<i;
	cout<<endl;
	return 0;
}
