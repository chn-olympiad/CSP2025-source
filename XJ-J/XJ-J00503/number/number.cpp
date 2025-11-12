#include<bits/stdc++.h>
using namespace std;
	string b="0123456789";
	int d[10];
int main(){
	freopen("r","number1.in",stdin);
	freopen("w","number.out",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<10;j++){
			if(a[i]==b[j]){
				d[j]+=1;
				
			} 
		}
	}
	for(int i=9;i>=0;i--){
	
	for(int j=0;j<d[i];j++){
		cout<<i;
	}
	}
	fclose(stdin);
	fclose(stdout);
		return 0;
}
