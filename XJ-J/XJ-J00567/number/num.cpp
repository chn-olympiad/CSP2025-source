#include<bits/stdc++.h>
using namespace std;
 
int main(){
	freopen("number.in",'r',stdin);
	freopen("number.out",'w',stdout);
	
	string a;
	int n=0,sum=0;
	cin>>a;
	
	int let[len[a]];
	for(int i=0;i<len(a);i++){
		if(a[i]==1||a[i]==2||a[i]==3||a[i]==4||a[i]==5||a[i]==6||a[i]==7||a[i]==8||a[i]==9||a[i]==0){
			let[n]=a[i];
			n+=1;
		}
	}
	sort(let[0],let[len(a)]+1);
	n=len(let);
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			let[i]*=10;
		}
		sum+=let[i];
	}
	cout<<sum;
	fclose(in);
	fclose(out);
	return 0;
	
} 
