#include<iostream>
#include<algorithm>

using namespace std;


int fs[100000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,f,p;
	
	cin>>n>>m;
	p = n*m;
	for(int i = 1;i <= p;i++){
		cin>>fs[i];
	}
	f = fs[1];

	
	int k;
	sort(fs+1,fs+p+1);
	
	
	for(int i = 1;i<=p;i++){
		if(fs[i] == f){
			k = p-i+1;
			break;
		}
	
	}


	
	int l,h,a;
	if(k%n == 0){
		l = k/n;
		if(l%2 == 0){
			h = 1;
		}else{
			h = m;
		} 
	}else if(k%n == 1){
		l = k/n + 1;
		if(l%2 == 0){
			h = m;
		}else{
			h = 1;
		} 
	}else if(k%n > 1){
		l = k/n + 1;
		if(l%2 == 0){
			h = m - k%n +1;
		}else{
			h = l % n ;
			
		} 
	}
	cout<<l<<" "<<h;
	
	
	
	
	
	
	
	

	return 0;

} 
