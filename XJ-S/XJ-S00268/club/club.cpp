#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],ans,A,B;
struct yg {
	int a1;
	int a2;
	int a3;
	int f=0;	
};
yg my[100005];
bool cmp1(yg a,yg b){
	return a.a1>b.a1;
}
bool cmp2(yg a,yg b){
	return a.a2>b.a2;
}
bool cmp3(yg a,yg b){
	return a.a3>b.a3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++){
		memset(my,sizeof(my),0);
		ans=0;
		cin>>n;
		int sum1=0;
		for(int i=1;i<=n;i++){
			cin>>my[i].a1>>my[i].a2>>my[i].a3;	
			if(my[i].a2==0&&my[i].a3==0){
				A++;
			}
			if(my[i].a2==0){
				B++;
			}
		}
		if(A==n){
			sort(my+1,my+1+n,cmp1) ;
			cout<<my[1].a1+my[2].a1 ; 
			return 0;
		} 
		if(n==2){
			int s=max(my[1].a1+my[2].a2,my[1].a1+my[2].a3);
			int d=max(my[1].a2+my[2].a1,my[1].a2+my[2].a3);
			int e=max(my[1].a3+my[2].a1,my[1].a3+my[2].a2);
			s=max(s,d);
			s=max(s,e);
			cout<<s;
			return 0;
		}
		sort(my+1,my+1+n,cmp1) ;
		for(int i=1;i<=n;i++){
			if(sum1>n/2){
				continue;
			}
			if(my[i].f==0){
				ans=ans+my[i].a1;
				sum1++;
				my[i].f=1;
				//cout<<my[i].a1<<my[i].a2;
			}
		}
		sum1=0;
		sort(my+1,my+1+n,cmp2) ;
		for(int i=1;i<=n;i++){
			if(sum1>n/2){
				continue;
			}
			if(my[i].f==0){
				ans=ans+my[i].a2;
				sum1++;
				my[i].f=1;
				//cout<<my[i].a1<<my[i].a2;
			}
		}
		sum1=0;
		sort(my+1,my+1+n,cmp3) ;
		for(int i=1;i<=n;i++){
			if(sum1>n/2){
				continue;
			}
			if(my[i].f==0){
				ans=ans+my[i].a3;
				sum1++;
				my[i].f=1;
				//cout<<my[i].a1<<my[i].a2;

			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}  
