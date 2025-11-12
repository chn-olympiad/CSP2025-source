#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=5e4+5;
int T,n,ans,l,dp[M],kkk,k3=0,k4;
struct aaa{
	int d[5],c;
}a[N];
struct bbb{
	int dd[N],b;
}biao[5];
bool cmp(aaa x,aaa y){
	if(x.d[1]!=y.d[1])return x.d[1]<y.d[1];
	else if(x.d[2]!=y.d[2])return x.d[2]<y.d[2];
	else return x.d[3]<y.d[3];
}
bool cmp1(aaa x,aaa y){
	if(x.d[1]!=y.d[1])return x.d[1]>y.d[1];
	else if(x.d[2]!=y.d[2])return x.d[2]>y.d[2];
	else return x.d[3]>y.d[3];
}
bool cmp2(aaa x,aaa y){
	if(x.d[2]!=y.d[2])return x.d[2]>y.d[2];
	else if(x.d[1]!=y.d[1])return x.d[1]>y.d[1];
	else return x.d[3]>y.d[3];
}
bool cmp3(aaa x,aaa y){
	if(x.d[3]!=y.d[3])return x.d[3]>y.d[3];
	else if(x.d[2]!=y.d[2])return x.d[2]>y.d[2];
	else return x.d[1]>y.d[1];
}
int hanshu(int k,int ll){
	sort(a+1,a+1+n,cmp1);int kk=0;
	for(int i=1;i<=biao[k].b;i++){
		if(ll==biao[k].dd[i]){
			kk=1;kkk=i;k3=k;k4=a[ll+1].c;
			break;
		}
	}
	if(kk==1){
		for(int i=1;i<=n;i++){
			if(a[i].c==ll){
				kk=a[i+1].d[k]+a[i].d[k+1];
				//cout<<a[i].d[k+1]<<" "<<a[i+1].d[k]<<" "<<kk<<" ";
				break;
			}
		}
	}
	sort(a+1,a+1+n,cmp2);//cout<<kk<<"\n";
	return kk;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int lll=0;lll<T;lll++){
		cin>>n;ans=0;l=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
			a[i].c=i;
			if((a[i].d[1]||a[i].d[2])&&(a[i].d[1]||a[i].d[3])&&(a[i].d[3]||a[i].d[2])){
				l=1;
			}
			if(a[i].d[1]>=a[i].d[2]&&a[i].d[1]>=a[i].d[3]){
				biao[1].dd[++biao[1].b]=i;ans+=a[i].d[1];
			}else if(a[i].d[2]>=a[i].d[1]&&a[i].d[2]>=a[i].d[3]){
				biao[2].dd[++biao[2].b]=i;ans+=a[i].d[2];
			}else{
				biao[3].dd[++biao[3].b]=i;ans+=a[i].d[3];
			}
		}
		if(l==0){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans=ans-a[i].d[1]-a[i].d[2]-a[i].d[3];
			}
			cout<<ans<<"\n";
			continue;
		}l=0;
		for(int i=1;i<=3;i++){
			if(biao[i].b>n/2){
				l=1;
				break;
			}
		}
		if(l==0){
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			biao[1].dd[i]=0;
			biao[2].dd[i]=0;
			biao[3].dd[i]=0;
		}
		biao[1].b=0;
		biao[2].b=0;
		biao[3].b=0;
		sort(a+1,a+1+n,cmp1);
		for(int j=1;j<=n/2;j++){
			dp[j]=a[j].d[1]+dp[j-1];
			biao[1].dd[++biao[1].b]=a[j].c;
			//cout<<dp[j]<<" ";
		}
		//cout<<"\n";
		sort(a+1,a+1+n,cmp2);
		for(int j=1;j<=n/2;j++){
			int ax=dp[j]+dp[j-1],by=hanshu(1,a[j].c);//+dp[j];
			dp[j]=max(ax,by);
			if(ax<by){
				biao[1].dd[kkk]=k4;
				biao[2].dd[++biao[2].b]=a[j].c;
			}
			//cout<<dp[j]<<" ";
		}
		//cout<<"\n";
		sort(a+1,a+1+n,cmp3);
		for(int j=1;j<=n/2;j++){
			int ax=dp[j]+dp[j-1],by=hanshu(1,a[j].c)+hanshu(2,a[j].c);//+dp[j];
			dp[j]=max(ax,by);
			if(ax<by){
				biao[k3].dd[kkk]=k4;
				biao[3].dd[++biao[3].b]=a[j].c;
			}
			
			//cout<<dp[j]<<" ";
		}
		//cout<<"\n";
		cout<<dp[n/2]<<"\n";
	}
	return 0;
}
