#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	short a[n*m];
	for(int i = 0;i <n*m;i++){
		cin>>a[i];
	}
	const int R = a[0];
	sort(a,(a+(n*m)));
	short b[n*m];
	for(int i = n*m-1;i >=0;i--){
		b[i] = a[i];
		//cout<<b[i];
	}
	short idx=0;
	for(int i = 0;i < m;i+=2){
		for(int j = 0;j < n;j++){
			if(b[idx] ==R){
				cout<<i+2<<" "<<j+1;
				return 0;
			}
			//cout<<i<<" "<<j<<" "<<b[idx];
			idx++;
		}
		//cout<<endl;
		for(int j = n-1;j >=0;j--){
			if(b[idx] ==R){
				cout<<i+1<<" "<<j+1;
				return 0;
			}
			//cout<<b[idx];
			idx++;
		}
	}
	//¿ÉËãÐ´ÍêÁË 
	return 0;
}
