#include <bits/stdc++.h>
using namespace std;
int n,t,cnt;
int a[200001],b[200001],c[200001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i] >> b[i] >> c[i];	
		}
		sort(a + 1,a + n + 1);
		for(int i = 1;i <= n / 2;i++){
			cnt += a[i];
		}
		cout << cnt << endl;
	}
	return 0;
}
