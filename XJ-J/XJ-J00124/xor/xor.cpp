#include<iostream>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i,s=0,s1=0;
	int a[500010];
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k=1){
		for(i=1;i<=n;i++){
			if(a[i]==1){
				s++;
			}
		}
	}else if(k=0){
		for(i=1;i<=n;i++){
			if(a[i]==0){
				s++;
			}
			if(a[i]==1&&a[i+1]==1){
				s1++;
			}
			s=s+s1/2;
		}
	}
	cout<<s;
	return 0;
} 
