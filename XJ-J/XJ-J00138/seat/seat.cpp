#include<bits/stdc++.h>
using namespace std;
int b[400];
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	//freopen("seat2.in","r",stdin);
	//freopen("seat2.ans","w",stdout);
	int n,m;
	int xr;
	cin>>n>>m;
	int z=1;
	for(int i=1;i<=n*m;i++){
		if(i==1){
			cin>>xr;
			b[z]=xr;
			z++;
		}else{
			cin>>b[i];
			z++;
		}
			
		
	}
	sort(b+1,b+1+z);
	for(int i=1;i<=z;i++){
		if(xr==b[i]){
			xr=i;
			break;
		}
	}
	if((xr/m)%2==0){
		cout<<xr/m-1<<" ";
		cout<<m-(xr%n+1)+1;
	}else{
		cout<<xr/m+1<<" ";
		cout<<xr%n+1;
	}
	return 0;
}
/*
2 2
100
99
98
97

2 2
99 100 97 98
1 2

3 3
94 95 96 97 98 99 100 93 92
3 1

2 2
98 99 100 97
2 2
*/
