#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n*m);
	for(int i=0;i<(n*m);i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<(n*m);i++){
		if(a[i]>a[0]){
			cnt++;
		}
	}
	if((int)(cnt/n)%2==0){
		cout<<(int)(cnt/n)+1<<" "<<(cnt%n)+1<<endl;
	}else{
		cout<<(int)(cnt/n)+1<<" "<<(n-(cnt%n))<<endl;
	}
	return 0;
}
