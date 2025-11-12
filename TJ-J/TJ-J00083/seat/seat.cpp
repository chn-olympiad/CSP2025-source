#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],h,l;
bool cmp(int a,int b){
	return a>b;
}
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1],sum;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(t==a[i]){
			sum=i;
		}
	}
	if(sum%n==0){
		l=sum/n;
		if(l%2==1){
			cout<<l<<' '<<n;
			return 0;
		}else{
			cout<<l<<' '<<1;
			return 0;
		}
	}else{
		l=sum/n+1;
	}
	int s=sum%n;
	if(l%2){
		h=s;
	}else{
		h=n-s+1;
	}
	cout<<l<<' '<<h;
	
	fclose(stdin);
	fclose(stdout); 
} 
