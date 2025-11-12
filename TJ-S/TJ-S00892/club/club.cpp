#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct memb{
	int a,b,c;
}a[N];
struct dd{
	int u,s1,s2;
};
int s1,s2,s3;
bool cmp(dd x,dd y){
	if(min(x.s1,x.s2)==min(y.s1,y.s2)) return max(x.s1,x.s2)<max(y.s1,y.s2);
	else return min(x.s1,x.s2)<min(y.s1,y.s2);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		long long ans=0;
		s1=s2=s3=0;
		memset(a,0,sizeof a);
		vector<dd> d1,d2,d3;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			int t=max(a[i].a,max(a[i].b,a[i].c));
			if(t==a[i].a){
				d1.push_back({i,t-a[i].b,t-a[i].c});
				s1++;
			}
			else if(t==a[i].b) {
				d2.push_back({i,t-a[i].a,t-a[i].c});
				s2++;
			}
			else{
				d3.push_back({i,t-a[i].a,t-a[i].b});
				s3++;
			}
			ans+=t;
		}
		sort(d1.begin(),d1.end(),cmp);
		sort(d2.begin(),d2.end(),cmp);
		sort(d3.begin(),d3.end(),cmp);
		if(s1>n/2){
			int p=0;
			while(s1>n/2){
				ans-=min(d1[p].s1,d1[p].s2);
				s1--;
				p++;
			}
		}
		if(s2>n/2){
			int p=0;
			while(s2>n/2){
				ans-=min(d2[p].s1,d2[p].s2);
				s2--;
				p++;
			}
		}
		if(s3>n/2){
			int p=0;
			while(s3>n/2){
				ans-=min(d3[p].s1,d3[p].s2);
				s3--;
				p++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
