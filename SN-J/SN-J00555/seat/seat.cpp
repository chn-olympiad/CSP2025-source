#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5][m+5]={0},b[n*m+5]={0},c[102]={0},num,h=1,l=1;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		c[b[i]]++;
	}
	num=b[1];
	int i=100;
	while(i>num){
		if(c[i]==0){
			i--;
			continue;
		}
		if(c[i]!=0&&l%2==1&&h<n) h++;
		else if(c[i]!=0&&l%2==1&&h==n) l++;
		else if(c[i]!=0&&l%2==0&&h>1) h--;
		else if(c[i]!=0&&l%2==0&&h==1) l++;
		i--;
	}
	cout<<l<<" "<<h;
	return 0;
}

