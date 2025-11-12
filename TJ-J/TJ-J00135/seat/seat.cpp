#include<bits/stdc++.h>
using namespace std;
int s[102];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int hang,lie,m;
	cin>>hang>>lie;
	int a=0;
	for(;a<hang*lie;a++){
		cin>>s[a];
	}
	int r=s[0];
	for(int b=0;b<hang*lie;b++){
		for(a=0;a<hang*lie;a++){
			if(s[a]<s[a+1]){
				m=s[a];
				s[a]=s[a+1];
				s[a+1]=m;
			}
		}
	}
	for(a=0;a<hang*lie;a++){
		if(s[a]==r)
			r=a+1;
	}
	if(r%lie==0){
		if(r%hang==0){
			if((r/lie)%2==1)
				cout<<lie-r/lie<<" "<<r/hang;
			else
				cout<<r/lie<<" "<<r/hang;
		}
		else{
			if((r/lie)%2==1)
				cout<<lie-r/lie<<" "<<r/hang+1;
			else
				cout<<r/lie<<" "<<r/hang+1;
		}
	}
	else{
		if(r%hang==0){
			if((r/lie)%2==1)
				cout<<1+lie-r/lie<<" "<<r/hang;
			else
				cout<<r/lie+1<<" "<<r/hang;
		}else{
			if((r/lie)%2==1)
				cout<<1+lie-r/lie<<" "<<r/hang+1;
			else
				cout<<r/lie+1<<" "<<r/hang+1;
		}
	}
	return 0;
}
