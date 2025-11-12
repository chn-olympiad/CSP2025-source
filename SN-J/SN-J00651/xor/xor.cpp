#include <bits/stdc++.h>
using namespace std;
const int maxN = 5*1e5; 
struct node
{
	int l, r;
};

string dec_to_bin(int x)
{
	string s = "00000000000000000000";
	int ii = 19;
	int yu,shang = x;
	while(shang > 0)
	{
		yu = shang % 2;
		shang /= 2; 
		s[ii] = yu + '0';
		ii--;
	}
	//cout << s;
	return s;
}

string yihuo(string a, string b)
{
	string s = "00000000000000000000";
	for(int i = 0; i < 20; i++)
	{
		if(a[i] == b[i]) s[i] = '0';
		else s[i] = '1';
	}
	return s;
}

int to_10(string s)
{
	int ans = 0;
	int ii = 0;
	for(int i = 19; i >= 0; i--)
	{
		if(s[i] == '1')
		{
			ans += (int)pow(2, ii);
		}
		ii++;
	}
	
	return ans;
} 

bool cmp(node a, node b)
{
	return a.r < b.r;
}

int main()
{	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	vector<string> pre;
	int n, k;
	cin >> n >> k;
	vector<string> a;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		string now = dec_to_bin(x);
		a.push_back(now);
		if(i == 0)
		{
			pre.push_back(now);
		}
		else
		{
			pre.push_back(yihuo(now, pre[i-1]));
		}
	}
//	cout << yihuo(pre[0], pre[3]);
//	cout << "\n" << dec_to_bin(k);
//	for(int i = 0; i < pre.size(); i++)
//	{
//		cout << pre[i] << "\n";
//	}
	
	int cnt = 0;
	string k1 = dec_to_bin(k);
	vector<node> b; 
	for(int l = 0; l < pre.size(); l++)
	{
		for(int r = l; r < pre.size(); r++)
		{	
			if(l == 0)
			{
				if(pre[r] == k1) b.push_back({l, r});
				continue;
			}
			if(l == r)
			{
				if(a[l] == k1) b.push_back({l, r});
				continue;
			}
			else
			{
				if(yihuo(pre[l-1],pre[r]) == k1)
				{
					b.push_back({l, r});
				}
				continue;
			}
		}
	}
	sort(b.begin(), b.end(), cmp);
//	
	cout << b.size();
	

	return 0;	
} 
