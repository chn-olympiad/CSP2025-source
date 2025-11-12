#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const long long mod=998244353;
long long n,a[100050],s,maxx,s2,s3;

long long Read(){
	long long Ra=0,Rf=1;
	char Rc=getchar();
	while(Rc<'0'||Rc>'9'){
		if(Rc=='-') Rf=-1;
		Rc=getchar();
	}
	while(Rc>='0'&&Rc<='9'){
		Ra=(Ra<<1)+(Ra<<3)+(Rc&15);
		Rc=getchar();
	}
	return Ra*Rf;
}void b(long long now,long long sum,long long amax){
	if(now>n){
		if(sum>2*amax){
			s=(s+1)%mod;
		}
		return ;
	}
	b(now+1,sum+a[now],max(amax,a[now]));
	b(now+1,sum,amax);
}long long quick_pow(long long x,long long y){
	long long sum=1;
	while(y){
		if(y%2==1) sum=(sum*x)%mod;
		x=x*x%mod;
		y/=2;
	}
	return sum;
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=Read();
	for(int i=1;i<=n;i++){
		a[i]=Read();
		maxx=max(maxx,a[i]);
	}
	//O(2^n) 40+24=64
	if(maxx==1){
		for(int i=3;i<=n;i++){
			s2=1,s3=1;
			for(int j=n-i+1;j<=n;j++){
				s2=s2*j%mod;
			}
			for(int j=2;j<=i;j++){
				s3=s3*j%mod;
			}
			s2=(s2*quick_pow(s3,mod-2))%mod;
			s+=s2;
		}
	}else{
		b(1,0,0);
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
