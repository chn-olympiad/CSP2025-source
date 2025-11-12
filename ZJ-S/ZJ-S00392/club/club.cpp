#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a,b,c;
struct node{
	int maxx,m2;
	int diff;
	int maxid;
}v[100001];
int ans,cnt1,cnt2,cnt3;
int d1[100001],d2[100001],d3[100001];
bool cmp(node a,node b){
	return a.diff<b.diff;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(v,0,sizeof(v));
		cnt1=0;
		cnt2=0;
		cnt3=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>=b){
				if(b>=c){
					v[i].maxx=a;
					v[i].m2=b;
					v[i].maxid=1;
					v[i].diff=v[i].maxx-v[i].m2;
				}
				else{
					if(a>=c){
						v[i].maxx=a;
						v[i].m2=c;
						v[i].maxid=1;
						v[i].diff=v[i].maxx-v[i].m2;						
					}
					else{
						v[i].maxx=c;
						v[i].m2=a;
						v[i].maxid=3;		
						v[i].diff=v[i].maxx-v[i].m2;				
					}
				}
			}
			else{
				if(c<=a){
					v[i].maxx=b;
					v[i].m2=a;
					v[i].maxid=2;
					v[i].diff=v[i].maxx-v[i].m2;					
				}
				else{
					if(b>=c){
						v[i].maxx=b;
						v[i].m2=c;
						v[i].maxid=2;
						v[i].diff=v[i].maxx-v[i].m2;					
					}
					else{
						v[i].maxx=c;
						v[i].m2=b;
						v[i].maxid=3;
						v[i].diff=v[i].maxx-v[i].m2;					
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(v[i].maxid==1){
				cnt1++;
				d1[cnt1]=v[i].diff;
			}
			else if(v[i].maxid==2){
				cnt2++;
				d2[cnt2]=v[i].diff;
			}
			else{
				cnt3++;
				d3[cnt3]=v[i].diff;
			}
			ans+=v[i].maxx;
		}
		if(cnt1>n/2){
			sort(d1+1,d1+cnt1+1);
			for(int i=1;i<=cnt1-n/2;i++){
				ans-=d1[i];
			}
		}
		if(cnt2>n/2){
			sort(d2+1,d2+cnt2+1);
			for(int i=1;i<=cnt2-n/2;i++){
				ans-=d2[i];
			}
		}
		if(cnt3>n/2){
			sort(d3+1,d3+cnt3+1);
			for(int i=1;i<=cnt3-n/2;i++){
				ans-=d3[i];
			}
		}		
		cout<<ans<<"\n";
	}
	return 0;
}