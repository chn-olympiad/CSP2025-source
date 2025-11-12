#include<iostream>
#include<cstring>
using namespace std;
int a[500005],f[500005],mx[5000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	memset(mx,-0x3f,sizeof(mx));
	mx[0] = 0;
	int sum = 0;
	for(int i = 1;i <= n;i++)
	{
		sum ^= a[i];
		f[i] = max(mx[sum ^ k] + 1,f[i - 1]); 
		mx[sum] = max(mx[sum],f[i]); 
	} 
	cout << f[n] << "\n"; 
	return 0; 
} 
