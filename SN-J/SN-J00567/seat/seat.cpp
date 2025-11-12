/*李牧泽 SN-J00567 西安滨河学校*/
#include<bits/stdc++.h>
using namespace std;
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	FI("seat");
	FO("seat");
	int n,m,c=1,r=1,x=0;
	cin>>n>>m;
	for (int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int R=a[0],iR;
	sort(a,a+n*m,cmp);
	for (int i=0;i<n*m;i++){
		if (a[i]==R){
			iR=i;
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=0;j<n;j++){
			if (x==iR){
				cout<<c<<' '<<r;
				return 0;
			}
			if ((i%2)==1){
				if (j!=n-1) r+=1;
			}
			else{
				if (j!=n-1) r-=1;
			}
			x++;
		}
		c++;
	}
} 
