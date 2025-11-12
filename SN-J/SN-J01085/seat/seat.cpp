//SN-J01085  闫卜予  西安高新一中沣东中学初中校区 

#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[114];
int n,m,r;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)r=a[i];
	}
	sort(a+1,a+m*n+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				cnt++;
				if(a[cnt]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				cnt++;
				if(a[cnt]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
