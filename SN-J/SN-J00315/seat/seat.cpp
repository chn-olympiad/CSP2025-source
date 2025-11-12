#include<bits/stdc++.h>
using namespace std;
int opp=1,n,m,a[10005];
bool tmp(int a,int b) {
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int u=n*m;
	while(opp--){
		for(int i=0;i<u;i++)
		{
			cin>>a[i];
		}
		int y=a[0];//cout<<y<<endl;
		
		sort(a,a+u,tmp);
//		for(int i=0;i<u;i++)
//		{
//			cout<<a[i];
//		}
		int r;
		for(int i=0;i<u;i++)
		{
			if(a[i]==y){
				r=i+1;
				break;
			}
		}//cout<<r<<endl;
		int h;
		if(r%m!=0) h=r/m+1;
		else h=r/m;
		r=r%m;
		if (r==0)r=m;
		if(h%2==0)cout<<h<<" "<<n-r+1;
		else cout<<h<<" "<<r;
	}
	return 0;
}
