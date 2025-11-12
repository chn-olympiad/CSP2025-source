#include<bits/stdc++.h>
using namespace std;
string er(int a)
{
	string sum1 = "";
	while(a != 0)
	{
		sum1 += (a%2+'0');
		a /= 2;
	}
	reverse(sum1.begin(),sum1.end());
	return sum1;
}
string xor1(string a,string b)
{
	string das = "";
	int a1 = a.size();
	int b1 = b.size();
	if(a1 > b1)
	{
		reverse(b.begin(),b.end());
		b += '0' * (a1-b1);
		reverse(b.begin(),b.end());
		for(int i = 1;i <= a1;i++)
		{
			if(a[i] == b[i])
			{
				das += '0';
			}
			else
			{
				das += '1';
			}
		}
	}
	else if(a1 < b1)
	{
		reverse(a.begin(),a.end());
		a += '0' * (b1-a1);
		reverse(a.begin(),a.end());
		for(int i = 1;i <= b1;i++)
		{
			if(a[i] == b[i])
			{
				das += '0';
			}
			else
			{
				das += '1';
			}
		}
	}
	return das;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin >> n >> k;
	cout << n / 2;
	return 0;
}

