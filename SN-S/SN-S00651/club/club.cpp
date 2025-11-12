#include<bits/stdc++.h>
using namespace std;
long long n,m,l,t;
struct man{
	int c1,c2,c3;
	int of1,of2,of3;
	int x;
	bool p=true;
}a[10086];
bool oiof1(man a,man b){
	if(a.of1>=b.of1){
		return a.of1>b.of1;
	}
	return a.of1>b.of1;
}
bool oic1(man a,man b){
	if(a.c1>=b.c1){
		return a.c1>b.c1;
	}
	return a.c1>b.c1;
}
bool oiof2(man a,man b){
	if(a.of2>=b.of2){
		return a.of2>b.of2;
	}
	return a.of2>b.of2;
}
bool oic2(man a,man b){
	if(a.c2>=b.c2){
		return a.c2>b.c2;
	}
	return a.c2>b.c2;
}
bool oiof3(man a,man b){
	if(a.of3>=b.of3){
		return a.of3>b.of3;
	}
	return a.of3>b.of3;
}
bool oic3(man a,man b){
	if(a.c3>=b.c3){
		return a.c3>b.c3;
	}
	return a.c3>b.c3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		cin>>n;
		l=n;
		for(int i=1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
			a[i].x=i;
			if(a[i].c1>=a[i].c2&&a[i].c1>=a[i].c3){
				a[i].of1=3;
				if(a[i].c2>=a[i].c3){
					a[i].of2=2;
					a[i].of3=1;
				}
				else{
					a[i].of2=1;
					a[i].of3=2;
				}
			}
			if(a[i].c2>=a[i].c1&&a[i].c2>=a[i].c3){
				a[i].of2=3;
				if(a[i].c1>=a[i].c3){
					a[i].of1=2;
					a[i].of3=1;
				}
				else{
					a[i].of1=1;
					a[i].of3=2;
				}
			}
			if(a[i].c3>=a[i].c2&&a[i].c3>=a[i].c1){
				a[i].of3=3;
				if(a[i].c2>=a[i].c3){
					a[i].of2=2;
					a[i].of1=1;
				}
				else{
					a[i].of2=1;
					a[i].of1=2;
				}
			}
		}
		//1
		sort(a+1,a+1+n,oiof1);
		sort(a+1,a+1+n,oic1);
		for(int i=1;i<=n/2;i++){
			if(a[i].of1!=3){
				break;
			}
			m=m+a[i].c1;
			a[i].p=false;
			l--;
		}
		for(int i=1;i<=n;i++){
			a[i].c1=0;
			a[i].of1=0;
			a[i].of2++;
			a[i].of3++;
			if(a[i].of2==4){
				a[i].of2--;
			}
			if(a[i].of3==4){
				a[i].of3--;
			}
		}
		//2
		sort(a+1,a+1+n,oiof2);
		sort(a+1,a+1+n,oic2);
		for(int i=1;i<=n/2;i++){
			if(l==0){
				break;
			}
			if(a[i].of2!=3){
				break;
			}
			m=m+a[i].c2;
			a[i].p=false;
			l--;
		}
		for(int i=1;i<=n;i++){
			a[i].c2=0;
			a[i].of2=0;
			a[i].of3++;
			if(a[i].of3==4){
				a[i].of3--;
			}
		}
		//3
		sort(a+1,a+1+n,oiof3);
		sort(a+1,a+1+n,oic3);
		for(int i=1;i<=n/2;i++){
			if(l==0){
				break;
			}
			if(a[i].of3!=3){
				break;
			}
			m=m+a[i].c3;
			a[i].p=false;
			l--;
		}
		cout<<m<<endl;
		m=0;
		for(int i=1;i<=n;i++){
			a[i].c1=0;
			a[i].c2=0;
			a[i].c3=0;
			a[i].of1=0;
			a[i].of2=0;
			a[i].of3=0;
			a[i].p=true;
		}
	}
}
