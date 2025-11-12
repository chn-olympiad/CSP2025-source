//SN-J01169 马歆玥 西安滨河学校 
#include <bits/stdc++.h>
using namespace std;

long long n,k,num0,num1,numk;
long long a[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i] == 0)
			num0++;
		if(a[i] == 1)
			num1++;
		if(a[i] == k)
			numk++;
	}
	if(k == 0)
		cout << num1/2 + num0;
	else if(k == 1)
		cout << num1;
	else
		cout << numk;
	return 0;
}
