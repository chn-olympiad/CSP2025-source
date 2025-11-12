#include <bits/stdc++.h>
using namespace std;
int b[101],n,m,ch,x,y,sum,c=1;
int main(){
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>b[i];
	}
	ch=b[1];
	sort(b+1,b+1+sum);
	for(int i=1;i<=sum;i++){
		if(b[i]==ch){
			ch=sum-i+1;
			break;
		}
	}
	x=ch/m;
	if(ch%m!=0){
		x++;
	}
	ch=ch%m;
	if(ch==0){ 
		ch=m;
		c=0;
	}
	if(x%2==1){
		y=ch;
	}
	else {
		y=m-ch+1;
	}
	cout<<x<<' '<<y;
	return 0;
}
