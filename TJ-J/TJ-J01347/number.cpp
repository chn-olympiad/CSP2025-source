#include<iostream>
using namespace std;
int main(){
	int b[101],s,a[0],m,k,z,v;
	cin>>a[0];
	for(int i=a[0];i>0;i/=10)
		s++;
		m=1;
		m*=10;
	k=0;
	z=0;
	for(int i=1;i<=s;i++){
		b[i]=i/m-k;
		k=b[i]*10;
		m/=10;
}
	v=b[0];
	int h;
	for(int i=2;i<=s;i++){
		if(b[i]>v)
		{
			h=v;
			v=b[i];
			b[i]=v;
		}
	}
	
	for(int i=1;i<=s;i++)
		cout<<b[i];
	return 0;
} 
