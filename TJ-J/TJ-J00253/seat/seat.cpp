#include <bits/stdc++.h>
#include <cstdio>
#define int long long
using namespace std;

int n=0;
int m=0;
int num=0;

int value[1000];
int Rvalue=0;

int sortn(int a,int b){
	return a>b;
}

signed main(){
	
	//sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	freopen("seat1.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;

	num=n*m;
	
	for(int i=0;i<num;i++){
		
		cin>>value[i];
		
	}
	Rvalue=value[0];
	
	sort(value,value+num,sortn);
   
    int v=0;
    int s=0;
    for(int i=0;i<m;i++){
    	
    	if(s==0){	
	    	for(int j=s;j<n;j++){
	    		if(value[v]==Rvalue){
	    			cout<<i+1<<" "<<j+1;
				}
	    		v++;
	    		
	    		s=j;
			}
		}else{
		
			for(int j=s;j>=0;j--){
	    		if(value[v]==Rvalue){
	    			cout<<i+1<<" "<<j+1;
				}
	    		v++;
	    		
	    		s=j;
			}
		}

	}
		

	return 0;
	
}
