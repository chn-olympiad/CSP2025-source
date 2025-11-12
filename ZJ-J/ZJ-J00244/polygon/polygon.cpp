#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=5005, MAX=988244353;
int a[N];

ll digui(int i,int sum){
	if(sum<0){
		return 1<<i%MAX;
	}if(i==0){
		return 0;
	}
//	cout<<"digui("<<i<<","<<sum<<")"<<endl;
	return (digui(i-1,sum-a[i-1])+digui(i-1,sum))%MAX;
} 

int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdin);
	int n;
	ll s=0;
	bool is_one=true;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			is_one=false;
		}
	}
	sort(a,a+n);
	if(is_one){
		cout<<((1<<n)-n*(n-1)/2-n-1+MAX)%MAX;
		return 0;
	}
	for(int l=n-1;l>=3;l--){
		s%=MAX;
		s+=digui(l,a[l]);
	}
	cout<<s;
	return 0;
}
