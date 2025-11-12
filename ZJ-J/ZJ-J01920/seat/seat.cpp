#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

long long n,m,a[100050],score,x,flag;

long long Read(){
	long long Ra=0,Rf=1;
	char Rc=getchar();
	while(Rc<'0'||Rc>'9'){
		if(Rc=='-') Rf=-1;
		Rc=getchar();
	}
	while(Rc>='0'&&Rc<='9'){
		Ra=(Ra<<1)+(Ra<<3)+(Rc&15);
		Rc=getchar();
	}
	return Ra*Rf;
}bool cmp(long long u,long long v){
	return u>v;
}int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=Read(),m=Read();
	for(int i=1;i<=n*m;i++){
		a[i]=Read();
	}
	score=a[1];
	sort(a+1,a+n*m+1,cmp);
	x=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[x]==score){
					cout<<i<<" "<<j<<"\n";
					flag=1;
					break;
				}
				x++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[x]==score){
					cout<<i<<" "<<j<<"\n";
					flag=1;
					break;
				}
				x++;
			}
		}
		if(flag==1){
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
