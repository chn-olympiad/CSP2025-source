#include<bits/stdc++.h>
using namespace std;
int c,r;
int n,m;
int s,w=1;
int a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>s)w++;
	}s=w/m;
	w=w%m;
	if(w!=0)s++;
	
	if(s%2==1){
		if(w==0)w=m;
		cout<<s<<" "<<w;
	}else{
		if(w==0)w=1;
		else w=m+1-w;
		cout<<s<<" "<<w;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
