#include<bits/stdc++.h>
using namespace std;
long long a[100000]={0},n,m,e=0;
long long b[10000][10000];
void qsort(int x){
	for(int i=0;i<x;i++){
		for(int j=0;j<x-i;j++){
			if(a[j]<a[j+1])
				swap(a[j],a[j+1]);
		}
	}
	for(int i=0;i<x;i++){
		cout<<a[i]<<"  ";
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n*m;i++){
		cin>>a[i];
	}
	e=a[0];
	qsort(n*m);
	for(long long i=0;i<n;i++){
		long long l=0;
		for(long long j=0;j<m;j++){
				b[i][j]=a[l];
				l++;
		}
		for(long long j=m;j>=0;j--){
				b[i+1][j]=a[l];
				l++;
		}
		

	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<m;j++){
				cout<<b[i][j]<<";";
		}
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<m;j++){
				if(b[i][j]==e){
					cout<<i+1<<" "<<j+1<<endl;
					break;
				}
		}
	}
	return 0;
}

