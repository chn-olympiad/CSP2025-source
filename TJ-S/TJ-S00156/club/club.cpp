#include<bits/stdc++.h>
using namespace std;

int t,n,sum,ma,t1,t2,t3;
struct en{
	int m1,m2,m3;
	int m;
}a[100005];
bool cmp(en x,en y){
	return x.m1>y.m1;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i].m1>>a[i].m2>>a[i].m3;
			//a[i].m=a[i].m1+a[i].m2+a[i].m3;
		}
		//sort(a,a+n,cmp);
		for(int i=0;i<n/2;){
			sum+=a[i].
		}
		
	}
	
	return 0;
}
