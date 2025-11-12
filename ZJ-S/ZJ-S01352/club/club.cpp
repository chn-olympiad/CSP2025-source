#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,q1[100010],q2[100010],q3[100010],sum1,sum2,sum3,ans;
struct node{
	int a,b,c;
}a[100010];
bool cmp1(int i,int j){
	int v1=a[i].a-max(a[i].b,a[i].c);
	int v2=a[j].a-max(a[j].b,a[j].c);
	return v1<v2;
}
bool cmp2(int i,int j){
	int v1=a[i].b-max(a[i].a,a[i].c);
	int v2=a[j].b-max(a[j].a,a[j].c);
	return v1<v2;
}
bool cmp3(int i,int j){
	int v1=a[i].c-max(a[i].b,a[i].a);
	int v2=a[j].c-max(a[j].b,a[j].a);
	return v1<v2;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		ans=sum1=sum2=sum3=0;
		memset(q1,0,sizeof q1);
		memset(q2,0,sizeof q2);
		memset(q3,0,sizeof q3);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			int maxs=max(a[i].a,max(a[i].b,a[i].c));
			if(maxs==a[i].a) q1[++sum1]=i;
			else if(maxs==a[i].b) q2[++sum2]=i;
			else q3[++sum3]=i;
			ans+=maxs;
		}
		if(sum1>n/2){
			int v=sum1-n/2;
			sort(q1+1,q1+sum1+1,cmp1);
			for(int i=1;i<=v;i++){
				ans-=a[q1[i]].a;
				ans+=max(a[q1[i]].b,a[q1[i]].c);
			}
		}
		else if(sum2>n/2){
			int v=sum2-n/2;
			sort(q2+1,q2+sum2+1,cmp2);
			for(int i=1;i<=v;i++){
				ans-=a[q2[i]].b;
				ans+=max(a[q2[i]].a,a[q2[i]].c);
			}
		}
		else if(sum3>n/2){
			int v=sum3-n/2;
			sort(q3+1,q3+sum3+1,cmp3);
			for(int i=1;i<=v;i++){
				ans-=a[q3[i]].c;
				ans+=max(a[q3[i]].b,a[q3[i]].a);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
