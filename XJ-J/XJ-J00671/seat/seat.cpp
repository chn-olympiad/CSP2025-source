#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int si=n*m;
	vector<int> a;
	int a1;
	for(int i=0,j;i<si;i++){
		cin>>j;
		a.push_back(j);
		if(i==0){
			a1=j;
		}
	}
	sort(a.rbegin(),a.rend());
	for(int i=0;i<si;i++){
		if(a[i]==a1){
			a1=i+1;
			break;
		}
	}
	int x=a1%n;
	int y=a1/n;
	if(x>0) y++;
	if(x==0) x=n;
	if(y%2==0) x=n-x+1;
	cout<<y<<" "<<x;
	return 0;
} 
