#include <iostream>
using namespace std;
long long read(){
	long long nov=1,dat=0;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			nov-1;
			c=getchar();
		}
	}
	while(c>='0'&&c<='9'){
		dat=(dat<<3)+(dat<<1)+(c&15);
		c=getchar();
	}
	return nov*dat;
}
int n,m,sum1=0,sum2=0;
int p[505],cc[505];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	int j=1;
	char c=getchar();
	while(c=='1'||c=='0'){
		if(c=='1'){
			cc[j]=1;
			sum1++;
		}
		if(c=='0'){
			cc[j]=0;
			sum2++;
		}
		j++;
		c=getchar();
	}
	/*for(int i=1;i<=n;i++){
		char c=getchar();
		if(c=='1'){
			cc[i]=1;
			sum1++;
		}
		if(c=='0'){
			cc[i]=0;
			sum2++;
		}
	}*/
	for(int i=1;i<=n;i++){
		p[i]=read();
	}
//	for(int i=1;i<=n;i++){
//		cout<<p[i]<<" ";
//	}
	if(sum1==n){
		for(int i=2;i<=n;i++){
			ans=(ans*i)%998244353;
		}
		cout<<ans;
		return 0;
	}
	if(sum2==n){
		cout<<0;
		return 0;
	}
	if(sum1<m){
		cout<<0;
		return 0;
	} 
	if(m==n){
		if(sum2){
			cout<<0;
			return 0;
		}
	}
	if(m==1){
		int id=1,sum3=0;
		for(int i=1;;i++){
			if(cc[i]==1){
				id=i;
				break;
			}
		}
	//	cout<<id<<endl;
		for(int i=1;i<=n;i++){
			if(p[i]>=(id-1)){
				sum3++;
			//	cout<<i<<" ";
			} 
		}
		ans=sum3;
		for(int i=2;i<n;i++){
			ans=(ans*i)%998244353;
		}
		cout<<ans;
		return 0;	
	}
	cout<<0;
	return 0;
}
