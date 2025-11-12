#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=(s[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		for(int j=i-1;j>=0;j--)
		{
			if((s[i]^s[j])==k)
			{
				f[i]=max(f[i],f[j]+1);
				break;
			}
		}
	}
	printf("%d\n",f[n]);
	return 0;
}/*
CCF ji zi neng bu neng pao kuai dian.
bu ran 100+100+80+80=360 mei you yi deng le.
hua shuo dian nao wei shen me da bu chu zhong wen.
*/
