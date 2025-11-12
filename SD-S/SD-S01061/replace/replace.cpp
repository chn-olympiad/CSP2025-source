#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
/*
2 1
ab ba
aab aba
aaab aaba
*/
const int N = 100010;
int n, m, wei1[N], wei2[N], nei1, nei2, cnt;
string s1[N], s2[N], t1, t2;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )
		{
			cin >> s1[i] >> s2[i];
			wei1[i] = s1[i].find('b');
			wei2[i] = s2[i].find('b');
		}
		
	
	for(int i = 1; i <= m; i ++ )
		{
			int cnt = 0;
			cin >> t1 >> t2;
			if(t1.size() != t2.size()) 
			{
				cout << 0 << endl;
				continue;
			}
			nei1 = t1.find('b');
			nei2 = t2.find('b');
			for(int j = 1; j <= n; j ++)//¿ªÊ¼ÅÐ¶ÏÀ² 
			{
				if(nei1 >= wei1[j] && t1.size()-nei1 >= s1[j].size()-wei1[j])
				if(t2[nei1 + wei2[j] - wei1[j]] == 'b') 
				cnt++;
			}
			cout << cnt << endl;
		}
	return 0;//Ren5Jie4Di4Ling5%
 }

