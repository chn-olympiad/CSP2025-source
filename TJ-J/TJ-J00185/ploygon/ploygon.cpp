#include<iostream>
#include<cstring>
using namespace std;
char a[1000000],d[1000000];
int main(){
	int n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int s;
	for(int i=0;i<n;i++){
		if(a[i]<a[i+1]){
			s=a[i];
			a[i]=a[i+1];
			a[i+1]=s;
		}
		else if(a[i]>=a[i+1]){
			continue;
		}
	}
	int w;
	for(int i=0;i<n;i++){
		w=w+a[i];
		if(w>2*a[1]&&n>=3){
			
		}
	}
	
	
	cout<<
	return 0;
}
