#include<bits/stdc++.h>
using namespace std;
long long a,b,c[10001],d,p=1,w;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	long long e=a*b;
	for(int i=1;i<=e;i++)
	{
		cin>>c[i];
	}
	long long m=c[1];
	for(int i=1;i<=e;i++)
	{
		for(int j=1;j<=e;j++){
			if(c[j]<c[j+1])swap(c[j],c[j+1]);
		}
	}
	for(int i=1;i<=e;i++)
	{
		if(m==c[i]){
		d=i;
		break;
		}
	}
	if(d<=a){
		cout<<1<<' '<<d;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else{
		while(1)
		{
			if(d>a){
			
			d-=a;
			p++;
		}
		else break;
		}
		cout<<p<<' ';
		if(p%2==0){	
		w=a+1-d;
		cout<<w;}
		else
		cout<<d;
	}
		fclose(stdin);
		fclose(stdout);
	return 0;
} 
