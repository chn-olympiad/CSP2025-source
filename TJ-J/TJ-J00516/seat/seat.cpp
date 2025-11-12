#include<bits/stdc++.h>
using namespace std;

bool ___(int a,int b);

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c[11][11];
	int n,m;//nhangmlie
	cin>>n>>m;
	vector<int> vec(n*m+10);
	for(int i=1;i<=n*m;i++){
		cin>>vec[i];
	}
	int r=vec[1];
	int p;
	sort(vec.begin()+1,vec.begin()+n*m,___);
	for(int i=1;i<=n*m;i++){
		if(vec[i]==r){
			p=i;
			break;
		}
	}
	int l=(p-1)/n+1;
	if(l%2==1) cout<<l<<" "<<(p-1)%n+1;
	if(l%2==0) cout<<l<<" "<<n-(p-1)%n;
	return 0;
} 

bool ___(int a,int b){
	return a>b;
}
