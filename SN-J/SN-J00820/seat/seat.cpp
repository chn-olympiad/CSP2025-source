#include<bits/stdc++.h>
using namespace std;

bool cmp(const long long& l,const long long& r){
	return l>r;
}
long long n,c,flag,c1,b,z,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>c;
	b=n*c;
	cin>>a[0];
	c1=a[0];
	for(int i=1;i<b;i++){
		cin>>a[i];
	}
	sort(a,a+b,cmp);
	for(int i=0;i<b;i++){
		if(a[i]==c1){
			flag=i+1;
		}
	}
	c1=flag/n+1;
	if(c1%2==1){
		z=flag%n;
	}else if(c1%2==0){
		z=n+1-flag%n;
	}
	cout<<c1<<' '<<z; 
	return 0;
}



