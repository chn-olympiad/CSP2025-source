#include <iostream>
#include <cmath>
using namespace std;
long long n,ans=0;
int a[5010];
void dfs(int top,int l,int r,int sum,int num);
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	    cin >> a[i];
	for(int i = 1; i < n; i++)
    {
    	int flag = 1;
    	for(int j = n-1; j >= i; j--)
    	{
    		if(a[j] < a[j+1]) swap(a[j],a[j+1]),flag = 0;
		}
		if(flag) break;
	}
//	for(int i = 1; i <= n; i++)
//	    cout << a[i] << " ";
//	cout << endl;
	for(int i = 1; i <= n; i++)
		dfs(i,n,n,a[n],1);
	
	cout << ans << endl;
	return 0;
}
void dfs(int top,int l,int r,int sum,int num)
{
	if(top>=n-2) return;
	if(l==top) return;
//	cout << top << " "  << l << " "  << r << " "  << sum << " "  << num << endl;
//	cout << "sum:" << sum << "  a[top]*2:" << a[top]*2 << endl;
	if(sum>a[top]&&num>=2)
	{
//		cout << top << " "  << l << " "  << r << " "  << sum << " "  << num << endl;
//		cout << "sum:" << sum << " a[top]:" << a[top] << endl;
		ans += (1<<(l-top-1))%998244353;
		dfs(top,l-1,r,sum+a[l-1]-a[l],num);
//		cout << (l-top-1) << " " << (1<<(l-top-1)) << endl;
//		cout << top << endl;
	}
	else
	{
		dfs(top,l-1,r,sum+a[l-1],num+1);
		dfs(top,l-1,r,sum+a[l-1]-a[l],num);	
	}
	return;
}
//#Shang4Shan3Ruo6Shui4
//polygon
/*
5
1 2 3 4 5

*/
