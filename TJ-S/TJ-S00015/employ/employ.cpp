#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool s[509];
	int c[509];
	bool h=true;
	char cc;
	for(int i=0;i<n;i++){
		cin>>cc;
		s[i]=cc-'0';
	}
	int ssum=0;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]!=0){
			ssum++;
		}
	}
	int mod=998244353;
	int a[n];
	for(int i=0;i<n;i++){
		a[i]=i;
	}
	int sum=0,su=0;
	if(n<=10){
	do{
		su=0;
		for(int i=0;i<n;i++){
//			cout<<su<<' '<<c[a[i]]<<endl;
			if(s[i]==0||su>=c[a[i]]){
				su++;
//				cout<<a[i]<<' ';
			}
		}
//		cout<<su<<endl;
		if(n-su>=m){
			sum++;
		}
	}while(next_permutation(a,a+n));
	cout<<sum;
    }
    else{
    	cout<<0;
	}
	return 0;
}
