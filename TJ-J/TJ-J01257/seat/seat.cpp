#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll n,m,b[15][15];
struct node{
	int z,r;
}a[105]; 
void px(int nm){
	for(int j = 1;j<nm;j++){
		for(int i = 1;i<=nm;i++){
			if(a[i].z < a[i+1].z){
				int t = a[i].z,x = a[i].r;
				a[i].z = a[i+1].z;
				a[i].r = a[i+1].r;
				a[i+1].z = t;
				a[i+1].r = x;
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm = n*m;
	for(int i = 1;i<=nm;i++){
		cin>>a[i].z;
	}
	a[1].r = 1;
	px(nm);
	int k = 1,t = 1;
	for(int i = 1;i<=m;i++){
		if(t){
			for(int j = 1;j<=n;j++){
				b[j][i] = a[k].z;
				if(a[k].r == 1){
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
			}
			t = 0; 
		}else{
			for(int j = n;j>=1;j--){
				b[j][i] = a[k].z;
				if(a[k].r == 1){
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
			}
			t = 1;
		}
		
	}
	return 0;
}
