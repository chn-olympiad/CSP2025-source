#include<iostream>
#include<algorithm>
using namespace std;
string s;
int a[1000005];
int len1,x,y;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[len1]=s[i]-'0';
			len1++;
		}
	}
	sort(a,a+len1);
	for(int i=len1-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
 } 
