#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a1,a2,a3,m[5],ans,k,z1,z2,z3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(;t--;m[1]=0,m[2]=0,m[3]=0,ans=0,z1=0,z2=0,z3=0){
		cin>>n;
		int b1[n+5],b2[n+5],b3[n+5];
		for(int i=0;i<n;i++){
			cin>>a1>>a2>>a3;
			if(a1>a2&&a1>a3){
				m[1]++,ans+=a1;
				if(a2>a3)b1[z1++]=a1-a2;
				else b1[z1++]=a1-a3;
			}else if(a2>a1&&a2>a3){
				m[2]++,ans+=a2;
				if(a1>a3)b2[z2++]=a2-a1;
				else b2[z2++]=a2-a3;
			}else{
				m[3]++,ans+=a3;
				if(a1>a2)b3[z3++]=a3-a1;
				else b3[z3++]=a3-a2;
			}
		}
		if(m[1]>n/2){
			sort(b1,b1+z1),k=m[1]-n/2;
			for(int i=0;i<k;i++)ans-=b1[i];
		}else if(m[2]>n/2){
			sort(b2,b2+z2),k=m[2]-n/2;
			for(int i=0;i<k;i++)ans-=b2[i];
		}else{
			sort(b3,b3+z3),k=m[3]-n/2;
			for(int i=0;i<k;i++)ans-=b3[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
