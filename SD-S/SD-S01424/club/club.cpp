#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a1[20005],a2[20005],a3[20005],cnt=0;
	cin>>t;
	for(int i=0;i<=t;i++){
		cin>>n;
		for(int j=0;j<=n;j++)
			cin>>a1[j]>>a2[j]>>a3[j];
	}
	int y=0;
	for(int z=0;z<=n;z++){
		for(int x=0;x<=10;x++){
			if(x>y)
				y=x;
		}
		cnt++;
	}
	if(cnt>n/2)
		return 0;
	else		
		cout<<cnt<<endl; 
	return 0;
} 
