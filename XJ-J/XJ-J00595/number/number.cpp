#include<bits\stdc++.h>
 using namespace std;
 const int N=1e3+9;
 int main (){
 	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
 	string s;
 	int a[N];
	int nm=1,p;
 	cin>>s;
 	for(int i=0;i<=s.size();i++){
 		if(s[i]>='0'&&s[i]<='9'){
 			a[nm]=s[i];
 			nm++; 
		 }
	 }
	 while(p==1){
	 	p=0;
	 	if(nm==2){
	 		break;
		 }
	 	else if(nm>2){
	 		for(int i=2;i<nm;i++){
	 			if(a[i]>a[i-1]){
	 				int bb=a[i];
	 				a[i]=a[i-1];
	 				a[i-1]=bb;
	 				p=1;
				 }
			 }
		 }
	 }
 	for(int i=1;i<nm;i++){
 		char cc=a[i];
 		cout<<cc;
	 }
 	return 0;
 }
