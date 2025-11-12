#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int vec[N],tot=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s,a,b;
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			vec[tot++]=s[i]-'0';
	}
	sort(vec,vec+tot,cmp);
	for(int i=0;i<tot;i++)
	{
		cout << vec[i];
	}
//	for(int i=0;i<s.size();i++)
//	{
//		if(s[i]>='0' && s[i]<='9')
//		{	
//			int l=0,r=a.size(),ans=0,mid=0;
//			while(l<=r)
//			{
//				mid=(l+r)/2;
//				if(a[mid]>s[i])
//				{
//					l=mid+1;
//				}
//				else
//				{
//					r=mid-1;
//					ans=mid;
//				}
//			}
//			a.insert(ans,1,s[i]);
//		}
//	}
//	cout << a;
	return 0;
}