#include<bits/stdc++.h>
using namespace std;
int l[105]={};
int l1[15][15]={};
int l2[15][15]={};
int l3[105]={};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>l[i];
	}
	int a=l[0];
	sort(l,l+n*m,cmp);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			l1[i][j]=l[i*n+j];
		}
		if(i%2==1){
			reverse(l1[i],l1[i]+n);
		}
	}
	int k=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			l3[k]=l1[i][j];
			k++;
		}
	}
	k=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			l2[j][i]=l3[k];
			k++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(l2[i][j]==a){
				cout<<j+1<<' '<<i+1;
				return 0;
			}
		}
	}
	return 0;
}
