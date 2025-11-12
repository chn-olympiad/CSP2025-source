#include<bits/stdc++.h>
using namespace std;
struct node{
	int p1,p2,p3;
	bool vis=false;
}a[10005];
bool asd1(node x,node y){
	return x.p1>y.p1;
}
bool asd2(node x,node y){
	return x.p2>y.p2;
}
bool asd3(node x,node y){
	return x.p3>y.p3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,sum=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].p1>>a[i].p2>>a[i].p3; 
		}
		sort(a,a+n,asd1);
		for(int i=0;i<n/2;i++){
			sum+=a[i].p1;
		}
		cout<<sum<<endl;
	}
	return 0;
}
