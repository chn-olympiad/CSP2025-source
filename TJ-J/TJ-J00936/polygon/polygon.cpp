#include<bits/stdc++.h>
using namespace std;
int x[5005],n;
int san(int a,int b,int c){
	if(x[a]+x[b]>x[c]){
		return 1;
	}
	return 0;
}
int si(int a,int b,int c,int d){
	int cnt=0;
	if(x[a]+x[b]+x[c]>x[d]){
		cnt++;
	}
	for(int i=0;i<4;i++){
		for(int j=i+1;j<4;j++){
			for(int k=j+1;k<4;k++){
				cnt+=san(i,j,k);
			}
		}
	}
	return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	sort(x,x+n);
	if(n==3){
		cout<<san(0,1,2);
	}else if(n==4){
		cout<<si(0,1,2,3);
	}
	fclose(stdin);
	fclose(stdout);
}
