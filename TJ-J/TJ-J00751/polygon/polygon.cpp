#include<bits/stdc++.h>
using namespace std;
long long n,c[50005],ans=0;
int w1(int a,int b,int d){
	long long  m=0,z=0,ans1=0;
	for(int i=a;i<=a+b;i++){
		if(i!=d){
			m=max(m,c[i]);
			z=z+c[i];
		}
	}
	if(m*2<z)ans1++;
	for(int i=a;i<=a+b;i++){
		if(i!=d){
			ans1=ans1+w1(a,b,i);
		}
	}
	return ans1;
}
int w(int a,int b){
	long long m=0,z=0,ans1=0;
	for(int i=a;i<=a+b;i++){
		m=max(m,c[i]);
		z=z+c[i];
	}
	if(m*2<z)ans1++;
	for(int i=a;i<=a+b;i++){
		ans1=ans1+w1(a,b,i);
	}
	return ans1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long m=0,l=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		m=max(m,c[i]);
	}
	if(m==1){
		for(int i=1;i<=n;i++)ans=ans+i;
		cout<<ans;
		return 0;
	}
	if(n==3){
		m=m*2;
		if(m>c[1]+c[2]+c[3])cout<<"0";
		else cout<<"1";
		return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(c[i]>c[j])swap(c[i],c[j]);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			l=w(i,j-i);
			ans=ans+l;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
