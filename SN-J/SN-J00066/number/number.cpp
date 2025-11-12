#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a1;
cin>>strin;
int a2[n];
int s=0;
int s1=0;
int s2=0;
for(int i=0;i<a1.sizf()/a1[0].sizf();i++){
	cin>>a1[i];
	if(a1[i]=='1'){
		a2[s1]=1;
		s1+=1;
	}
	if(a1[i]=='2'){
		a2[s1]=2;
		s1+=1;
	}
		if(a1[i]=='3'){
		a2[s1]=3;
		s1+=1;
	}
		if(a1[i]=='4'){
		a2[s1]=4;
		s1+=1;
	}
		if(a1[i]=='5'){
		a2[s1]=5;
		s1+=1;
	}
		if(a1[i]=='6'){
		a2[s1]=6;
		s1+=1;
	}
		if(a1[i]=='7'){
		a2[s1]=7;
		s1+=1;
	}
		if(a1[i]=='8'){
		a2[s1]=8;
		s1+=1;
	}
		if(a1[i]=='9'){
		a2[s1]=9;
		s1+=1;
	}
}
int a3[s1];
int a4[9];
for(int i=9;i>=1;i--){
	for(int j=0;j<s1;j++){
		if(a2[j]==i){
			a4[j]+=1;
		}
	}
}
for(int i=9;i>=1;i--){
	for(int j=0;j<a4[s2];j++){
		a3[s]=i;
		s+=1;
	}
	s2+=1;

}
for(int i=0;i<s1;i++){
	cout<<a3[i];
}

	return 0;
}
