#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N = 2e5+5555;
int n,q; 
string s[N][2];
int len[N],pos[N];
string s1,s2;
bool ck1(string s)
{
	for(int i = 1;i <= n;i++)
	{
		int a[100] = {},cnt = 0;
		for(int j = 1;j <= len[i];j++)
		{
			if((int)(a[s[j]-'a'])){
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	
	for(int i = 1;i <= n;i++)
	{
		cin >> s[i][0] >> s[i][1];
		len[i] = s[i][0].length();
		for(int i = 1;i <= n;i++)
		{
//			if()
		}
	}
//	if(ck1())
//	{
//		
//		while(q--)
//		{
//			cin >> s1 >> s2;
//			if(ck2())
//			{
//				
//			}
//			cout << 0 << endl;
//		}
//		return 0;
//	}
		while(q--)
		{
			cin >> s1 >> s2;
			cout << 0 << endl;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
