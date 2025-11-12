#include<bits/stdc++.h> 
using namespace std;
int a[100005];
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int j=0;
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+0,a+j+0,cmp);
	for(int i=0;i<=j-1;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
