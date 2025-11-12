#include<bits/stdc++.h>
using namespace std;
int T,n,ca[100005],cb[100005],cc[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int num1=0,num2=0,num3=0,x,y,z;
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
		//	cin>>x>>y>>z;
			scanf("%d%d%d",&x,&y,&z);
			if(x>=y&&x>=z){
				ca[++num1]=min(x-y,x-z);
				ans+=x;
			}
			else if(y>=x&&y>=z){
				cb[++num2]=min(y-x,y-z);
				ans+=y;
			}
			else {
				cc[++num3]=min(z-y,z-x);
				ans+=z;
			}
		}
		if(num1>n/2){
				sort(ca+1,ca+num1+1);
				for(int i=1;i<=num1-n/2;i++)ans-=ca[i];
		}
		else if(num2>n/2){
			sort(cb+1,cb+num2+1);
			for(int i=1;i<=num2-n/2;i++)ans-=cb[i];
		}
		else if(num3>n/2){
			sort(cc+1,cc+num3+1);
			for(int i=1;i<=num3-n/2;i++)ans-=cc[i];	
		}
		printf("%d\n",ans);
	//	cout<<ans<<"\n";
	}
	return 0;
}
