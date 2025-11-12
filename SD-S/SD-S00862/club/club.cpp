#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll n,l,K;
ll a[N][4];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cout.tie(0);
 	cin>>l;
 	while(l--)
 	{
 		ll s[N]={0},b=0,ans=0,f;
 		cin>>K;
 		int pan[K+3]={0},pan2[4]={0},num=0;
 		f=K*3;
 		for(ll i=1;i<=K;i++)
 		{
 			for(ll j=1;j<=3;j++)
 			{
 				cin>>a[i][j];
 				s[b]=a[i][j];
 				b++;
			 }
		}
		sort(s+1,s+1+f,cmp);
		for(ll da=1;da<=f;da++)
		{
			//cout<<endl<<s[da]<<"da"<<endl;
			if(num>=K) break;
			for(ll i=1;i<=K;i++)
			{
			//	cout<<endl<<pan[i];
				if(pan[i]==1)
					continue;
				for(ll j=1;j<=3;j++)
				{
					//cout<<pan2[j]<<endl;
					if(pan2[j]>=K/2) continue;
					else{
						if(a[i][j]==s[da])
						{
							ans+=s[da];
							num++;
						//	cout<<s[da]<<" "<<ans<<" "<<num<<endl;
							pan[i]=1;pan2[j]++;
						}
					}
					
				}
			}
		}
		cout<<ans<<endl;
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


