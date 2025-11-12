#include<bits/stdc++.h>
using namespace std; 
long long t,n,a[200000],b[200000],c[200000],p,p_max[4],ans,topa,topb,topc,chac[200005],chab[200005],chaa[200000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		topa=0;
		topb=0;
		topc=0;
		p_max[1]=0;
		p_max[2]=0;
		p_max[3]=0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				p_max[1]++;
				ans+=a[i];
				chaa[++topa]=a[i]-max(b[i],c[i]);
			}
			else if(a[i]<=b[i]&&b[i]>=c[i]){
				p_max[2]++;
				chab[++topb]=b[i]-max(a[i],c[i]);
				ans+=b[i];
			}
			else{
				p_max[3]++;
				chac[++topc]=c[i]-max(a[i],b[i]);
				ans+=c[i];
			}
		}
		long long maxx=0;
		for(int i=1;i<=3;i++){
			if(p_max[i]>maxx){
			maxx=p_max[i];
			p=i;
			}
		}
		if(p==1){
				sort(chaa+1,chaa+maxx+1);
				for(int i=1;i<=maxx-n/2;i++)ans-=chaa[i];
			}
		else if(p==2){
				sort(chab+1,chab+maxx+1);
				for(int i=1;i<=maxx-n/2;i++)ans-=chab[i];
			}
		else{
				sort(chac+1,chac+maxx+1);
				for(int i=1;i<=maxx-n/2;i++)ans-=chac[i];
			}
		cout<<ans<<endl;
	}
	return 0;
}
