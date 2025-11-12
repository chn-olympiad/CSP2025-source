#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a,d,h;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>h;
		for(int y=1;y<=2;y++){
			cin>>d;
			if(h<d){
				h=d;
			}
			
		}
	}
	cout<<h;
	
} 
