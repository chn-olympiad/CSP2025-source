#include<bits/stdc++.h>
using namespace std;
int b;
int a[100000][100000],O[100000];
int i,j;
int w[100000];
int w1,w2,w3;
int x[100000],x1[100000];
int sy[10];
int da(int a1,int b,int c){
	if(a1>=b&&a1>=c){
		swap(a1,c);
		w1++;
	}
	if(b>=a1&&b>=c){
		swap(b,c);
		w2++;
	}
	if(c>=a1&&c>=b){
		w3++;
	}
	return c;
}
int er(int a4,int b,int c){
	int e[3];
	e[0]=a4;e[1]=b;e[2]=c;
	sort(e,e+3);
	return e[1];
}
void pd(int ty){
	if(ty>i/2){
		for(int i=0;i<w1-i/2;i++){
			for(int j=0;j<i;j++){
				if(w[i]==x[j]){
					w[i]=x1[j];
				}
			}
		}
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>b;
	for(int m=0;m<b;m++){
		cin>>i;
		for(int n=0;n<i;n++){
			for(int x2=0;x2<3;x2++)
			cin>>a[n][x2];
			w[n]=da(a[n][0],a[n][1],a[n][2]);
			x[n]=w[n];
			x1[n]=er(a[n][0],a[n][1],a[n][2]);
		}
		sort(w,w+i);
		pd(w1);
		pd(w2);
		pd(w3);
		for(int n=0;n<i;n++)sy[i]=sy[i]+w[n];
		cout<<sy[i];
		i=0;
	}
	for(int m=0;m<b;m++)cout<<sy[m]<<endl;
	return 0;
}