#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int flag,l,r,qzy[500005],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	l=0,r=0,qzy[0]=a[0];
	while(r<=n){
		flag=0;
		for(int j=l;j<r;j++){
			qzy[j]=qzy[j]^a[r];
			if(qzy[j]==k){
				//cout<<l<<' '<<r<<"\n";
				ans++;
				flag=1;
				break;
			}
		}
		qzy[r]=a[r];
		if(qzy[r]==k&&r!=n&&flag!=1){
			//cout<<l<<' '<<r<<"\n";
			ans++;
			flag=1; 
		}
		if(flag==1)l=r+1;
		//cout<<r<<qzy[0]<<qzy[1]<<qzy[2]<<qzy[3]<<"t\n";
		r++;
	}
	
	cout<<ans;
}