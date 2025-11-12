#include<bits/stdc++.h>
using namespace std;
int t,n,cnt1,cnt2,cnt3,cnt4,cnt5,cnt6;
int nx,ny,nz,num;
struct cj{
	int x;
	int y;
	int z;
};

bool f1(cj a,cj b){
	if(a.x>b.x){
		return true;
	}
	return false;
}

bool f2(cj a,cj b){
	if(a.y>b.y){
		return true;
	}
	return false;
}

bool f3(cj a,cj b){
	if(a.z>b.z){
		return true;
	}
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	cj a[100005],b[100005];
	
	for(int i = 1;i<=t;i++){
		cin>>n;
		
		for(int j = 1;j<=n;j++){
			cin>>a[j].x>>a[j].y>>a[j].z;
//			a[j].x = b[j].x;
//			a[j].y = b[j].y;
//			a[j].z = b[j].z; 
		}
		int m = n;

		while( m>=0 ){
			sort(a+1,a+1+n,f1);
			cnt1+=a[1].x;
			a[1].x = 0;
			a[1].y = 0;
			a[1].z = 0;
			m--;
			
			sort(a+1,a+1+n,f2);
			cnt1+=a[1].y;
			a[1].x = 0;
			a[1].y = 0;
			a[1].z = 0;
			m--;
			
			sort(a+1,a+1+n,f3);
			cnt1+=a[1].z;
			a[1].z = 0;
			a[1].y = 0;
			a[1].x = 0;
			m--;
		}
		m = n;
		
//		for(int j = 1;j<=n;j++){
//			a[j].x = b[j].x;
//			a[j].y = b[j].y;
//			a[j].z = b[j].z; 
//		}
//		while( m>=0 ){
//			sort(a+1,a+1+n,f1);
//			cnt2+=a[1].x;
//			a[1].x = 0;
//			a[1].y = 0;
//			a[1].z = 0;
//			m--;
//			
//			sort(a+1,a+1+n,f3);
//			cnt2+=a[1].z;
//			a[1].x = 0;
//			a[1].y = 0;
//			a[1].z = 0;
//			m--;
//			
//			sort(a+1,a+1+n,f2);
//			cnt2+=a[1].y;
//			a[1].z = 0;
//			a[1].y = 0;
//			a[1].x = 0;
//			m--;
//		}
//		m = n;
//		
//		for(int j = 1;j<=n;j++){
//			a[j].x = b[j].x;
//			a[j].y = b[j].y;
//			a[j].z = b[j].z; 
//		}
//		while( m>=0 ){
//			sort(a+1,a+1+n,f2);
//			cnt3+=a[1].y;
//			a[1].x = 0;
//			a[1].y = 0;
//			a[1].z = 0;
//			m--;
//			
//			sort(a+1,a+1+n,f1);
//			cnt3+=a[1].x;
//			a[1].x = 0;
//			a[1].y = 0;
//			a[1].z = 0;
//			m--;
//			
//			sort(a+1,a+1+n,f3);
//			cnt3+=a[1].z;
//			a[1].z = 0;
//			a[1].y = 0;
//			a[1].x = 0;
//			m--;
//		}
//		m = n;
//		
//		for(int j = 1;j<=n;j++){
//			a[j].x = b[j].x;
//			a[j].y = b[j].y;
//			a[j].z = b[j].z; 
//		}
//		while( m>=0 ){
//			sort(a+1,a+1+n,f2);
//			cnt4+=a[1].y;
//			a[1].x = 0;
//			a[1].y = 0;
//			a[1].z = 0;
//			m--;
//			
//			sort(a+1,a+1+n,f3);
//			cnt4+=a[1].z;
//			a[1].x = 0;
//			a[1].y = 0;
//			a[1].z = 0;
//			m--;
//			
//			sort(a+1,a+1+n,f1);
//			cnt4+=a[1].x;
//			a[1].z = 0;
//			a[1].y = 0;
//			a[1].x = 0;
//			m--;
//		}
//		m = n;
//		
//		for(int j = 1;j<=n;j++){
//			a[j].x = b[j].x;
//			a[j].y = b[j].y;
//			a[j].z = b[j].z; 
//		}
//		while( m>=0 ){
//			sort(a+1,a+1+n,f3);
//			cnt5+=a[1].y;
//			a[1].x = 0;
//			a[1].y = 0;
//			a[1].z = 0;
//			m--;
//			
//			sort(a+1,a+1+n,f2);
//			cnt5+=a[1].y;
//			a[1].x = 0;
//			a[1].y = 0;
//			a[1].z = 0;
//			m--;
//			
//			sort(a+1,a+1+n,f1);
//			cnt5+=a[1].x;
//			a[1].z = 0;
//			a[1].y = 0;
//			a[1].x = 0;
//			m--;
//		}
//		m = n;
//		
//		for(int j = 1;j<=n;j++){
//			a[j].x = b[j].x;
//			a[j].y = b[j].y;
//			a[j].z = b[j].z; 
//		}
//		while( m>=0 ){
//			sort(a+1,a+1+n,f3);
//			cnt6+=a[1].z;
//			a[1].x = 0;
//			a[1].y = 0;
//			a[1].z = 0;
//			m--;
//			
//			sort(a+1,a+1+n,f1);
//			cnt6+=a[1].x;
//			a[1].x = 0;
//			a[1].y = 0;
//			a[1].z = 0;
//			m--;
//			
//			sort(a+1,a+1+n,f2);
//			cnt6+=a[1].y;
//			a[1].z = 0;
//			a[1].y = 0;
//			a[1].x = 0;
//			m--;
//		}
//		m = n;
//		
//		int maxx = max(cnt1,max(cnt2,max(cnt3,max(cnt4,max(cnt5,cnt6)))));
//		
		cout<<cnt1<<endl;
		cnt1 = 0;
		
	}
}
