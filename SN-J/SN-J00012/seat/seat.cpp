#include<iostream> 
#include<cmath>
#include<string> 
int aaa[10000];
int bbb[10000];
using namespace std;
int main (){
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	int c,d,e,f,g,m,n,r;
	cin>>n>>m;
	for (int i = 0;i<n*m;i++){
		cin>>g;
		aaa[i] = g;
	}
	c = 0;
	r = 0;
	
	
	
	
	
	
	
	
	g = aaa[0];
	for (int i = 0;i<n*m;i++){
		d = aaa[0];
		
		for (int j = 0;j<n*m-1;j++){
			d = max(d,aaa[j+1]);
			
		}
		bbb[i] = d;
		for (int j = 0;j<n*m;j++){
			if (aaa[j] == bbb[i]){
				aaa[j] = 0;
			}
		}
	}
	for (int i = 0;i<n*m;i++){
		
		if (bbb[i] == g){
			d = i+1;
		}
	}
	
	if(d%n == 0){
		c = d/n;
	}
	else{
		c = d/n+1;
	}
	
	f = d%n;
	
	if (c%2 == 0){
		if (f == 0){
			r = 1;
		}
		else{
			r = n-f+1;
		}
	}
	else{
		if (f == 0){
			r = m;
		}
		else{
			r = f;
		}
	}
	
	cout<<c<<" "<<r;
	return 0;
}
