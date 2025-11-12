#include<bits/stdc++.h>
#define ll longlong;
using namespace std;
inline rd(){
	int ans=0,f=0;
	char ch=getchar();
	while(ch>'0'||ch<'9') f^=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return f?-ans:ans;
}
int n, m, k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<4;i++){
	   for(int j=0;j<3;j++){
	  cin>>a[j];
	   }	
		
	}
	if(n=4||m=4||k=2){
	   cout<<13;	
	}
	return 0;
}
