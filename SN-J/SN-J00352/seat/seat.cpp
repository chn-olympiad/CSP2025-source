//SN-J00352张晟轩渭南初级中学 
#include<bits\stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;

int n,m,grade[105];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>grade[i];
	}
	int r=grade[1],place;
	sort(grade+1,grade+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(grade[i]==r){
			place=i;
			break;
		}
	}
	int y,x;
	y=place/n;
	x=place%n;
    if(y%2==0){
    	if(x==0){
		    cout<<y<<" "<<1;
		    return 0;
	    }
		cout<<y+1<<" "<<x;
		return 0;	
	}if(y%2==1){
    	if(x==0){
		    cout<<y<<" "<<n;
		    return 0;
	    }
	    cout<<y+1<<" "<<n-x+1;
		return 0;
	}
	return 0;
}
