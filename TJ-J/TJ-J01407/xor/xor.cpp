#include<bits/stdc++.h>
using namespace std;
#define l long long
int a[100000];
int b[100000];
int c[100000];
l suan(l x,l y){
	l sum=0;
	for(l i=x;i<=y;i++){
		sum=sum^a[i];
	}
	return sum;
}
int main(){
	int n,k,cnt=1,ce1,ce2,sum=0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(l i=1;i<=n;i++){
		cin>>a[i];
	}
	for(l i=1;i<=n;i++){
		for(l j=i;j<=n;j++){
			if(suan(i,j)==k){
				b[cnt]=i;
				c[cnt]=j;
				cnt++;
			}
		}
	}
	cnt--;
	sum=cnt;
	for(l i=1;i<=cnt-1;i++){
		ce1=b[i];
		ce2=c[i];
		for(l j=i+1;j<=cnt;j++){
			if(b[j]==-1)	continue;
			if(b[i]==-1)	break;
			l ce11=b[j],ce22=c[j];
			if(ce11>=ce1&&ce11<=ce2||ce22>=ce1&&ce22<=ce2){
				sum--;
				if(ce22-ce11>=ce2-ce1){
					b[j]=-1;
					}
				else{
					b[i]=-1;
					}
			}
		}
	}
	cout<<sum;
	return 0;
}
