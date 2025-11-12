//SN-J01067  郭思辰  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,d,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1;a+1+n);
	for(int i=1;i<=n*m;++i){
		if(a[i]==f&&i==n*m){
			s=1;
			d=1;
		}else if(a[i]==f&&i==1){
			s=m;
			d=n;
		}else if(a[i]==f&&i>n*m-n){
			s=m-1;
			d=n*m-n;
		}
	}
	cout<<s<<" "<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
