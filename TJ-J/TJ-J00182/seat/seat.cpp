#include <bits/stdc++.h>
using namespace std;
int cmp(int q,int p){
	return q>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[101]={0};
	int b[101][101]={0};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int e=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=2;
	if(a[1]==e){
		cout<<"1 1";
		return 0;
	}
	for(int i=2;i<=n*m;i++){
		if(a[i]==e){
			cout<<x<<' '<<y;
			return 0;
		}
		if(y+1>m&&x%2!=0){
			x+=1;
			if(x%2!=0){
			   y=1;
			}
		}
		else{
			if(x%2==0&&y-1!=0){
				y-=1;
			}
			else if(y-1==0){
				x+=1;
			}
			else{
				y+=1;
			}
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
