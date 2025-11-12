#include<bits/stdc++.h>
using namespace std;
string WW;
int b[1000000];
char a[1000000];
int main(){
	int c=0,z=0,mx=0,q=0;
	cin>>WW;
	int l=WW.size();
	for(int i=0;i<l;i++){
		if(WW[i]>='0'&&WW[i]<='9'){
			a[c]=WW[i];
			c++;
		}
	}for(int i=0;i<c;i++){
		b[i]=a[i];
		b[i]-=48;
	}for(int j=0;j<c;j++){
		for(int i=q;i<c;i++){
			if(b[i]>mx){
				mx=b[i];
				b[i]=b[j];
				q++;
			}
		}	
		b[j]=mx;
		mx=1;
	}for(int i=0;i<c;i++)cout<<b[i];
	return 0;
} 
