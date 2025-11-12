#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
int t,n;
struct my{
	int a1,a2,a3;
}a[MAXN];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int mx1=-1,mx2=-1,mx3=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			mx1=max(mx1,a[i].a1);
			mx2=max(mx2,a[i].a2);
			mx3=max(mx3,a[i].a3);
		}
		cout<<mx1+mx2+mx3<<endl;
	}
	return 0;
}
