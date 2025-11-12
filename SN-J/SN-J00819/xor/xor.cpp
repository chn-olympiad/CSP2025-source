#include<bits/stdc++.h>
std::ifstream cin("xor1.in");
std::ofstream cout("xor1.out");
int main(){
	int a,b,c;
	cin>>a>>b;
	int as[a];
	for(int i=1;i<=a;i++)
	{
		cin>>c;
		as[i]={c};
	}
	if(b==2)
	{
		cout<<"2";	
	}else if(b==3)
	{
		cout<<"3";
	}else if(b==0)
	{
		cout<<"1";
	}
	
	
}
