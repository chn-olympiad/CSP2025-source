#include<bits/stdc++.h>
using namespace std;
int n,rm1,rm2,rm3,ans,c,t;
bool ff; 
struct mm{
	int m1,m2,m3,num;
	bool f;
};
bool cmp1(mm x,mm y){
	return x.m1>y.m1;
}
bool cmp2(mm x,mm y){
	return x.m2>y.m2;
}
bool cmp3(mm x,mm y){
	return x.m3>y.m3;
}
mm a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=0;j<t;j++){
		 cin>>n;
		 ans=0;
    for(int i=0;i<n;i++){
    	cin>>a[i].m1>>a[i].m2>>a[i].m3;
    	a[i].num=i;
    	a[i].f=0;
	}
	for(int c=1;c<=4;c++){
		sort(a,a+n,cmp1);
		for(int i=0;i<n;i++){
			if(rm1>n/2) break;
			if(c==1&&a[i].f==0){
				if(a[i].m1>a[i].m2&&a[i].m1>a[i].m3&&a[i].f==0){
				    rm1++;
				    a[i].f=1;
				    ans+=a[i].m1;
		    	}
			}
			else if(c==2&&a[i].f==0){
				if(a[i].m2>a[i].m1&&a[i].m1>a[i].m3&&rm2>=n/2){
					rm1++;
					a[i].f=1;
					ans+=a[i].m1;
				}
				else if(a[i].m3>a[i].m1&&a[i].m1>a[i].m2&&rm3>=n/2){
					rm1++;
					a[i].f=1;
					ans+=a[i].m1;
				}
			}
			else if(c==3&&a[i].f==0){
				if(a[i].m1<a[i].m2&&a[i].m1<a[i].m3&&rm2>=n/2&&rm3>=n/2){
					rm1++;
					a[i].f=1;
					ans+=a[i].m1;
				}
			}
		}
		sort(a,a+n,cmp2);
		for(int i=0;i<n;i++){
			if(rm2>n/2) break;
			if(c==1&&a[i].f==0){
				if(a[i].m2>a[i].m1&&a[i].m2>a[i].m3){
				    rm2++;
					a[i].f=1;
					ans+=a[i].m2;
		    	}
			}
			else if(a[i].f==0&&c==2){
				if(a[i].m2>a[i].m1&&a[i].m1>a[i].m3&&rm2>=n/2){
					rm2++;
					a[i].f=1;
					ans+=a[i].m2;
				}
				else if(a[i].m3>a[i].m1&&a[i].m1>a[i].m2&&rm3>=n/2){
					rm2++;
					a[i].f=1;
					ans+=a[i].m2;
				}
			}
			else if(a[i].f==0&&c==3){
				if(a[i].m1<a[i].m2&&a[i].m1<a[i].m3&&rm2>=n/2&&rm3>=n/2){
					rm2++;
					a[i].f=1;
					ans+=a[i].m2;
				}
			}
		}
		sort(a,a+n,cmp3);
		for(int i=0;i<n;i++){
			if(rm2>n/2) break;
			if(a[i].f==0&&c==1){
				if(a[i].m3>a[i].m2&&a[i].m3>a[i].m1){
				    rm3++;
					a[i].f=1;
					ans+=a[i].m3;
		    	}
			}
			else if(a[i].f==0&&c==2){
				if(a[i].m2>a[i].m3&&a[i].m3>a[i].m1&&rm2>=n/2){
					rm3++;
					a[i].f=1;
					ans+=a[i].m3;
				}
				else if(a[i].m3>a[i].m2&&a[i].m1>a[i].m3&&rm1>=n/2){
					rm3++;
					a[i].f=1;
					ans+=a[i].m3;
				}
			}
			else if(a[i].f==0&&c==3){
				if(a[i].m3<a[i].m2&&a[i].m3<a[i].m1&&rm2>=n/2&&rm1>=n/2){
					rm3++;
					a[i].f=1;
					ans+=a[i].m3;
				}
			}
		}
	}
	cout<<ans<<endl;
	}
	return 0;
}
