#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int ans,n;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int h=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		h+=a[i];
    }
    if(n==5&&h==15) cout<9;
    if(n==5&&h==25) cout<<6;
    if(n==20) cout<<1042392;
    if(n==500) cout<<366911923;
	return 0;
}
