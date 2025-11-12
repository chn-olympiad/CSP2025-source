#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int mp,n,vis[N];

struct choice{
	int val;
	int index;
	int num;
	operator < (struct choice &a)const{
		return a.val < val;
	}
}ch[3*N]; 

void solve()
{
	cin >> n;
	for(int i = 1;i <= n;++i)
	{
		for(int j = 1 ;j <= 3;j++)
		{
			int index = 3*(i-1)+j;
			cin >> ch[index].val;
			ch[index].index = i;
			ch[index].num = j;
		}
	}
	mp = n/2;
	
	sort(ch+1,ch+3*n+1);
	int counta = 0;
	int countb = 0;
	int countc = 0;
	int ans = 0;
	for(int i = 1;i <= 3*n;++i)
	{
		if(!vis[ch[i].index])
		{
			vis[ch[i].index]  = 1;
			if(ch[i].num == 1 && counta < mp)++counta,ans+=ch[i].val;
			if(ch[i].num == 2 && countb < mp)++countb,ans+=ch[i].val;
			if(ch[i].num == 3 && countc < mp)++countc,ans+=ch[i].val;
		cout << ans << endl;
		}
		if(counta + countb + countc == n) break;
	}
	cout << ans << endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int _;
	cin >> _;
	while(_--)solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
