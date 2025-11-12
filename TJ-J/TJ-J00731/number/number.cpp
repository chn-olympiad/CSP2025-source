#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int b[1000010];
int n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int la=0;
	while(a[la]>='a'&&a[la]<='z'||a[la]>='0'&&a[la]<='9'){
		la++;
	}
	
	for(int i=0;i<la;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[i]=a[i]-48;
			n++;		
		}
	}
	for(int j=0;j<n;j++){
		int max=b[0],t=0,c;
		for(int i=1;i<n;i++){
			if(b[i]>=max&&b[i]!=-1){
				max=b[i];
				t=i;
			}
		}
		cout<<max;
		b[t]=-1;
		c=b[t];
		b[t]=b[n-j];
		b[n-j]=c;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
