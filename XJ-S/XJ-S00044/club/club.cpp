#include<bits/stdc++.h>
using namespace std;
struct{
	int a1,a2,a3;
}a[100050];
int cmp(int a,int b){
	if(a.a1>b.a1 && a.a2<=b.a2 && a.a3<=b.a3){
		return a.a1>b.a1;
	}
	else if(a.a1>a.a2 && a.a1>a.a3){
		return a.a1>a.a2;
	}
	
}
int t,n,s1,s2,s3,num=0;
int main()
{
	//freopen("club.in","w",stdin);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a.a1>>a.a2>>a.a3;
		}
		sort(a+1,a+1+n,cmp);
		
	}
	
	
	//freopen("club.out","r",stdout);
	return 0;
}
