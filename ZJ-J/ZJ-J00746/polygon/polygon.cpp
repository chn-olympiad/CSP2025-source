#include<iostream>
#include<vector>
using namespace std;
vector<int> a(5000);
int n;
long long maxnum=0;

void find(int l,int s,int c){
	int jl=l;
	int js=s;
	jl+=a[c];
	js++;
	if(c==n-1){
		if(jl>2*a[c]&&js>=3){
			maxnum++;
		}
		return;
	}
	if(js>=3){
		if(jl>2*a[c]){
			maxnum++;
		}
	}
	for(int i=c+1;i<n;i++){
		find(jl,js,i);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n+1;i++){
		for(int k=0;k<n-1;k++){
			if(a[k]>a[k+1]){
				int t=a[k];
				a[k]=a[k+1];
				a[k+1]=t;
			}
		}
	}
	for(int i=0;i<n;i++){
		find(0,0,i);
	}
	cout<<maxnum%998244353<<endl;
	return 0;
}

