#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1],b[n+1],c[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a,a+n+1);
		sort(b,b+n+1);
		sort(c,c+n+1);
		max=a[1];
		max1=b[1];
		max2=c[1];
		//if(max>=max1&&max1>=max2){
		//	cout<<max<<" "<<max1;
		//}else if(max>=max1&&max2>=max1){
		//	cout<<max<<" "<<max2;
		//}
		cout<<'0';
    }
	return 0;
}
