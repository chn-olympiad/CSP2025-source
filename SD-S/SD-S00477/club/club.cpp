#include<bits/stdc++.h>
using namespace std;
int t,n;
struct s{
	int d1;
	int d2;
	int d3;
	int d=0;
};
bool d1(s a1,s a2){
	return a1.d1> a2.d1;
}
bool d2(s a1,s a2){
	return a1.d2> a2.d2;
}
bool d3(s a1,s a2){
	return a1.d3> a2.d3;
}
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>t;
    for(int o=1;o<=t;o++){
	cin>>n;
    	s a[n+2];
    	for(int i=1;i<=n;i++){
    		cin>>a[i].d1;
    		cin>>a[i].d2;
    		cin>>a[i].d3;
		}
		//1,2,3
		long long num1=0;
		sort(a+1,a+n+1,d1);//+d1
			int ad1=0;
		for(int i=1;i<=n;i++){
			if(a[i].d1>=a[i].d2){
				ad1++;
				num1+=a[i].d1;
				a[i].d=1;
			}
			if(ad1>=n/2) break;
		}
		sort(a+1,a+n+1,d2);
			int ad2=0;
		for(int i=1;i<=n;i++){//+d2
			if(a[i].d==0&&a[i].d2>=a[i].d3){
				ad2++;
				num1+=a[i].d2;
			    a[i].d=2;
			}
			if(ad2>=n/2) break;
		}
		for(int i=1;i<=n;i++){//+d3
			if(a[i].d==0){
				num1+=a[i].d3;
			}
			a[i].d=0;
		}
		//2,1,3
		long long num2=0;//+d2
		ad1=0;
		for(int i=1;i<=n;i++){
			if(a[i].d2>a[i].d3){
				
				ad1++;
				num2+=a[i].d2;
				a[i].d=1;
			}
			if(ad1>=n/2) break;
		}
		sort(a+1,a+n+1,d1);
		ad2=0;
		for(int i=1;i<=n;i++){//+d3
			if(a[i].d==0){
				ad2++;
				num2+=a[i].d1;
			    a[i].d=2;
			}
			if(ad2>=n/2) break;
		}
		for(int i=1;i<=n;i++){//+d1
			if(a[i].d==0){
				num2+=a[i].d3;
			}
			a[i].d=0;
		}
		cout<<max(num2,num1)<<endl;
		num1=0;
		ad2=0;
		ad1=0;
    	
	}
	return 0;
}

