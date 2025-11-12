#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>s;
	int R=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)R=a[1];
		s.push_back(a[i]);
	}
	sort(s.begin(),s.end(),[](int a,int b){
		return a>b;
	});
	int r;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]==R){
			r=i+1;
			break;
		}
	}
	int ansm=(r+(n-1))/n;
	int ansn;
	if(r%n==0){
		ansn=n;
	}
	else{
		ansn=r%n;
	}
	if(ansm%2==0){
		ansn=n-ansn+1;
	}
	cout<<ansm<<' '<<ansn;
	return 0;
}