#include<bits/stdc++.h>
using namespace std;
struct cy{
	int d1=0;int d2=0;int d3=0;
	int b1=0;int b2=0;int b3=0;
	int mn=0;
};
cy a[100005];
bool p1(cy x,cy y){
	if(x.d1>y.d1) return 1;
	else return 0;
}
bool p2(cy x,cy y){
	if(x.d2>y.d2) return 1;
	else return 0;
}
//bool p2(cy x,cy y){
//	if(x.b2==1&&y.b2==0) return 1;
//	else if(x.b2==1&&y.b2==1) return 1;
//	else return 0;
//}
//bool p3(cy x,cy y){
//	if(x.b3==1&&y.b3==0) return 1;
//	else if(x.b3==1&&y.b3==1) return 1;
//	else return 0;
//}
bool c1(cy x,cy y){
	if(x.mn!=0&&y.mn!=0){
		if(x.mn>y.mn) return 1;
		else return 0;
	}else if(x.mn!=0&&y.mn==0) return 1;
	else return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	int n;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			a[j].b1=0;a[j].b1=0;a[j].b1=0;
		}
		int zh1=0,zh2=0,zh3=0;int r1=0,r2=0,r3=0;int s1=0;
		for(int j=1;j<=n;j++){
			int mx=0;
			cin>>a[j].d1>>a[j].d2>>a[j].d3;
			zh1+=a[j].d1;
			zh2+=a[j].d2;
			zh3+=a[j].d3;
			if(a[j].d1>=a[j].d2&&a[j].d1>=a[j].d3){
				r1++;a[j].b1=1;s1+=a[j].d1;
			}
			else if(a[j].d2>=a[j].d3&&a[j].d2>=a[j].d1){
				r2++;a[j].b2=1;s1+=a[j].d2;
			}
			else if(a[j].d3>=a[j].d2&&a[j].d3>=a[j].d1){
				r3++;a[j].b3=1;s1+=a[j].d3;
			}
		}
		if(zh3==0){
			if(zh2==0){
				sort(a+1,a+n+1,p1);
				for(int j=n/2+1;j<=n;j++){
					zh1-=a[j].d1;
				}
				cout<<zh1<<endl;
			}else{
				int s0=zh1+zh2,s2=zh1+zh2;
				sort(a+1,a+n+1,p1);
				for(int j=n/2+1;j<=n;j++){
					s0-=a[j].d1;
				}
				for(int j=1;j<=n/2;j++){
					s0-=a[j].d2;
				}
				sort(a+1,a+n+1,p2);
				for(int j=n/2+1;j<=n;j++){
					s2-=a[j].d2;
				}
				for(int j=1;j<=n/2;j++){
					s2-=a[j].d1;
				}
				cout<<max(s0,s2)<<endl;
			}
		}else{
			if(r1>n/2){
			//sort(a+1,a+n+1,p1);
			for(int j=1;j<=n;j++){
				if(a[j].b1!=0)
					a[j].mn=min(abs(-a[j].d1+a[j].d2),abs(-a[j].d1+a[j].d3));
			}
			sort(a+1,a+n+1,c1);
			for(int j=n/2+1;j<=r1;j++){
				s1=s1-a[j].mn;
			}
		}
		else if(r2>n/2){
			//sort(a+1,a+n+1,p2);
			for(int j=1;j<=n;j++){
				if(a[j].b2!=0)
					a[j].mn=min(abs(-a[j].d2+a[j].d1),abs(-a[j].d2+a[j].d3));
			}
			sort(a+1,a+n+1,c1);
			for(int j=n/2+1;j<=r2;j++){
				s1=s1-a[j].mn;
			}
		}
		else if(r3>n/2){
		//	sort(a+1,a+n+1,p3);
			for(int j=1;j<=n;j++){
				if(a[j].b3!=0)
					a[j].mn=min(abs(-a[j].d3+a[j].d1),abs(-a[j].d3+a[j].d2));
			}
			sort(a+1,a+n+1,c1);
			for(int j=n/2+1;j<=r3;j++){
				s1=s1-a[j].mn;
			}
		}
		cout<<s1<<endl;
		}

	}
	return 0;
}