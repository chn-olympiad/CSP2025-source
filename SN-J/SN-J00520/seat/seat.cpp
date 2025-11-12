#include <bits/stdc++.h>
freopen(number.in,'r',strin);
freopen(number.out,'w',strout);
int main{
	int a,s;
	cin>>a>>s;
	string z[a*s];
	for(int i=0;i<=z.size()-1;i++){
		cin>>z[i];
	}
	string m[1];
	m[0]=z[0]
	string n[1];
	for(int i=0;i<=z.size()-1;i++){
		if(z[i]+'48'<z[i-1]+'48'){
			n[1]=z[i];
			z[i]=z[i-1];
			z[i-1]=n[1];
		}
	}
	int p;
	for(int i=0;i<=z.size()-1;i++){
		if(z[i]==m[0]){
			p=i;
			break;
		}
	}
	int u;
	u=p/a
	if(p/a==u){
		cour<<u<<" ";
	}else{
		cout<<u+1<<" ";
	}
	cout<<a+1-p%a;
}
