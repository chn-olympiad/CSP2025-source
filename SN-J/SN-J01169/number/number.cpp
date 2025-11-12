//SN-J01169 马歆玥 西安滨河学校 
#include <bits/stdc++.h>
using namespace std;

string s;
int n,cnt;
int a[1000005];

bool cmp(int num1,int num2)
{
	return num1 > num2;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> s;
	int len = s.size();
	for(int i=0;i<len;i++)
		if(s[i] >= '0' && s[i] <= '9')
			a[++cnt] = s[i] - '0';
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
		cout << a[i];
	return 0;
}
