#include<bits/stdc++.h>
using namespace std;
int n = 0;
int a[5010];
int num = 0;
int numm = 0;
int nummm = 0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> a[n];	
	}
	
	if(n<=3){
		for(int x = 1;x<=n;x++){
			for(int y = x+1;y<=n;y++){
				for(int z = y+1;z<=n;z++){
					if((x+y+z)>2*max(x,max(y,z))){
						num= num + 1;
					}
				}
			}
		}
		cout<<num;
	}
	
	

	return 0;
}
