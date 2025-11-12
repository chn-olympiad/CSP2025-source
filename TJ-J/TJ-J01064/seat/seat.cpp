#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<cstdio>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	frepoen("seat.out","w",stdout);
	int n,m,lie=0,hang=0,x,olie,ohang,l,h;
	bool fx=true;
	cin>>n>>m;
	int zong=n*m;
	int s[n][m],a[zong];
	for(int i=0;i<=n*m-1;i++){
		cin>>a[i];
	}
	int a1=a[0];
	for (int i=0;i<=zong-1;i++){
		for (int j=1;j<=zong-i;j++){
			if (a[i]<a[i+j]){
				x=a[i];
				a[i]=a[i+j];
				a[i+j]=x;
			}
		}
	}
	for(int i=0;i<=zong;i++){
		if (a[i]==a1){
			cout<<hang+1<<' '<<lie+1;
		}
		s[lie][hang]=a[i];
		if (hang==(n-1)){
			lie++;
			fx=!fx;
		}
		else if (hang==0&&lie>=1){
			lie++;
			fx=!fx;
		}
		else if (fx==true){
			hang++;
		}
		else if (fx==false){
			hang++;
		}
	}	 
	
	fclose("seat.in");
	fclose("seat.out");
	return 0;
}
