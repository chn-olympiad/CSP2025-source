#include<bits/stdc++.h>
using namespace std;
int ao[37][37];
int bp[307];
int c[1007][1007];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int rc,r,sum=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>bp[i];
	}
	rc=bp[0];
	sort(bp,bp+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(rc==bp[i]){
			r=i+1;
			break;
		}
	}
int num=0;
	for(int i=1;i<=n;i++){

			for(int j=1;j<=m;j++){
				sum++;
			if(r==sum){
				cout<<j<<" "<<i;
				return 0;
			}
		}

			for(int j=m;j<=1;j--){
				sum++;
				if(r==sum){
				cout<<j<<" "<<i;
				return 0;
			}
			}

	}
	return 0;
}
