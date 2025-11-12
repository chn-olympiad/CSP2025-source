#include<bits/stdc++.h>
using namespace std;
int a[500010],s[1048580];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i=1;i<=1048576;i++){
		s[i]=-2;
	}
	int m,k,z=-1,sum=0;
	cin>>m>>k;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		a[i]=(a[i-1]^x);
		if(s[(a[i]^k)]>=z){
			sum++;
			z=i;
		}
		s[a[i]]=i;
	}
	cout<<sum;
}
