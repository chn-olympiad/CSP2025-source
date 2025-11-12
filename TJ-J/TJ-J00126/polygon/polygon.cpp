#include <bits/stdc++.h>
using namespace std;
int a,y;
int x[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for (int i=1;i<=a;i++){
		cin>>x[i];
	}
	for (int i=0;i<=a;i++){
		for (int j=0;j<=a;j++){
			for (int b=0;b<=a;b++){
				if(x[i]+x[j]+x[b]>2*(max(x[i],x[j],x[b]))){
					y++;
				}
			}
		}
	}
	return 0;
}

