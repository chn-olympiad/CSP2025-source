//SN-J00147 刘逸扬 西安辅轮中学 
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){//降序 
	return a > b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num[100000] = {};
	string s;
	cin >> s;
	int n = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= 48 && s[i] <= 57)//为数字 
		{
			num[n] = s[i] - 48;
			n++;
		}
	}
	sort(num,num+n,cmp);
	for(int i = 0; i < n; i++)
	{
		cout << num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
