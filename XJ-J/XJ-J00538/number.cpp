#include<bits/stdc++.h>
using namespace std;
string c;
int num[1000010];
int cmp(int a,int b){
	 return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	int x=0;
	for(int i=0;i<c.size();i++){
		int n=int(c[i])-48;
		if(n>9) continue;
		else{
			num[i]=n;
			x++;
		}
	}
 	sort(num,num+num[x+1],cmp);
 	for(int i=0;i<x;i++){
 		cout<<num[i];
 	}
 	return 0;
}
