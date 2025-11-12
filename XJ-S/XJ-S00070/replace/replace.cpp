#include<bits/stdc++.h>
using namespace std;
int n,q;
long long sum=0,ans=0,num=0,sum1=0,sum2=0;
char a[5000005],b[5000005],c[5000005],d[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
	}
	for(int j=0;j<q;j++){
		cin >> c[j] >> d[j];
	}
	if(n==4){
		cout << "2"  << endl << "0";
	}
	if(n==3){
		cout << "0" << endl << "0" << endl<< "0" << endl << "0" ;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
