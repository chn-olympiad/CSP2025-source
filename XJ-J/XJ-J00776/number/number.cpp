#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s;
	cin>>s;
	int a,b,c,d;
	c=s;
	if(s/10==0){
		cout<<s;
	}
	if(s/10!=0)
	{
		if(s/100!=0)
		{
			a=s/100;
			b=c/10%10;
			d=s%100%10;
			if(b>a)
				if(b<d)
					cout<<d*100+b*10+a;	
				else if(a<d)
					cout<<b*100+d*10+a;	
			else
				cout<<c;
			if(b<a)
				if(b<d)
					cout<<a*100+d*10+b;	
				else if(b>d)
					cout<<a*100+b*10+d;	
		}
		else{
			a=s/10;
			b=c%10;
			if(a+(10*b)>c){
				cout<<a+(b*10);
			}
			else{
				cout<<c;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
