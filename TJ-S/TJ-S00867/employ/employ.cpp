#include<bits/stdc++.h>
using namespace std;
//struct w{
//	long long x,y,z,b;
//}a[1000005];
long long a,b[1000005],c[1000005],d[1000005],t,n,m,k,x,y,z,q,ma,ma1,ma2,ma3,num,b_1,c_1,d_1,f1,f2,f3,u,v,w;
string s,s_1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) cin>>b[i];
	if(m==1){
		for(int i=0;i<n;i++){
			if(b[i]==1) x++;
		}
		cout<<x;
	}
	else{
		a=1;
	t=1;
	for(int i=1;i<=n;i++){
		a*=i;
	}
	for(int i=1;i<=m;i++){
		t*=i;
	}
	cout<<a/t;
	}
	
	return 0;
}
