#include<bits/stdc++.h>
using namespace std;
int n,m,s[1001],a,c;
bool cmp(int a,int b){
	return (a>b);
}int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	a=s[0];
	sort(s,s+n*m+1,cmp);
	int i=0;
	for(;i<n*m;i++){
		if(s[i]==a) break;
	}
	i++;
	c=i/n;
	//cout<<n<<' '<<i%n<<' '<<c<<' ';
	if(i%n){
		if(c%2){
			cout<<c+1<<' '<<n-i%n+1<<endl;
		}else{
			cout<<c+1<<' '<<i%n<<endl;
		}
	}else{
		if(!c%2){
			cout<<c<<' '<<1<<endl;
		}else{
			cout<<c<<' '<<n<<endl;
		}
	}
}
