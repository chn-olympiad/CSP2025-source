#include <bits/stdc++.h>
using namespace std;
int main(){
int n,m,Ans,a,d;
cin>>n>>m;
a=n*m;
int ans[a+1];
for(int i=1;i<a+1;i++){
	cin>>ans[i];
	if(i==1){
		Ans=ans[i];
	}
}

for(int n=1;n<a+1;n++){
	for(int i=1;i<a;i++){
	if(ans[i]<ans[i+1]){
		int s;
		s=ans[i];
		ans[i]=ans[i+1];
		ans[i+1]=s;
	}
}}
for(int i=1;i<a+1;i++){
	if(Ans==ans[i]){
	if(i%m==0){
		d=i/m;
	}
	else{d=i/m+1;
	}
	cout<<d<<" ";
	if(d==1){	cout<<i;return 0;
	}
if(d%2==0){	cout<<d*m+1-i;
	}
	else{cout<<m-d*m+i;
	}
	}
}
return 0;
}

