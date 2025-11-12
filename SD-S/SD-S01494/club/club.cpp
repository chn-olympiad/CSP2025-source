#include<bits/stdc++.h>
using namespace std;
int T;
struct pr{
	int r,id;
}v;
bool cmp1(pr x,pr y){
	return x.r>y.r;
}
int n,ans=0,num[4];
struct C{
	int q1=0,q2=0;
	pr s[3];
}a[100010];
bool cmp2(C x,C y){
	if(x.q1==y.q1){
		return x.q2>y.q2;
	}
	return x.q1>y.q1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		num[1]=0;
		num[2]=0;
		num[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			a[i].s[0]={x,1};
			cin>>x;
			a[i].s[1]={x,2};
			cin>>x;
			a[i].s[2]={x,3};
			sort(a[i].s,a[i].s+3,cmp1);
			a[i].q1=a[i].s[0].r-a[i].s[1].r;
			a[i].q2=a[i].s[0].r-a[i].s[2].r;
			//cerr<<a[i].q1<<' '<<a[i].q2;
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				v=a[i].s[j];
				if(num[v.id]>=n/2) continue; 
				ans+=v.r;
				num[v.id]++;
				break;		
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}    
