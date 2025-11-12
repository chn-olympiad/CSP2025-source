#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s[121212],q,pro,dow=0;
	cin>>n>>m;
	q=n*m;
	for(int i=0;i<q;i++){
		cin>>s[i];
	}
	pro=s[0];
	sort(s,s+q);
	for(int i=q-1;i>-1;i--){
		if(s[i+1]==pro)
			dow=i;

	}
	
	if(dow>n){
		int z=dow%n+1,p=dow/n;
		if(z%2==0){
			cout<<z<<" "<<m-p;
		}
	}
	else{
		int y=dow%n;
		cout<<"1 "<<y+n;
	}

	return 0;
} 
