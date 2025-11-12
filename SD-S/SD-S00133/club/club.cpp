#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n=0; 
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		
		int ans=0,zui,a1[100001],a2[100001],a3[100001],r1,r2,r3;
		for(int j=0;j<n;j++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			if(n==2)
			{
				cin>>a1[1]>>a2[1]>>a3[1];
				ans=max(max(max(a1[0]+a2[1],a1[0]+a3[1]),max(a2[0]+a1[1],a2[0]+a3[1])),max(a3[0]+a1[1],a3[0]+a2[1]));
				cout<<ans<<endl;
				break;
			}
			zui=max(max(a1[i],a2[i]),a3[i]);
			if(zui==a1[i]){
				if(r1<n/2){
					r1++;
					ans+=zui;
					continue;
				}
				else if(r1>=n/2){
					zui=max(a3[i],a2[i]);
					if(zui==a2[i]){
						r2++;
						ans+=zui;
						continue;
					}
					else{
						r3++;
						ans+=zui;
						continue;
					}
				}
			}
			else if(zui==a2[i]){
				if(r2<n/2){
					r2++;
					ans+=zui;
					continue;
				}
				else if(r2>=n/2)
				{
					zui=max(a3[i],a1[i]);
					if(zui==a1[i]){
						r1++;
						ans+=zui;
						continue;
					}
					else{
						r3++;
						ans+=zui;
						continue;
					}
				}
				
			}
			else if(zui==a3[i]){
				if(r3<n/2){
					r3++;
					ans+=zui;
					continue;
				}
					else if(r3>=n/2)
				{
					zui=max(a2[i],a1[i]);
					if(zui==a1[i]){
						r1++;
						ans+=zui;
						continue;
					}
					else{
						r2++;
						ans+=zui;
						continue;
					}
				}
			}
			
			
		}
		if(n!=2)cout<<ans<<endl;
	}
	return 0;
} 
