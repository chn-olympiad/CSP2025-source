#include<bits/stdc++.h>
using namespace std;
bool com1(vector<int> a,vector<int> b){
	return a[0]>b[0];
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	vector<vector<int> > a(n*m,vector<int>(2));
	for(int i=0;i<n*m;i++){
		cin>>a[i][0];
		a[i][1]=i;
	}
	int index;
	sort(a.begin(),a.end(),com1);
	for(int i=0;i<n*m;i++){
		if(a[i][1]==0){
			index=i;
			break;
		}
	}
	int r=index/n;
	r++;
	index++;
	index%=n;
	if(index==0){
		index=n;
	}
	int c;
	if(r%2==0){
		c=n+1-index;
	}else{
		c=index;
	}
	cout<<r<<" "<<c;
	return 0;
}
