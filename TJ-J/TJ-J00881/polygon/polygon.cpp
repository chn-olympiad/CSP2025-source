#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b,c[100010],chang,d[10010],cnt=0,cntr=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int i=1;i<=a;i++){
		
		for(int j=i;j<=a-1;j++){
			d[j]=c[j];
			cntr=cntr+c[j];
		
		sort(d,d+i);
		if(d[i]*2<cntr){
			cnt++;
		}
	}
	}
	cout<<cnt;
}
