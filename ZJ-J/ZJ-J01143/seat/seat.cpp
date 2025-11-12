#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1],num=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			num=i;
			break;
		}
	}
	int op=1,p=0;
	for(int j=1;j<=m;j++){
		if(op==1){
			for(int i=1;i<=n;i++){
				p++;
				if(p==num){
					cout<<j<<' '<<i;
					return 0;
				}
			}
			op=2;
		}else{
			for(int i=n;i>=1;i--){
				p++;
				if(p==num){
					cout<<j<<' '<<i;
					return 0;
				}
			}
			op=1;
		}
	}
	return 0;
}
