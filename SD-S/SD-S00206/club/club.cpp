#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a,b,c;
	int NO;
};
stu a[100001]={};
int maxn=0;
int cmp1(stu q,stu p){

	return q.a>p.a;
}
int cmp2(stu q,stu p){
	return q.b>p.b;
}
int cmp3(stu q,stu p){ 
	return q.c>p.c;
}
int ans=0;
int main(){
  	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		ans=0;
		int n;cin>>n;
		maxn=n/2;
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].NO=0;
		}
		sort(a,a+n,cmp1);
		int x=0;
		for(int i=0;i<n;i++){
			x++;
			if(a[i].b==0&&a[i].c==0&&x<=maxn){
				a[i].NO=1;
			}
			else if(a[i].NO==0&&a[i].a>=a[i].b&&a[i].a>=a[i].c&&x<=maxn){
				a[i].NO=1;
			}
		}
		sort(a,a+n,cmp2);
		x=0;
		for(int i=0;i<n;i++){
			x++;
			if(a[i].a==0&&a[i].b==0&&x<=maxn){
				a[i].NO=2;
			}
			else if(a[i].NO==0&&a[i].b>=a[i].a&&a[i].b>=a[i].c&&x<=maxn){
				a[i].NO=2;
			}
		}
		sort(a,a+n,cmp3);
		x=0;
		for(int i=0;i<n;i++){
			x++;
			if(a[i].a==0&&a[i].b==0&&x<=maxn){
				a[i].NO=3;
			}
			else if(a[i].NO==0&&a[i].c>=a[i].a&&a[i].c>=a[i].b&&x<=maxn){
				a[i].NO=3;
			}
		}
		for(int i=0;i<n;i++){
			if(a[i].NO==1){
				ans+=a[i].a;
			}
			if(a[i].NO==2){
				ans+=a[i].b;
			}
			if(a[i].NO==3){
				ans+=a[i].c;
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}
