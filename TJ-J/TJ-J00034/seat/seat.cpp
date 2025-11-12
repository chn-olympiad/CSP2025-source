#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int o[101];
	int fin;
	for(int i = 1;i <=n*m;i++){
		cin>>o[i];
	}
	fin=o[1];
	//cout<<fin<<endl;
	sort(o+1,o+1+n*m);
	/*for(int i = 1;i <=n*m;i++){
		cout<<o[i];
	}*/
	int l=1,r=n*m;
	while(l<=r){
		int mid = (l+r)>>1;
		//cout<<l<<r<<mid<<endl;
		//cout<<o[mid]<<fin<<endl;
		if(o[mid]>fin){
			r=mid-1;
			//cout<<mid<<endl;
		}
		else if(o[mid]==fin){
			l=mid;
			//cout<<"we"<<endl;
			break;
		}
		else{
			l=mid+1;
		}
		//cout<<l<<r<<mid<<endl;
	}
	l = n*m+1-l;
	//cout<<l<<endl;
	int y = ((l-1)/n+1);
	int u = ((l-1)%n)+1;
	if(y%2==0) u = n+1-u;
	cout<<y<<" "<<u<<endl;
	return 0;
}
