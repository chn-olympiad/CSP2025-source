#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in",'r',stdin);
	freopen("polygon.out",'w',stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	int ans=0;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			for(int z=0;z<n;z++){
				if(a[x]!=a[y] && a[y]!=a[z] && a[x]!=a[z]){
					if(x+y>z && x+z>y && z+y>x){
						ans+=1;
					}
				}
			}
		}
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			for(int z=0;z<n;z++){
				for(int i=0;i<n;i++){
					if(x+y>z && x+y>i && x+z>y && x+z>i && z+y>x && z+y>i){
						ans+=1;
					}
				}
			}
		}
	}
	cout<<ans+1<<endl;
	return 0;
}
