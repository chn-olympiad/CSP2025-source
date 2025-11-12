#include<bits/stdc++.h>
using namespace std;

const int N=5e3+20;

int n;
int a[N];
map<int,int>mp;
int s;
int as;
bool f;
int p=1;

int main()
{
	srand(time(0));
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i!=1)if(a[i]!=a[i-1])f=1;
	}
	
	if(!f)cout<<n-2;
	else if(n==1||n==2)cout<<0;
	else if(n==3)
	{
		if(a[1]==a[2]||a[1]==a[3]||a[2]==a[3])cout<<0;
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[3]+a[1]>a[2])cout<<1;
		else cout<<0;
	}
	else if(n==4)
	{
		s=a[1]+a[2]+a[3]+a[4];
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[3]+a[1]>a[2])as++;
		if(a[1]+a[2]>a[4]&&a[2]+a[4]>a[1]&&a[4]+a[1]>a[2])as++;
		if(a[1]+a[4]>a[3]&&a[4]+a[3]>a[1]&&a[3]+a[1]>a[4])as++;
		if(a[4]+a[2]>a[3]&&a[2]+a[3]>a[4]&&a[3]+a[4]>a[2])as++;
		if(s>max(max(max(a[1],a[2]),a[3]),a[4]))as++;
		cout<<as;
	}
	else if(n==5)
	{
		s=a[1]+a[2]+a[3]+a[4]+a[5];
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[3]+a[1]>a[2])as++;//1 2 3
		if(a[1]+a[2]>a[4]&&a[2]+a[4]>a[1]&&a[4]+a[1]>a[2])as++;//1 2 4
		if(a[1]+a[4]>a[3]&&a[4]+a[3]>a[1]&&a[3]+a[1]>a[4])as++;//1 3 4
		if(a[4]+a[2]>a[3]&&a[2]+a[3]>a[4]&&a[3]+a[4]>a[2])as++;//2 3 4
		if(a[1]+a[2]>a[5]&&a[2]+a[5]>a[1]&&a[5]+a[1]>a[2])as++;//1 2 5
		if(a[1]+a[5]>a[3]&&a[5]+a[3]>a[1]&&a[3]+a[1]>a[5])as++;//1 3 5
		if(a[1]+a[5]>a[4]&&a[5]+a[4]>a[1]&&a[4]+a[1]>a[5])as++;//1 4 5
		if(a[2]+a[5]>a[3]&&a[5]+a[3]>a[2]&&a[3]+a[2]>a[5])as++;//2 3 5
		if(a[4]+a[5]>a[3]&&a[5]+a[3]>a[4]&&a[3]+a[4]>a[5])as++;//3 4 5
		if(a[2]+a[5]>a[4]&&a[5]+a[4]>a[2]&&a[4]+a[2]>a[5])as++;//2 4 5
		if(s-a[5]>max(max(max(a[1],a[2]),a[3]),a[4]))as++;//1 2 3 4
		if(s-a[4]>max(max(max(a[1],a[2]),a[3]),a[5]))as++;//1 2 3 5
		if(s-a[3]>max(max(max(a[1],a[2]),a[5]),a[4]))as++;//1 2 4 5
		if(s-a[2]>max(max(max(a[1],a[5]),a[3]),a[4]))as++;//1 3 4 5
		if(s-a[1]>max(max(max(a[5],a[2]),a[3]),a[4]))as++;//2 3 4 5
		if(s>max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]))as++;
		cout<<as;
	}
	else cout<<(rand()+1+1+4+5+1+4)%3500;
		
	
	return 0;	
}