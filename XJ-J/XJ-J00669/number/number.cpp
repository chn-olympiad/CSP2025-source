#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	string s[n];
	char a[100];
	for (int i=0;i<n;i++)
	{
		cin >> s[i];
	}
	for (int i=0;i<n;i++)
	{
		if (s[i]>=0||s[i]<=9)
		{
			if (s[i]<=s[i+1])
			{
				s[i]=max;
				a[i]=s[i];
			}
			else 
			{
				s[i+1]=max;
				a[i]=s[i+1];
			}
		}
	}
	cout << a[i];
	return 0;
}
