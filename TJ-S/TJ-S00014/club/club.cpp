#include<bits/stdc++.h>
using namespace std;
long long l,t,o,s,n;
const int N=100005;
long long a[N][8];
long long m[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int w;
		cin>>s;
		n=s;
		int b=-1300;
		for(int j=1;j<=n;j++){
			cin>>a[i][1];
			cin>>a[i][2];
			cin>>a[i][3];
			if(a[i][1]>=b){
				b=a[i][1];
				w=1;
			}
			else if(a[i][2]>=b){
				b=a[i][2];
				w=2;
			}
			else{
				b=a[i][3];
				w=3;
			}
			m[i]=a[j][3];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<m[i];
	}	
	return 0;
} 
