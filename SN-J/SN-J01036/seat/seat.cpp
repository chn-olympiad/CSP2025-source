#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int s[102];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;int rn,rm;
	cin>>n>>m;
	int c=n*m;int t;
	for(int i=0;i<c;i++){
		cin>>s[i];
	}
	int r=s[0];
	for(int i=0;i<c;i++){
		for(int j=0;j<c;j++){
			if(s[j]>s[i]){
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
		}
	}
	for(int i=0;i<c;i++){
		if(s[i]==r) {
			r=c-i;
			break;
		}
	}

	if(r%n==0){
		rm=r/n;
	}else{
		rm=r/n+1;
	}
	
	if(rm%2==0){
		if(r%n==0){
			rn=1;
		}else{
			rn=n-(r%n)+1;
		}
	}else{
		if(r%n==0){
			rn=n;
		}else{
			rn=r%n;
		}
	}
	cout<<rm<<" "<<rn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
