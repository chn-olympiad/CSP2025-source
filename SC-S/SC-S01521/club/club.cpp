#include<bits/stdc++.h>
using namespace std;
struct str{
	long long c1,c2,c3;
	bool flag;
}a[100005];
bool cmp(str x,str y){
	return x.c1>y.c1;
}
bool cm(str x,str y){
	return x.c2>y.c2;
}
bool mp(str x,str y){
	return x.c3>y.c3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long t;
	cin>>t;
	while(t--){
		long long n,ans=0,cnt=0;
		cin>>n;
		//输入 
		for(int i=0;i<n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
			a[i].flag=0;
		}
		//部门 1 
		sort(a,a+n,cmp);
		cnt=0;
		for(int i=0;i<n;i++){
			if(cnt==n/2) break;
			if(a[i].flag==0){
				if(a[i].c1>a[i].c2&&a[i].c1>a[i].c3){
					ans+=a[i].c1;
					a[i].flag=1; 
					cnt++;
				}
			}
		} 
		//部门 2
		sort(a,a+n,cm);
		cnt=0;
		for(int i=0;i<n;i++){
			if(cnt==n/2) break;
			if(a[i].flag==0){
				if(a[i].c2>a[i].c1&&a[i].c2>a[i].c3){
					ans+=a[i].c2;
					a[i].flag=1; 
					cnt++;
				}
			}
		} 
		//部门 3   
		sort(a,a+n,mp);
		cnt=0;
		for(int i=0;i<n;i++){
			if(cnt==n/2) break;
			if(a[i].flag==0){
				if(a[i].c3>a[i].c2&&a[i].c3>a[i].c1){
					ans+=a[i].c3;
					a[i].flag=1; 
					cnt++;
				}
			}
		} 
		cout<<ans<<"\n";
	}
	return 0;
} 