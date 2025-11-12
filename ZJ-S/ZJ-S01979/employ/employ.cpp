#include<bits/stdc++.h>
using namespace std;
int n,m;
int const N=1e2+5;
bool nan[N];
int a[N];
int Z=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	int l0=0;
	ke[0]=1;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1'){
			nan[i]=1;
			ke[i]=ke[i-1];
			Z++;
		}
		else{
			nan[i]=0;
			ke[i]=ke[i-1]+1;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",a[i]);
	}if(Z<=18){
		if(m>18)
			cout<<0;
	}
	for(int i=1;i<=n;i++){
		
	}
	return 0; 
} 
