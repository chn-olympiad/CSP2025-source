#include<bits/stdc++.h>
using namespace std;
struct c{
	int a1,a2,a3;
}a[100005];
bool cmp1(c c1,c c2){
	return c1.a1>c2.a1;
}
int main(){
	//freopen
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,sum=0,ans=0;
		cin>>n;
		int x=n/2;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
	 	}
	 	if(n==2){
			sum+=(max(max(a[2].a1,a[2].a2),a[2].a3));
			if(a[1].a1>a[1].a2){
				if(a[1].a3>a[1].a1){
					sum+=a[1].a1;
				}
				else if(a[1].a3<a[1].a2){
					sum+=a[1].a2;
				}
				else{
					sum+=a[1].a3;
				}
			}else{
				if(a[1].a3>a[1].a2){
					sum+=a[1].a2;
				}
				else if(a[1].a3<a[1].a1){
					sum+=a[1].a1;
				}
				else{
					sum+=a[1].a3;
				}
			}
			ans+=(max(max(a[1].a1,a[1].a2),a[1].a3));
			if(a[2].a1>a[2].a2){
				if(a[2].a3>a[2].a1){
					ans+=a[2].a1;
				}
				else if(a[2].a3<a[2].a2){
					ans+=a[2].a2;
				}
				else{
					ans+=a[2].a3;
				}
			}else{
				if(a[2].a3>a[2].a2){
					ans+=a[2].a2;
				}
				else if(a[2].a3<a[2].a1){
					ans+=a[2].a1;
				}
				else{
					ans+=a[2].a3;
				}
			}
			if(sum>ans){
				ans=sum;
			}
			cout<<ans<<endl;
		} 
		else{
	 		sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=x;i++){
				if(a[i].a2==0 && a[i].a3==0){
					sum+=a[i].a1;	
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
