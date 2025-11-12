#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int t,r,f,v,suma,sumb,sumc;
		cin>>t;
		int df=0,de=0;
		for(int i=1;i<=t;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=c[i]||b[i]!=0){
				df=1;
			}
		}
		if(df==0){
			int ans=0;
			sort(a+1,a+t+1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(t==2){
			cout<<max(a[1]+b[2],max(a[2]+b[1],max(a[1]+c[2],max(a[2]+c[1],max(c[1]+b[2],c[2]+b[1])))))<<endl;
			continue;
		}
	}
} 
