#include<bits/stdc++.h>
using namespace std;
int t,n;
struct student{
	int b[4];
	int pf,ps,pt;
	
}a[200005]={};
bool cmp1(student mm,student nn){
	if(mm.b[mm.pf]-mm.b[mm.ps]==nn.b[nn.pf]-nn.b[nn.ps]){
		if(mm.b[mm.ps]-mm.b[mm.pt]==nn.b[nn.ps]-nn.b[nn.pt]) return mm.b[mm.pf]>nn.b[nn.pf];
		else return mm.b[mm.ps]-mm.b[mm.pt]>nn.b[nn.ps]-nn.b[nn.pt];
	}
	return mm.b[mm.pf]-mm.b[mm.ps]>nn.b[nn.pf]-nn.b[nn.ps];
}
int main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int ans1=0,sum[4]={},ans2=0;//ans1为总分，ans2为人数 
		memset(a,0,sizeof(a));
		for(int j=1;j<=n;j++){
			cin>>a[j].b[1]>>a[j].b[2]>>a[j].b[3];
			if(a[j].b[1]>a[j].b[2]){
				if(a[j].b[2]>a[j].b[3]) a[j].pf=1,a[j].ps=2,a[j].pt=3;
				else if(a[j].b[3]>a[j].b[1]) a[j].pf=3,a[j].ps=1,a[j].pt=2;
				else a[j].pf=1,a[j].ps=3,a[j].pt=2;
			}else{
				if(a[j].b[1]>a[j].b[3]) a[j].pf=2,a[j].ps=1,a[j].pt=3;
				else if(a[j].b[3]>a[j].b[2]) a[j].pf=3,a[j].ps=2,a[j].pt=1;
				else a[j].pf=2,a[j].ps=3,a[j].pt=1;
			}
			
		}
		sort(a+1,a+n+1,cmp1);
		for(int j=1;j<=n;j++){
			if(sum[a[j].pf]>=n/2){
				sum[a[j].ps]+=1;
				ans2++;
				ans1+=a[j].b[a[j].ps];
				a[j].pf=0,a[j].ps=0,a[j].pt=0;
			}
			sum[a[j].pf]+=1;
			ans2++;
			ans1+=a[j].b[a[j].pf];
			a[j].pf=0,a[j].ps=0,a[j].pt=0;
		}

		cout<<ans1<<endl;
	}
}
