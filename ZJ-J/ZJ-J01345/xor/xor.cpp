#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
struct line {
	int l;
	int r;
};
vector <line> b;
int a[500010];
int value[500010];
bool Cmp(line a,line b);
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	cin >> n >> k;
	int xs = 0;
	for (int i=1;i <= n;i++)
	    {
	    	cin >> a[i];
	    	xs = xs ^ a[i];
	    	value[i] = xs;
		}
	for (int i=1;i <= n;i++)
	    {
	    	for (int j=1;j <= i;j++)
	    	    {
	    	    	long long v = value[i] ^ value[j-1];
	    	    	if (v == k)
	    	    	    {
	    	    	    	line t;
	    	    	        t.l = j;
	    	    	        t.r = i;
	    	    	        b.push_back(t);
						}
				}
		}
	int l = b.size();
	
//	cout << l << endl;
//	for (int i=0;i < l;i++)
//	    {
//	    	cout << b[i].l << " " << b[i].r << endl;
//		}
	return 0;
}
bool Cmp(line a,line b)
    {
    	return a.r < b.r;
	}
