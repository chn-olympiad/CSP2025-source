#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],cnt=0;cin>>n>>m;
	for(int i=0;i<n*m;i++){cin>>a[i];}
	for(int i=1;i<n*m;i++){
		if(a[i]>a[0])cnt++;
	}int i=1,j=1,flg=1;
	while(cnt>0){cnt--;
		if(i==n&&flg==1){
			j++;flg=-1;
			continue;
		}if(i==1&&flg==-1){
			j++;flg=1;
			continue;
		}i+=flg;
	}cout<<j<<' '<<i;
	return 0;
}
