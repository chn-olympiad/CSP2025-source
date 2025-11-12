//SN-J00787  ÍõìÏÂü 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int z=0,a[N];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	int lens=s.size()-1;
	for(int i=0;i<=lens;i++)
	{
		if(s[i]<='9'&&s[i]>='0') a[z++]=s[i]-'0';
	}
	sort(a,a+lens+1,cmp);
	z--;
	for(int i=0;i<=z;i++) printf("%d",a[i]);
	return 0;
}
