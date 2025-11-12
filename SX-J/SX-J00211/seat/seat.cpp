#include<bits/stdc++.h>
using namespace std;
long long l,n,m,k,x[1000],a[100][100],i=1,j=1,o=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int p=1;p<=l;p++){
		cin>>x[p];
	}
	k=x[1];
	sort(x+1,x+1+l,cmp);
	while(l--){
			a[i][j]=x[o];
			if(j%2!=0){
				if(i<n)
					i++;
				else
					j++;
			}
			else{
				if(i>1)
					i--;
				else
					j++;
			}
			o++;
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==k)
				cout<<i<<" "<<j;
		}
	}
	return 0;
}