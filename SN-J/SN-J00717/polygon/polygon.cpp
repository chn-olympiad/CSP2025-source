#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010],zong=0;
	cin>>n;
	long long length=0;
	long long count=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=(n-2);i++){
		for(int j=3;j<=(n+1-i);j++){
			for(int k=1;k<=(n-(j-1));k++){
				int shizi=j-(k-1);
				if(shizi<=0)   count+=0;
				else     count+=shizi;
			}
			for(int k=1;k<=count;k++){
				length+=a[i];
				int in_c=j;
				int in_c1=1;
				int in_c2=n-j-in_c1;
				for(int p=in_c;p>=1;p--){
					length+=(a[in_c1+i]+a[in_c2+i]);
				}
				if(length>(2*a[in_c2+i])){
					zong++;
					length=0;
				}
				else      length=0;
			}
			
		}
	}
	cout<<zong%998%244%353;
	return 0;
} 
