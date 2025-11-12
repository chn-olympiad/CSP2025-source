#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int a1[N],a2[N],a3[N];
struct node{
	int u,num,Max;	
}c[N];	//存最大和次大之间的差值 
int maxx[N];
bool cmp1(node x,node y){
	if(x.Max==y.Max)
		return x.u<y.u;
	return x.Max<y.Max;
}
bool cmp2(node x,node y){
	if(x.Max==2&&y.Max!=2)
		return x.Max<y.Max;
	else
		return x.u<y.u;
}
bool cmp3(node x,node y){
	if(x.Max==y.Max)
		return x.u<y.u;
	return x.Max>y.Max;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(a1,0,sizeof a1);
		memset(a2,0,sizeof a2);
		memset(a3,0,sizeof a3);
		memset(c,0,sizeof c);
		memset(maxx,0,sizeof maxx);
		int n;
		ll ans=0;
		int cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		int half=n/2;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			maxx[i]=max(max(a1[i],a2[i]),a3[i]);
			int minn=min(min(a1[i],a2[i]),a3[i]);
			c[i].num=i;
			if(a1[i]==maxx[i]){
				cnt1++;
				c[i].Max=1;
				if(a3[i]==minn)
					c[i].u=a1[i]-a2[i];
				if(a2[i]==minn)
					c[i].u=a1[i]-a3[i];
			}
			else if(a2[i]==maxx[i]){
				cnt2++;
				c[i].Max=2;
				if(a3[i]==minn)
					c[i].u=a2[i]-a1[i];
				if(a1[i]==minn)
					c[i].u=a2[i]-a3[i];
			}
			else if(a3[i]==maxx[i]){
				cnt3++;
				c[i].Max=3;
				if(a1[i]==minn)
					c[i].u=a3[i]-a2[i];
				if(a2[i]==minn)
					c[i].u=a3[i]-a1[i];
			}
		}
		for(int i=1;i<=n;i++)
			ans+=maxx[i];
		if(cnt1<=half&&cnt2<=half&&cnt3<=half){
			cout<<ans<<"\n";
			continue;
		}	//没问题 
		else{
			int m=max(max(cnt1,cnt2),cnt3);
			int h=m-half;
			if(m==cnt1)	//1超量了 
				sort(c+1,c+n+1,cmp1);
			else if(m==cnt2)	//2超量了 
				sort(c+1,c+n+1,cmp2);
			else if(m==cnt3)	//3超量了 
				sort(c+1,c+n+1,cmp3);
			for(int i=1;i<=h;i++)
				ans-=c[i].u;
			cout<<ans<<"\n";
		} 
	}
	return 0;
} //4