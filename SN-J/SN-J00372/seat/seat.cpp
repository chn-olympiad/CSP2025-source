#include<bits/stdc++.h>
using namespace std;
long long m,n,num,b1;
int s[4001],sz[4001],a1;
int main(){	
//	freopen("number3.in","r",stdin);
//	freopen("number3.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<m*n;i++){
		cin>>s[i];
	}
	a1=s[0];
	for(int h=0;h<m*n;h++){
		int m=s[0];
		for(int j=0;j<m*n;j++){
			if(m<=s[j]){
				m=s[j];
				num=j;
			}		
		}
		sz[h]=m;
		s[num]=-1;
	}
	for(int i=0;i<m*n;i++){
		if(sz[i]==a1){
			b1=i+1;
		}
	}
	int c=b1%n;
	cout<<int(b1%m)<<" "<<c;
}
