#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 1e5 + 7;
struct node
{
	ll val1,val2,val3,id;
	bool operator <(const node& x)const
	{
		ll a[3];
		a[0] = val1;
		a[1] = val2;
		a[2] = val3;
		sort(a,a + 2);
		ll b[3];
		b[0] = x.val1;
		b[1] = x.val2;
		b[2] = x.val3;
		sort(b,b + 2);
		return abs(a[0] - a[1]) > abs(b[0] - b[1]);
	}
};
vector <node> A;
vector <pair <ll,ll> > QWQ;
bool book[N];
ll sum[4];
bool cmp(pair <ll,ll> a,pair <ll,ll> b) {return a.first > b.first;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	scanf("%lld",&t);
	while (t --)
	{
		A.clear();
		ll n;
		scanf("%lld",&n);
		for (ll i = 1; i <= n; i ++)
		{
			ll a,b,c;
			scanf("%lld%lld%lld",&a,&b,&c);
			A.push_back((node){a,b,c,i});
		}
		memset(sum,0,sizeof(sum));
		sort(A.begin(),A.end());
		ll ans = 0;
		for (node i : A)
		{
			QWQ.clear();
			QWQ.push_back(make_pair(i.val1,1)); 
			QWQ.push_back(make_pair(i.val2,2)); 
			QWQ.push_back(make_pair(i.val3,3)); 
			sort(QWQ.begin(),QWQ.end(),cmp);
//			printf("%lld ",i.id);
			for (pair <ll,ll> j : QWQ)
			{
//				printf("%lld ",j.first);
				if (sum[j.second] < n / 2)
				{
					ans += j.first;
					sum[j.second] ++;
					break;
				}
			}
//			puts("");
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
/*

3
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 2
 10 9 8
 4 0 0






*/
