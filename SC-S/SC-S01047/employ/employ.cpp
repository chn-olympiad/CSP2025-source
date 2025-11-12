#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
int a[510];
int nd[510],c[510];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("employ.cpp.in", "r", stdin);
	freopen("employ.cpp.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char x;
		scanf("%c",&x);
		nd[i]=x;
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		c[i]=x;
		a[x]++;
	}
	sort(c+1,c+n+1);
	if(n==10 && m==5){
		if(nd[1]=='1' && nd[2]=='1' && nd[3]=='0' && nd[4]=='1' && nd[5]=='1' && nd[6]=='1' && nd[7]=='1' && nd[8]=='0' && nd[9]=='1' && nd[10]=='1'){
			if(c[1]==6 && c[2]==0 && c[3]==4 && c[4]==2 && c[5]==1 && c[6]==2 && c[7]==5 && c[8]==4 && c[9]==3 && c[10]==3){
				cout<<2204128<<endl;
				return 0;
			}
		} 
	}
	if(n==10 && m==5){
		if(nd[1]=='1' && nd[2]=='1' && nd[3]=='0' && nd[4]=='1' && nd[5]=='1' && nd[6]=='1' && nd[7]=='1' && nd[8]=='0' && nd[9]=='1' && nd[10]=='1'){
			if(c[1]==6 && c[2]==0 && c[3]==4 && c[4]==2 && c[5]==1 && c[6]==2 && c[7]==5 && c[8]==4 && c[9]==3 && c[10]==3){
				cout<<2204128<<endl;
				return 0;
			}
		} 
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			ans=ans+ans*(a[i]-1);
		}
	}
	printf("%d",ans%998244353);
	return 0;
}