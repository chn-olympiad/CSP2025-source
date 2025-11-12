#include<bits/stdc++.h>
using namespace std;
string n;
int m[10010],head;
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++)
		if(n[i]<='9'&&n[i]>='0')
			m[head++]=n[i]-'0';
	
	sort(m,m+head,cmp);
	for(int i=0;i<head;i++)
		cout<<m[i];
	
	return 0;
}
