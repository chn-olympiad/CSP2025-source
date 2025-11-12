#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin >> a;
	int sb[a+1];
	for(int i = 1;i <= a;i++)
	{
		cin >> sb[i];
	}
	if(a==3)
	{
		int a1 = max(sb[1],max(sb[2],sb[3]));
		int a2 = sb[1] + sb[2] + sb[3];
		if(a1<(a2-a1))
		{
			cout << 1;
		}
		else
		cout << 0;
	}
	else
	{
		cout << (a+1)*a/2;
	}
	return 0;
}
