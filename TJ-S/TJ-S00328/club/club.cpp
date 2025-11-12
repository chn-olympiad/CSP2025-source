#include<bits/stdc++.h>
using namespace std;
struct p{
	int a1,a2,a3;
}a[100005];
bool px1(p p1,p p2){
	return p1.a1>=p2.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,sum=0,o1,o2,o3,o4;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		} 
		if(n==2){
			int q1,q2,q11,q22;
			if(a[1].a1>=a[1].a2&&a[1].a1>=a[1].a3){
				q1=a[1].a1;
				q11=1;
			}else if(a[1].a2>=a[1].a1&&a[1].a2>=a[1].a3){
				q1=a[1].a2;
				q11=2;
			}else if(a[1].a3>=a[1].a1&&a[1].a3>=a[1].a2){
				q1=a[1].a3;
				q11=3;
			}
			if(a[2].a1>=a[2].a2&&a[2].a1>=a[2].a3){
				q2=a[2].a1;
				q22=1;
			}else if(a[2].a2>=a[2].a1&&a[2].a2>=a[2].a3){
				q2=a[2].a2;
				q22=2;
			}else if(a[2].a3>=a[2].a1&&a[2].a3>=a[2].a2){
				q2=a[2].a3;
				q22=3;
			}
			sum=q1+q2;
			if(q11==q22){
				if(q11==1){
					o1=a[1].a1-a[1].a2;
					o2=a[1].a1-a[1].a3;
				}else if(q11==2){
					o1=a[1].a2-a[1].a1;
					o2=a[1].a2-a[1].a3;
				}else if(q11==3){
					o1=a[1].a3-a[1].a1;
					o2=a[1].a3-a[1].a2;
				}
				if(q22==1){
					o3=a[2].a1-a[2].a2;
					o4=a[2].a1-a[2].a3;
				}else if(q22==2){
					o3=a[2].a2-a[2].a1;
					o4=a[2].a2-a[2].a3;
				}else if(q22==3){
					o3=a[2].a3-a[2].a1;
					o4=a[2].a3-a[2].a2;
				}
				sum-=min(min(min(o1,o2),o3),o4);
			}
		}else{
			sort(a+1,a+n+1,px1);
			for(int i=1;i<=n/2;i++){
				sum+=a[i].a1;
			}
		}
		cout<<sum;
	}
}
