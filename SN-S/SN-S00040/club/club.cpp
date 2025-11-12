//SN-S00040
#include<bits/stdc++.h>
using namespace std;
const int fyc=1e5+5;
struct stu{
	int num,id;
}now[fyc];
bool cmp1(stu x,stu y){
	return x.num<y.num;
}
bool cmp2(stu x,stu y){
	return x.num>y.num;
}
int T,n,ans,cnt1,cnt2,cnt3,s1[fyc],s2[fyc],s3[fyc],big,k[40],lis[fyc];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i]>>s3[i];
		cnt1=cnt2=ans=0;
		for(int i=1;i<=n;i++)
			if(s1[i]>s2[i]) cnt1++,lis[i]=1;
			else cnt2++,lis[i]=2;
		if(cnt1>cnt2){
			for(int i=1;i<=n;i++) now[i].num=(s1[i]-s2[i]>0?s1[i]-s2[i]:2147483647),now[i].id=i;
			sort(now+1,now+n+1,cmp1);
			for(int i=1;i<=cnt1-n/2;i++) lis[now[i].id]=3-lis[now[i].id];
		}
		else{
			for(int i=1;i<=n;i++) now[i].num=(s2[i]-s1[i]>0?s2[i]-s1[i]:2147483647),now[i].id=i;
			sort(now+1,now+n+1,cmp1);
			for(int i=1;i<=cnt2-n/2;i++) lis[now[i].id]=3-lis[now[i].id];
		}
		cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++)
			if(lis[i]==1) now[i].num=s3[i]-s1[i],now[i].id=i;
			else now[i].num=s3[i]-s2[i],now[i].id=i;
		sort(now+1,now+n+1,cmp2);
		for(int i=1;i<=n/2&&now[i].num>0;i++) lis[now[i].id]=3;
		for(int i=1;i<=n;i++)
			if(lis[i]==1) cnt1++;
			else if(lis[i]==2) cnt2++;
			else cnt3++;
		for(int i=1;i<=n;i++){
			if(s1[i]<s2[i]&&cnt2<n/2&&lis[i]==1) cnt2++,cnt1--,lis[i]=2;
			else if(s1[i]>s2[i]&&cnt1<n/2&&lis[i]==2) cnt1++,cnt2--,lis[i]=1; 
		}		
		for(int i=1;i<=n;i++){
			if(lis[i]==1) ans+=s1[i];
			else if(lis[i]==2) ans+=s2[i];
			else ans+=s3[i];
		}
		cout<<ans<<"\n";
	}
}
