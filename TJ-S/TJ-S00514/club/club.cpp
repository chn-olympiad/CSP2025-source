#include<bits/stdc++.h>
using namespace std;
	int t,n,a1[100005],a2[100005],a3[100005],maxn,ans=0,a4,a5,a6,maxm;
void zero(){
	if(a4>=maxm)	for(int i=1;i<=n;i++) a1[i]=0;
	if(a5>=maxm)	for(int i=1;i<=n;i++) a2[i]=0;		
	if(a6>=maxm)	for(int i=1;i<=n;i++) a3[i]=0;		
}
void find(){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				if(a1[j]<a1[i]){
					swap(a1[i],a1[j]);
					swap(a2[i],a2[j]);
					swap(a3[i],a3[j]);
				}
		if(a1[1]>a2[1]&&a1[1]>a3[1])	maxn=a1[1],a4++;
		if(a2[1]>a1[1]&&a2[1]>a3[1])	maxn=a2[1],a5++;
		if(a3[1]>a2[1]&&a3[1]>a1[1])	maxn=a3[1],a6++;
		ans+=maxn;
		a1[1]=0;a2[1]=0;a3[1]=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>t;
	while(t>0){
		t--;
		cin>>n;
		maxm=n/2;
		for(int i=1;i<=n;i++)	cin>>a1[i]>>a2[i]>>a3[i];
		if(n==2){
			ans=max(a1[2]+a2[1],a1[2]+a2[3]);
			ans=max(ans,a1[1]+a2[2]);
			ans=max(ans,a1[1]+a2[3]);
			ans=max(ans,a1[3]+a2[1]);
			ans=max(ans,a1[3]+a2[2]);
		}	else	for(int i=1;i<=n;i++) find();
		cout<<ans;
		ans=0;
	}
	return 0;
}

