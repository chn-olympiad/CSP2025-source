#include<bits/stdc++.h>
using namespace std;
int n,m,b[114],t;
int a[20][20];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		cin>>b[++t];
	}
	int xa=b[1];
	sort(b+1,b+1+t,cmp);
	int ok=1,okk=1,okkk=1;
	for(int i=1,j=1,k=1;k<=n*m;k++){
		a[i][j]=b[k];
		if(i==n and okkk){
			ok=0;
			okk=0;
			j++;
			okkk=0;
			continue;
		}
		if(i==1 and !okk){
			ok=1;
			j++;
			okk=1;
			okkk=1;
			continue;
		}
		if(ok) i++;
		else i--;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==xa){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
