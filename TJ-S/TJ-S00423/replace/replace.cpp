#include <bits/stdc++.h> 
using namespace std;
const int N=2e5+19;
struct chan{
	string a,b;
	string as,bs;
	string ass,bss;
};
chan x[N],y[N];
int main(){
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b;
		bool d=false;
		for(int j=0;j<x[i].a.size();j++){
			if(x[i].a[j]!=x[i].b[j] || d){
				d=true;
				x[i].as+=x[i].a[j];
				x[i].bs+=x[i].b[j];
			}
		}d=false;
		for(int j=x[i].as.size()-1;j>=0;j--){
			if(x[i].as[j]!=x[i].bs[j] || d){
				d=true;
				x[i].ass+=x[i].as[j];
				x[i].bss+=x[i].bs[j];
			}
		}
		reverse(x[i].ass.begin(),x[i].ass.end());
		reverse(x[i].bss.begin(),x[i].bss.end());
		
		
		cout<<x[i].ass<<"  "<<x[i].bss<<endl;
	}
	
	
	for(int i=1;i<=q;i++){
		cin>>y[i].a>>y[i].b;
		bool d=false;
		for(int j=0;j<y[i].a.size();j++){
			if(y[i].a[j]!=y[i].b[j] || d){
				d=true;
				y[i].as+=y[i].a[j];
				y[i].bs+=y[i].b[j];
			}
		}d=false;
		for(int j=y[i].as.size()-1;j>=0;j--){
			if(y[i].as[j]!=y[i].bs[j] || d){
				d=true;
				y[i].ass+=y[i].as[j];
				y[i].bss+=y[i].bs[j];
			}
		}
		reverse(y[i].ass.begin(),y[i].ass.end());
		reverse(y[i].bss.begin(),y[i].bss.end());
		
		cout<<y[i].ass<<"  "<<y[i].bss<<endl;
	}
}
