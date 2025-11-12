#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1],cnt=n*m;
	sort(a+1,a+1+cnt,cmp);
	int c=0;
	for(int i=1;i<=cnt;i++){
		if(a[i]==num){
			c=i;
			break;
		}
	}
	int nw=0;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				++nw;
				if(nw==c){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				++nw;
				if(nw==c){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
