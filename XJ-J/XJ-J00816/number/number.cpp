#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[114514];
ll tmp=1;

bool cmp(int a,int b)
{
	return a>b;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//48-57
	string s;
	cin>>s;

	for(int i=0; i<=s.size(); i++)
		if(((int)s[i])>=48 && (((int)s[i])<=57) ) {
			a[tmp]=s[i]-'0';tmp++;
		}
	if(tmp==1)
	{
		cout<<a[1];
		return 0;
	}
	
	
	sort(a+1,a+tmp,cmp);
	
	//if(a[1])
	
	//for(int i=1;i<=tmp;i++)
	//{
	//	for(int j=i;j<=tmp;j++)
	//	{
	//		for(int k=j;k<=tmp;k++)
	//		{
	//			if(a[i]==a[j]||a[i]==a[k]||a[j]==a[k])continue;
	//			
	//			
	//		}
//	}
	//}

	for(int i=1;i<tmp;i++)cout<<a[i];
	return 0;
}


























