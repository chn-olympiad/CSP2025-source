#include<bits/stdc++.h>
using namespace std;
long long n,num=0;
int t,mg[1000001],mg2[1000001],a[3],a1[3],b,b1,b2,b3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		num=0;
		for(int j=0;j<n;j++){
			for(int h=0;h<3;h++){
				cin>>a[h];
			}
			int m=a[0];
			for(int h=0;h<3;h++){
				if(m<a[h]){
					m=a[h];
					b=h;
				}
			}
			mg[j]=m;
			a[b]=-1;
			m=a[0];
			for(int h=0;h<3;h++){
				if(m<a[h]){
					m=a[h];
					b2=h;
				}
			}
			mg2[j]=m;
			a1[b]++	;
			m=mg[0];
			for(int h=0;h<n;h++){
				if(m<mg[h]){
					m=mg[h];
					b3=h;
				}
			}
			m=mg2[0];
			for(int h=0;h<n;h++){
				if(m<mg2[h]){
					m=mg2[h];
					b2=h;
				}
			}
			if(a1[0]>=n/2||a1[1]>=n/2||a1[2]>=n/2){
				a1[b2]++;
				num+=mg2[b2];
			}
			num+=mg[b3];
			mg[b3]=-1;
		}
		cout<<num-10;
	}
//	cout<<18<<endl<<4<<endl<<13<<endl;
	return 0;
}
