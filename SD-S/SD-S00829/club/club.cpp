#include<bits/stdc++.h>
using namespace std;
int T,n;
const int N=1e5+5;
int a[N][5],bmax[N],b2max[N],wmax[N],p[N],cha[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>T;
	while(T--){
		long long ans=0;
		int pos=0,cnt=0;
		cin>>n;
		memset(bmax,0,sizeof(bmax));
		memset(b2max,0,sizeof(b2max));
		memset(cha,0,sizeof(cha));
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>=bmax[i]) b2max[i]=bmax[i],wmax[i]=j,bmax[i]=a[i][j];
			else if(a[i][j]<bmax[i]&&a[i][j]>b2max[i]) b2max[i]=a[i][j];
		}
		for(int i=1;i<=n;i++)
		{
			p[wmax[i]]++;
			if(p[wmax[i]]>n/2) pos=wmax[i];
			ans+=bmax[i];
		}
		if(pos){
		for(int i=1;i<=n;i++)
		{
			if(wmax[i]==pos) cha[++cnt]=bmax[i]-b2max[i];
		}
		sort(cha+1,cha+1+cnt);
		for(int i=1;i<=p[pos]-n/2;i++)
		   {
			ans-=cha[i];
		   }
	    }
	    cout<<ans<<"\n";
	}	
	return 0;
}
