#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,s,number,english;
	cin >> s >>n;
	for (int i = 0;i <= n;i++)
{
		if (s==number)
		{
			s+=number;
		}
		else
		{
			s+=0;
		}
	}
	cout << s;
	return 0;
}
