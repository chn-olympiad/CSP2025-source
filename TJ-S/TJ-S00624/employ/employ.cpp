#include<bits/stdc++.h> 
using namespace std;
long long n,m,cnt;
vector<char> pd;
vector<int> ep;
set<vector<int> > s;
unsigned long long j;
unsigned long long jiecheng(int n)
{
	if(n==1) return 1;
	else return n*jiecheng(n-1);
}
bool f(vector<int> a)
{
	int t = 0;vector<int> fq(n+1,0);
	for(int i = 0;i < n;i++)
	{
		if(pd[i]-'0'==0 || fq[i]>=a[i]) fq[i+1]++;
		else t++;
	}
	return t>=m;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;pd.resize(n);ep.resize(n);
	for(int i = 0;i < n;i++) cin >> pd[i];
	for(int i = 0;i < n;i++) cin >> ep[i];
	sort(ep.begin(),ep.begin()+n);
	for(int i = 0;i < jiecheng(n);i++)
	{
		s.insert(ep);
		swap(ep[ep.size()-1],ep[ep.size()-2]);
		s.insert(ep);
		ep.insert(ep.begin(),ep[ep.size()-1]);
		ep.erase(ep.end()-1);
		s.insert(ep);
		swap(ep[ep.size()-1],ep[ep.size()-2]);
		ep.push_back(ep[0]);
		s.insert(ep);
		ep.erase(ep.begin());
	}
	set<vector<int> >::iterator a = s.begin();
	for(int j = 0;j < s.size();j++)
	{
		cnt+=f((*a));
		a++;
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
