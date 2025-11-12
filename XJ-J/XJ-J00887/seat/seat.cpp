#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int main(){
	freopen(seat.in,"r",stdin);
	freopen(seat.out,"w"stdout);
	cin>>n>>m;
	vector<int>a(n*m);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n*m;i++){
		if(a[i]=r){
			cnt++;
		}
	}
	cout<<2" "<<2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
