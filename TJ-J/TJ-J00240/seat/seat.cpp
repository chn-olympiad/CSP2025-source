#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001];
int w;
int self;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	self=a[1];
	
	for (int i=1 ;i<=n*m+1;i++){
		int t=0;
		for(int j=1;j<=i;j++){
			if(a[j+1]>a[j]){
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==self){
			w=i;
		}
	}
	if(w>=m){
		int t=w%m;//yushu
		int temp=(w-t)/m;//zhengshu
		//beishu		
		if(t==0){
		
			if(temp%2==1){
				cout << temp  << " " << m;			
			}
			else{
				
				cout << temp << " " << 1 ;
				
			}
		}
		else{
			
			if(temp%2==1){
				cout << temp+1 << " " << m-t+1;
			}
			else{
				cout << temp+1 << " " << t;
			}
		}
	}
	else{
		cout << 1 << " " << w;
	}
	
		


	
	return 0;
}

