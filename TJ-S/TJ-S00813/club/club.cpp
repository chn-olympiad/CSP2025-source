#include<bits/stdc++.h>
using namespace std;
struct qp{
	int s1,s2,s3;
};
bool cmp(qp x,qp y){
	return max(x.s1,max(x.s2,x.s3))>max(y.s1,max(y.s2,y.s3));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		qp a[100005]={};
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
		}
		int s=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			s+=max(a[i].s1,max(a[i].s2,a[i].s3));
		}
		cout<<s<<endl;
	}
	return 0;
}
