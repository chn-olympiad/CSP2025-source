#include <bits/stdc++.h>
using namespace std;
typedef int longlong;
long long t,n,n1,value=0;
const int N=1e5+10;
int b[4];//Õ¼ÓÃ

struct a1{
	int b1,b2,b3;
	int maxyuan,wei;
}a[N];

bool cmp1(a1 m1,a1 n1){
	return m1.maxyuan > n1.maxyuan;
}

bool pd(int m){
	if(m==1&&(b[m]<n1)){
		b[m]++;		
	}else if(m==2&&(b[m]<n1)){
		b[m]++;
	}else if(m==3&&(b[m]<n1)){
		b[m]++;
	}else{
		return 0;
	}
}

void pai(int i1){
	if(b[1]==n1){
		for(int i=i1;i<=n;i++){
			a[i].maxyuan=max(a[i].b2,a[i].b3);
		}
	}else if(b[2]==n1){
		for(int i=i1;i<=n;i++){
			a[i].maxyuan=max(a[i].b1,a[i].b3);
		}
	}else{
		for(int i=i1;i<=n;i++){
			a[i].maxyuan=max(a[i].b1,a[i].b2);
		}
	}
	sort(a+i1,a+n+1,cmp1);
	for(int i=i1;i<=n;i++){
		value+=a[i].maxyuan;
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		n=0; 
		cin>>n;
		n1=n/2;
		for(int i=1;i<=n;i++){
		cin>>a[i].b1>>a[i].b2>>a[i].b3;
		if(a[i].b1>a[i].b2){
			if(a[i].b1>a[i].b3){
				a[i].maxyuan=a[i].b1;
				a[i].wei=1;
			}else{
				a[i].maxyuan=a[i].b3;
				a[i].wei=3;
			}
		}else{
		 	if(a[i].b2>a[i].b3){
				a[i].maxyuan=a[i].b2;
				a[i].wei=2;
			}else{
				a[i].maxyuan=a[i].b3;
				a[i].wei=3;
			}
		 } 
	}
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++){
		if(pd(a[i].wei)){
			value+=a[i].maxyuan;
		}else{
			if((i==n)&&(a[n].maxyuan!=0)){
				cout<<1<<endl;
				value-=a[i-1].maxyuan;
				value+=max(a[n].b1,max(a[n].b2,a[n].b3));
				i--;
			}
			pai(i);
			break;
		}
	}
	cout<<value;
}
fclose(stdin);
fclose(stdout);
	return 0;
} 

