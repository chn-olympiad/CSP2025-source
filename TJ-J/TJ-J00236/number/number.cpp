#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int m;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	int n = a.length();
	for(int i = 0;i < n;i++)
	{
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')
		{
			arr[m] = a[i]-'0';
			m++;
		}
	}
	sort(arr,arr+m);
	for(int i = m-1;i >=0;i--)
	{
		cout << arr[i];
	}
	return 0;
}
