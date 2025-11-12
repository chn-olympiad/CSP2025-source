#include<bits/stdc++.h>
using namespace std;
int t,n;
struct ccf{
	int a1,a2,a3,max1,max2;
}a[100007];
bool cmp(ccf p,ccf q){
	return p.max1>q.max1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		int cnt=0;
		cin>>n;
		bool flag=0;
		for(int j=1;j<=n;j++){
			cin>>a[j].a1>>a[j].a2>>a[j].a3;
			if(a[j].a2==0&&a[j].a3==0)flag=1; 
			a[j].max1=max((max(a[j].a1,a[j].a2)),a[j].a3);
			if(a[j].max1==a[j].a1)a[j].max2=1;
			else if(a[j].max1==a[j].a2)a[j].max2=2;
			else a[j].max2=3;
		}
		sort(a+1,a+n+1,cmp);
		int m1=n/2,m2=n/2,m3=n/2,p=1;
		if(flag){
			while(m1){
				if(a[p].max2==1){
					cnt+=a[p].max1;
					m1--; 
				}
				p++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

