//考号；SN-J00829 姓名；白凌霄 学校:延安职业技术学院附属中学
#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a,b,c=1,d=1;
	cin>>n>>m>>a;
	for(int i=0;i<n*m-1;i++){
        cin>>b;
		if(a<b && m%2==0){
			c++;
		}
		else if(a<b && m%2==1){
		c--;
	} b=0;
		if(c>n && m%2==0){
			c=n-1;
			d++;
		}
		else if(c<1 && m%2==1){
		c=2;
		d++;
	}
}
    cout<<d<<' '<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
