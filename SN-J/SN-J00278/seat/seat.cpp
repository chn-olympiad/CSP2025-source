#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,c,r,g,max_=-1,maxn;
	cin>>n>>m;
	int a[m*n],s[m*n],p[m][n];
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	g=a[0];
	//sorting
	for(int i=0;i<m*n;i++){
		for(int j=0;j<m*n;j++){
			if(a[j]>max_){
				max_=a[j];
				maxn=j;
			}
		}
		s[i]=max_;
		a[maxn]=-1;
		max_=-1;
	}
	//sitting
	//for(int i=0;i<m*n;i++){
		//if((i/n)%2==1){
			//Which means in an even col
			//p[i/n+1][n+1-i%n]=s[i];
		//}else{
			//in an odd col
			//p[i/n+1][i%n]=s[i];
		//}
	//}
	for(int i=1;i<=m*n;i++){
		if(s[i-1]=g){
		if(((i-1)/n)%2==1){
			//Which means in an odd col
			//p[i/n+1][n+1-i%n]=s[i];
			c=i/n+1;
			r=i%n;
			if(r==0)r=n;
		}else{
			//in an even col
			//p[i/n+1][i%n]=s[i];
			c=i/n+2;
			r=n+1-i%n;
		}
		break;
	}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
