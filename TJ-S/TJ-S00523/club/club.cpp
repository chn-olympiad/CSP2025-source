#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,a[100003],b[100003],cnt,c[100003],sum=0;
		long long ans=0,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0)sum=1;
			if(c[i]!=0)cnt=1;
		}if(sum==0){//A部分分
			sort(a,a+n);
			for(int i=n/2;i<n;i++)ans+=a[i];
			cout<<ans<<endl;
			continue;
		}else if(n==2){
			cout<<max(max(max(a[0]+b[1],a[0]+c[1]),max(b[0]+a[1],b[0]+c[1])),max(c[0]+a[1],c[0]+b[1]))<<endl;
			continue;
		}for(int i=0;i<n;i++){//贪心
			if(a[i]>b[i]&&a[i]>c[i])ans+=a[i],cnt1++;
			else if(b[i]>a[i]&&b[i]>c[i])ans+=b[i],cnt2++;
			else ans+=c[i],cnt3++;
		}
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2)cout<<ans<<endl;
	}
	return 0;
}
