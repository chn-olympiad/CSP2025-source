#include<bits/stdc++.h>
using namespace std;
int main( ){
	freopen("number.in.txt","r",stdin);
	freopen("number.out.txt","w",stdout); 
	char a[1000000];
	char a2[1000000];
	int i1=0,i2=0;
	int cup,lena=0,lenb=0;
	short b[1000000];
	while(cin>>a[i1])
	     
	     lena++;
	cout<<endl<<lena;
		for(int i=0;i<lena;i++){
			b[i]=short(a[i]);
	        lenb++;}
	  
	cout<<lenb;
	//for(int i=0;i<len;i++)
	  // cout<<b[i];
	i1=0;
	for(int i=0;i<lenb;i++){
		if(b[i1]<b[i]){
		  cup=b[i1];
		  b[i1]=b[i];
		  b[i]=cup;
	    }
	}
	
	return 0;
}
