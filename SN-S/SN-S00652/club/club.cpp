#include<bits/stdc++.h>
using namespace std;
int t, n, o1, o2, o, b=0, end[111111]; 
int a[111111][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		//–¥»Î 
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			}
			
		}
		
		//≈≈–Ú
		for(int k=1;k<=n;k++){
			o1 = max(a[k][1], a[k][2]);
			o2 = max(a[k][2], a[k][3]);
			o = max(o1, o2);
			b += o;
		}
		end[i] = b;
		
	}
	
	for(int i=1;i<=t;i++){
		cout<<end[i]<<endl;
	}
	
	return 0;
}
