#include<bits/stdc++.h>
using namespace std;
#define FI(x) freopen(x".in","r",stdin);
#define FO(x) freopen(x".out","w",stdout);
int n,m,w,x,y;
vector<int> a; 
int main(){
	FI("seat");
	FO("seat");
	cin>>n>>m;
	for(int i=1,j;i<=n*m;i++){
		cin>>j;
		if(i==1){
			w=j;
		}
		a.push_back(j*-1);
	}
	sort(a.begin(),a.end());
//	for(int i=0;i<n*m;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<"\n";
	int k=0;
	while((a[k]*-1)!=w){
		k++;
	}
	k+=1;
//	cout<<k<<"\n";
	if((int)(k/n)==(k*1.0)/(n*1.0)){
		x=k/n;
	}else{
		x=k/n;
		x++;
	}
	if(x%2==1){
		if(k%n!=0){
			y=k%n;
		}else{
			y=n;
		}
	}else{
		if(k%n!=0){
			y=n-(k%n)+1;
		}else{
			y=1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
