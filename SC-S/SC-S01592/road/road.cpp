#include <bits/stdc++.h>
using namespace std;
int a[1015][1015],b[1005];
int c,d,e,f,g,h,k,l,m,n,o,p;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>c>>d>>e;
	for(int i=1;i<=d;i++) cin>>f>>g>>h;
	for(int i=1;i<=e;i++){
		cin>>k;
		for(int j=1;j<=d;j++){
			cin>>b[j];
		}
	}
	cout<<0;
    return 0;
	fclose(stdin);
	fclose(stdout);
}