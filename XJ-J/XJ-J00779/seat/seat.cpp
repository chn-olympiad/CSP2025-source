#include<bits\stdc++.h>
using namespace std;
int d[100];
int n,m;
int c,r;
int flag=0,flag1=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=n*m-1;
	for(int g=0;g<=cnt;g++) cin>>d[g];
	for(int i=0;i<=cnt-1;i++)
	{
		if(d[i]>d[i+1]){
			flag=d[i+1];
			d[i+1]=d[i];
			d[i]=flag;
		}
	}
	for(int j=cnt-1;j>=0;j--){
		if(d[j]>d[j-1]){
			flag1=d[j-1];
			d[j-1]=d[j];
			d[j]=flag1;
		}
	}
	for(int jk=0;jk<=cnt;jk++){
		cout<<d[jk]<<endl;
	}

	fclose(stdin);
	sfclose(stdout);
	return 0;
} 
