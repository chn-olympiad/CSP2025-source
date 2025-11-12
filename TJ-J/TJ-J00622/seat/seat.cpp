#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",std);
	freopen("seat.out","w",std);
	int n,m;
	cin>>n>>m;
	int s[n][m];
	int a[100];
	for(int c=0;c<n*m;c++){
		cin>>a[c];
	}
	int R=a[0];
	int Rx,Ry;
	//i为列，j为行 
	int num=0;
	for(int p=0;p<n*m;p++){
		for(int q=1;q<n*m;q++){
			if(a[p]<a[q]){
				int d=a[p];
				a[p]=a[q];
				a[q]=d;
			}
		}
	}
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				s[i][j]=a[num];
				num++;
				if(s[i][j]==R){
					Rx=i+1;
					Ry=j+1;
				}
			}
		}else{
			for(int j=n-1;j>=0;j--){
				s[i][j]=a[num];
				num++;
				if(s[i][j]==R){
					Rx=i;
					Ry=j+1;
				}
			}
		}
	}
	cout<<Ry<<" "<<Rx;
	return 0;
}
