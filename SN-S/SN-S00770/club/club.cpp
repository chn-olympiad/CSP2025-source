//韩骁-SN-S00770-西安高新第一中学南校区
#include<iostream>
#include<algorithm>
using namespace std;
int t,n,ans;
struct stu{
	int c1,c2,c3;
}a[100010];
bool cmp(stu a,stu b){
	if(a.c1!=b.c1) return a.c1>b.c1;
	if(a.c2!=b.c2) return a.c2>b.c2;
	return a.c3>b.c3;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n; ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
		} 
	    if(n==2){
	    	int ans1=a[1].c1+a[2].c2;
			int ans2=a[1].c1+a[2].c3; 
			int ans3=a[1].c2+a[2].c1;
			int ans4=a[1].c2+a[2].c3; 
			int ans5=a[1].c3+a[2].c1;
			int ans6=a[1].c3+a[2].c2; 
			int ans=max(ans1,ans2);
			ans=max(ans,ans3);
			ans=max(ans,ans4);
			ans=max(ans,ans5);
			ans=max(ans,ans6);
			cout<<ans<<endl;;
		}
		else{
			sort(a+1,a+n+1,cmp);
			int js1=0,js2=0,js3=0;
		    for(int i=1;i<=n;i++){
				if(a[i].c1>=a[i].c2&&a[i].c1>=a[i].c2&&js1<n/2){
					js1++; ans+=a[i].c1;
				}
				if(a[i].c2>=a[i].c1&&a[i].c2>=a[i].c3&&js2<n/2){
					js2++; ans+=a[i].c2;
				}
				if(a[i].c3>=a[i].c2&&a[i].c3>=a[i].c1&&js3<n/2){
					js3++; ans+=a[i].c3;
				}
		    }
		    cout<<ans<<endl;
		}
	}
	return 0;
}

