//原梓轩 SN-J00169 440514201308033019 陕西-西安-锦园中学 
#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
long long b[25]={1,2};
long long sum,ans,zzjg,t;
long long ttt(long long x){
	long long two=1;
	while(x>0){
		two=two*10+x%2;
		x/=2;
	}
	return two;
}
int  main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout); 
	cin>>n;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=1;
		}
	}
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]*2;
	}
	if(n==3){
		if(a[3]+a[1]+a[2]>2*(max(max(a[3],a[1]),a[2]))){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(f!=1){
		for(int i=3;i<=n;i++){
			sum=1;
			for(int j=1;j<=i;j++){
				sum*=j;
			}
			ans=1;
			for(int j=n-i+1;j<=n;j++){
				ans*=j;
			}
			zzjg+=ans/sum;
		}
		cout<<zzjg;
	}
	else{
		
		for(int i=0;i<=b[n];i++){
			t=ttt(i)-1;
			sum=0,ans=0;
			int j=0;
//			cout<<i<<":"<<t<<" "<<endl;
			while(t>0){
				if(t%10==1){
//					cout<<j<<" ";
//					cout<<t<<endl;
					sum+=a[j];
					ans=max(ans,a[j]);
//					cout<<endl<<sum<<"Yee"<<ans<<"YEEEEEE"<<endl;
				}
				t/=10;
				j++;
			}
//			cout<<endl;
			if(sum>2*ans){
				zzjg++;
			}
		}
		cout<<zzjg;
	}
	return 0;
}
