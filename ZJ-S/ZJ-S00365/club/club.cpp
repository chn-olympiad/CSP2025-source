#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct stu{
	int m,s;
}x[N];
bool cmp(stu &w,stu &v){
	return w.s<v.s;
}
void solve(){
	int n;
	scanf("%d",&n);
	int s1=0,s2=0,s3=0,ans=0;
	for(int i=1;i<=n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int mx=max({a,b,c});
		ans+=mx;
		if(a==mx){
			x[i]={1,min(mx-b,mx-c)};
			s1++;
		}
		else if(b==mx){
			x[i]={2,min(mx-a,mx-c)};
			s2++;
		}
		else{
			x[i]={3,min(mx-a,mx-b)};
			s3++;
		}
	}
	
//	cout<<"ans="<<ans<<endl;
	int k=max({s1,s2,s3});
	if(k>n/2){
    	int p;
    	if(k==s1) p=1;
		else if(k==s2) p=2;
		else p=3;
		sort(x+1,x+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<x[i].m<<" "<<x[i].s<<endl;
//		}
//		cout<<endl;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(x[i].m==p){
				cnt++;
				ans-=x[i].s;
			}
			if(cnt==k-n/2){
				break;
			}
//			cout<<ans<<endl;
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}
