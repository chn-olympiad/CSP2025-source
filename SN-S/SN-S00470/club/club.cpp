#include<bits/stdc++.h>
using namespace std;
long long t,n,cnt1,cnt2,cnt3,dy[100005],ii,cntt,n2;
struct st{
	long long a1,a2,a3;
	int z=0;
};
long long ans,anss;
st a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		n2=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>a[i].a2&&a[i].a1>a[i].a3){
				a[i].z=1;
				cnt1++;
				ans+=a[i].a1;
			}
			if(a[i].a2>a[i].a1&&a[i].a2>a[i].a3){
				a[i].z=2;
				cnt2++;
				ans+=a[i].a2;
			}
			if(a[i].a3>a[i].a1&&a[i].a3>a[i].a2){
				a[i].z=3;
				cnt3++;
				ans+=a[i].a3;
			}
		}
		if(cnt1<=n2&&cnt2<=n2&&cnt3<=n2){
			cout<<ans<<"\n";
		}
		else{
			if(cnt1>n2){
				for(int j=1;j<=n;j++){
					if(a[j].z==1){
						int x=max(a[j].a2,a[j].a3);
						dy[++ii]=a[j].a1-x;
					}
				}
				sort(dy+1,dy+cnt1+1);
				cntt=cnt1-n2;
			}
			
			if(cnt2>n2){
				
				for(int j=1;j<=n;j++){
					if(a[j].z==2){
						
						int x=max(a[j].a1,a[j].a3);
					
						dy[++ii]=a[j].a2-x;
						
					}
				}
				sort(dy+1,dy+cnt2+1);
				cntt=cnt2-n2;
				
			}
			if(cnt3>n2){
				for(int j=1;j<=n;j++){
					if(a[j].z==3){
						int x=max(a[j].a1,a[j].a2);
						dy[++ii]=a[j].a3-x;
					}
				}
				sort(dy+1,dy+cnt3+1);
				cntt=cnt3-n2;
			}
			for(int j=1;j<=cntt;j++){
				ans-=dy[j];
			}
			ans-=anss;
			cout<<ans<<"\n";
		}
		ans=0;
		anss=0;
		ii=0;
		cntt=0;
		cnt1=0;
		cnt2=0;
		cnt3=0;
	}
	return 0; 
}
