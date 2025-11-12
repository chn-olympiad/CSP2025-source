#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define elif else if
#define ll long long
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	ll n = a.size();
	vector<ll> b(1e7);
	ll cnt = 0;//, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0, cnt7 = 0, cnt8 = 0, cnt9 = 0;
	for(ll i = 0;i < n;i++)
	{
		if(a[i] == '0')
		{
			b[i] = 0;
			cnt++;
		}
		elif(a[i] == '1')
		{
			b[i] = 1;
			cnt++;
		}
		elif(a[i] == '2')
		{
			b[i] = 2;
			cnt++;
		}
		elif(a[i] == '3')
		{
			b[i] = 3;
			cnt++;
		}
		elif(a[i] == '4')
		{
			b[i] = 4;
			cnt++;
		}
		elif(a[i] == '5')
		{
			b[i] = 5;
			cnt++;
		}
		elif(a[i] == '6')
		{
			b[i] = 6;
			cnt++;
		}
		elif(a[i] == '7')
		{
			b[i] = 7;
			cnt++;
		}
		elif(a[i] == '8')
		{
			b[i] = 8;
			cnt++;
		}
		elif(a[i] == '9')
		{
			b[i] = 9;
			cnt++;
		}
	}
	sort(b.begin(), b.end());
	for(ll i = b.size() - 1;i >= b.size() - cnt;i--)
	{
		cout<<b[i];
	}
	cout<<'\n';
	//cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
