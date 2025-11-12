#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d" ,&n,&k);
	for(int i = 1;i <= n;i++)
	{
		int b;
		scanf("%d" ,&b);
		a[i] = a[i-1] ^ b;
	}
	int asd = -1;
	int ret = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i - 1;j >= asd;j--)
		{
			int b = a[i]^a[j];
			if (b == k)
			{
				ret++;
				asd = i;
				break;
			}
		}
	}
	printf("%d" ,ret);
	return 0;
}
