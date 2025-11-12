#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string d;
	cin>>s;
	long long a[s.length()];
	for(int i=0;i<=s.length();i++)
	{
		if((int)(s[i])<=57 && (int)(s[i])>=48){
			d+=s[i];
		}
	}
	for(int i=0;i<=d.length();i++){
		a[i]=(long long)(d[i]);
	}
	sort(a,a+d.length()+1,cmp);
	for(int i=0;i<=d.length();i++){
		d[i]=(char)(a[i]);
	}
	cout<<d;
	return 0;
} 
