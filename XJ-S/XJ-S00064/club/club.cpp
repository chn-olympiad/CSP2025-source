#include<bits/stdc++.h>
using namespace std;
int n,t;
struct N{
	int a1,a2,a3,a4;
}a[100005];
bool cmp(N x,N y){
	return x.a4>y.a4;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].a4=abs(a[i].a1-a[i].a2);
		}
		int num1=0,num2=0,num3=0;
		int sum=0;
		if(n==2){
			sum=max(a[1].a1+a[2].a2,max(a[1].a1+a[2].a3,max(a[1].a2+a[2].a1,max(a[1].a2+a[2].a3,max(a[1].a3+a[2].a1,a[1].a3+a[2].a2)))));
			
		}
		else{
		sort(a+1,a+n+1,cmp);
		
		for(int i=1;i<=n;i++){
			if(a[i].a1>a[i].a2){
				if(num1<n/2){
					sum+=a[i].a1;
					num1++;
				}
				else{
					sum+=a[i].a2;
					num2++;
				}
			}
			else{
				if(num2<n/2){
					sum+=a[i].a2;
					num2++;
				}
				else{
					sum+=a[i].a1;
					num1++;
				}
			}
		}}
		cout<<sum<<endl;
	}
	return 0;
} 

