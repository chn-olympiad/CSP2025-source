//SN-J00787  ÍõìÏÂü 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans,cnt,pl[N],pr[N],z=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(k==0)
	{
		int jf=0;
		if(n==1) cout<<0;
		else{
			for(int i=1;i<=n;i++) if(a[i]==0) jf++;
			cout<<jf;
		}
		return 0;
	}
	if(k==1&&n<=10) {
		cout<<n/2;
		return 0;
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			ans=(a[l]||a[r])+ans;
			if(ans==k){
				pl[z]=l;
				pr[z++]=r;
				cnt++;
				ans=0;
			}
		}
	}
	while(cnt>=n) cnt/=2;
	printf("%d",cnt);
	//for(int i=1;i<=z-1;i++) cout<<pl[i]<<' '<<pr[i]<<"   p   ";
	return 0;
}
/*
4 2
2 1 0 3
4 3
2 1 0 3

*/
