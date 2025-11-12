#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
#define ll long long
int t,n,m,sum,sum1,sum2,sum3,cnt[33];
struct node{
	int a1,a2,a3;
	int a12,a13,a21,a23,a31,a32;
}v[N];
void dfs(int p,int a1,int a2,int a3,int price){
	if(a1>n/2||a2>n/2||a3>n/2||price+cnt[n]-cnt[p-1]<max({sum1,sum2,sum3}))return;
	if(p==n+1){
		sum=max(sum,price);
		return;
	}
	dfs(p+1,a1+1,a2,a3,price+v[p].a1);
	dfs(p+1,a1,a2+1,a3,price+v[p].a2);
	dfs(p+1,a1,a2,a3+1,price+v[p].a3);
}
bool cmp1(node a,node b){return max(a.a12,a.a13)-a.a1>max(b.a12,b.a13)-b.a1;}
bool cmp2(node a,node b){return max(a.a21,a.a23)-a.a2>max(b.a21,b.a23)-b.a2;}
bool cmp3(node a,node b){return max(a.a31,a.a32)-a.a3>max(b.a31,b.a32)-b.a3;}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){ 
		cin>>n;
		sum=sum1=sum2=sum3=0;
		for(int i=1;i<=n;i++){
			cin>>v[i].a1>>v[i].a2>>v[i].a3;
			sum1+=v[i].a1,sum2+=v[i].a2,sum3+=v[i].a3;
			v[i].a12=v[i].a2-v[i].a1,v[i].a13=v[i].a3-v[i].a1;
			v[i].a21=v[i].a1-v[i].a2,v[i].a23=v[i].a3-v[i].a2;
			v[i].a31=v[i].a1-v[i].a3,v[i].a32=v[i].a2-v[i].a3;
		} 
		sort(v+1,v+1+n,cmp1);
		for(int i=1;i<=n/2;i++)sum1+=max(v[i].a12,v[i].a13);
		sort(v+1,v+1+n,cmp2);
		for(int i=1;i<=n/2;i++)sum2+=max(v[i].a21,v[i].a23);
		sort(v+1,v+1+n,cmp3);
		for(int i=1;i<=n/2;i++)sum3+=max(v[i].a31,v[i].a32);
		if(n<=30){
			for(int i=1;i<=n;i++)cnt[i]=cnt[i-1]+max({v[i].a1,v[i].a2,v[i].a3});
			dfs(1,0,0,0,0);
			cout<<sum<<'\n';
			continue;
		}
		cout<<max({sum1,sum2,sum3})<<'\n';
	}
	return 0;
}