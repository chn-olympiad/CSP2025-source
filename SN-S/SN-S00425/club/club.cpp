#include<bits/stdc++.h>
using namespace std;
struct node{
	long long id,val;
	int d;
}a[300000+30];
bool f[100000+10];
long long ta[5];
long long t,n,k,cnt=0,ans=0,tans=0,u,tt=600;
bool cmp(node ax,node ay){
	return ax.val>ay.val;
}
int main(){
	//SN-S00425 lianglinyi TYQJ
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;		
		k=1;
		u=1;
		for(long long i=1;i<=n*3;i++){
			cin>>a[i].val;
			a[i].id=k;
			a[i].d=u;
			u++;
			if(u==4){
				u=1;
			}
			if(i%3==0){
				k++;
			}			
		}
		sort(a+1,a+3*n+1,cmp);			
		ans=0;
		for(long long op=1;op<=tt&&op<=3*n;op++){			
			tans=0;
			cnt=0;
			for(long long i=1;i<=n+5;i++){
				f[i]=false;
			}	
			ta[1]=n/2;
			ta[2]=ta[1];
			ta[3]=ta[1];
			for(long long i=op;i<=3*n;i++){
				if(cnt==n){
					break;
				}
				long long v=a[i].id,val=a[i].val;
				int d=a[i].d;
				if(f[v]==false){
					f[v]=true;
					if(ta[d]>0){
						ta[d]--;
						cnt++;
						tans+=val;
					}
				}					
			}
			ans=max(ans,tans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
