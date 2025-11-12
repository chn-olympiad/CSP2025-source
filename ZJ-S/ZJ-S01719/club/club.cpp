#include <bits/stdc++.h>
using namespace std;

int t;
int a[100005],b[100005],c[100005];
int aa[100005],bb[100005],cc[100005];
int picka,pickb,pickc;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	
	cin>>t;
	for (int i=1; i<=t; i++){
		int n=100005,ans=0;

		cin>>n;
		for(int i=1; i<=n; i++)	{
			cin>>a[i]>>b[i]>>c[i];
			aa[i]=a[i],bb[i]=b[i],cc[i]=c[i];
		}
		
		sort(aa+1,aa+n+1),sort(bb+1,bb+n+1),sort(cc+1,cc+n+1);
		picka=n/2,pickb=n/2,pickc=n/2;
		
		
		for (int i=1; i<=n; i++){
			int awa=0,ovo=0,qwq=0;
			int numa=0,numb=0,numc=0;
			
			if (a[i]>=b[i])		awa=1;
			if (a[i]>=c[i])		ovo=1;
			if (b[i]>=c[i])		qwq=1;
			
			if (awa && ovo){
				if (a[i]>aa[picka] && numa<n/2){
					ans+=a[i],numa++;
					continue;
				}
				else if(qwq){
					if (b[i]>bb[pickb] && numb<n/2){
						ans+=b[i],numb++;
						continue;
					}
					if (c[i]>cc[pickc] && numc<n/2){
						ans+=c[i],numc++;
						continue;
					}
				}
			}
			
			if (!awa && qwq){
				if (b[i]>bb[pickb] && numb<n/2){
					ans+=b[i],numb++;
					continue;
				}
				else if(ovo){
					if (a[i]>aa[picka] && numa<n/2){
						ans+=a[i],numa++;
						continue;
					}
					if (c[i]>cc[pickc] && numc<n/2){
						ans+=c[i],numc++;
						continue;
					}
				}
			}
			
			if (!qwq && !ovo){
				if (c[i]>cc[pickc] && numc<n/2){
					ans+=c[i],numc++;
					continue;
				}
				else if(!awa){
					if (b[i]>bb[pickb] && numb<n/2){
						ans+=b[i],numb++;
						continue;
					}
					if (a[i]>a[picka] && numa<n/2){
						ans+=a[i],numa++;
						continue;
					}
				}
			}
			
			if (aa[picka]-a[i] >= bb[pickb]-b[i])	awa=1;
			else	awa=0;
			
			if (aa[picka]-a[i] >= cc[pickc]-c[i])	ovo=1;
			else	ovo=0;
			
			if (bb[pickb]-b[i] >= cc[pickc]-c[i])	qwq=1;
			else	qwq=0;
			
			if (awa && ovo && numa<n/2){
				ans+=a[i],numa++;
				picka++;
			}                      
			else if (!awa && qwq && numb<n/2){
				ans+=b[i],numb++;
				pickb++;
			}                          
			else if (numc<n/2){
				ans+=c[i],numc++;
				pickc++;
			}           
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}