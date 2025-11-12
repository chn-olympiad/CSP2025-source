#include<bits/stdc++.h>
using namespace std;
int n,i,ans,cnt1,cnt2,cnt3,sum[200010],T;
struct node{
	int st,nd,rd;
}a[200010],s1[200010],s2[200010],s3[200010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		cnt1=cnt2=cnt3=ans=0;
		for(i=1;i<=n;i++){
			cin>>a[i].st>>a[i].nd>>a[i].rd;
			if(a[i].st>=a[i].nd&&a[i].st>=a[i].rd)s1[++cnt1]=a[i];
			else if(a[i].nd>=a[i].st&&a[i].nd>=a[i].rd)s2[++cnt2]=a[i];
			else s3[++cnt3]=a[i];
		}
		for(i=1;i<=cnt1;i++)ans+=s1[i].st;
		for(i=1;i<=cnt2;i++)ans+=s2[i].nd;
		for(i=1;i<=cnt3;i++)ans+=s3[i].rd;
//		cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<ans<<"\n";
		if(cnt1>n/2){
			for(i=1;i<=cnt1;i++)sum[i]=min(s1[i].st-s1[i].nd,s1[i].st-s1[i].rd);
			sort(sum+1,sum+1+cnt1);
			for(i=1;i<=cnt1-n/2;i++)ans-=sum[i];
		}
		else if(cnt2>n/2){
			for(i=1;i<=cnt2;i++)sum[i]=min(s2[i].nd-s2[i].st,s2[i].nd-s2[i].rd);
			sort(sum+1,sum+1+cnt2);
			for(i=1;i<=cnt2-n/2;i++)ans-=sum[i];
		}
		else if(cnt3>n/2){
			for(i=1;i<=cnt3;i++)sum[i]=min(s3[i].rd-s3[i].st,s3[i].rd-s3[i].nd);
			sort(sum+1,sum+1+cnt3);
			for(i=1;i<=cnt3-n/2;i++)ans-=sum[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/