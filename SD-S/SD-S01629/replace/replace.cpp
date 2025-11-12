#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,q;
string ti[N][2];
string cha[N][2];
vector<int> nxt[N];
void getnxt(string s,int len,int x)
{
	nxt[x].push_back(0);
	int k = 0;
	for(int i = 1;i < len;i++)
	{
		while(k > 0 && s[i] != s[k]) k = nxt[x][k-1];
		if(s[i] == s[k]) k++;
		nxt[x].push_back(k);
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> ti[i][0] >> ti[i][1];
		getnxt(ti[i][0],ti[i][0].length(),i);
	}
	for(int qq = 1;qq <= q;qq++)
	{
		int ans = 0;
		cin >> cha[qq][0] >> cha[qq][1];
		int lena = cha[qq][0].size();
		if(lena != (int)cha[qq][1].size())
		{
			cout << 0 << '\n';
			continue; 
		}
		for(int c = 1;c <= n;c++)
		{
			int lenb = ti[c][0].size();
			int j = 0;
			for(int i = 0;i < lena;i++)
			{
				while(j > 0 && cha[qq][0][i] != ti[c][0][j]) j = nxt[c][j-1];
				if(cha[qq][0][i] == ti[c][0][j]) j++;
				if(j == lenb)
				{//i-lenb+1 -- i
					int op1 = 0,op2 = 0;
					for(int d = i-lenb+1;d <= i;d++)
					{
						if(cha[qq][1][d] != ti[c][1][d-(i-lenb+1)]) 
						{
							op1 = 1;
							break;
						}
					}
					if(!op1)
					{
						for(int d = 0;d < i-lenb+1;d++)
						{
							if(cha[qq][0][d] != cha[qq][1][d])
							{
								op2 = 1;
								break;
							}
						}
						for(int d = i+1;d < lena;d++)
						{
							if(op2) break;
							if(cha[qq][0][d] != cha[qq][1][d])
							{
								op2 = 1;
								break;
							}
						}
						if(!op2) {
							ans++;
							break;
						}
					}
					j = 0;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
