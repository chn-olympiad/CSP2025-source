#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int cel(int x,int y){
	return (x+1)/y+1;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[m*n],v,x;
	for(int i = 0;i<n*m;i++){
		cin>>b[i];
		if(i == 0){
			v = b[i]; 
		}
	}
	sort(b+0,b+n*m+1,cmp);
	int i = 0;
	while(true){
		if(b[i] == v){
			x = i+1;
			break;
		}
		i++;
	}
	if(x/n%2==0) cout<<x/n+1<<" "<<x%n<<endl;
	else cout<<cel(x,n)-1<<" "<<n-x%n<<endl;
	return 0;
}
