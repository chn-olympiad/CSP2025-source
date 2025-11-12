#include<bits/stdc++.h>
using namespace std;
long long n=0;	
string b;
long long num[1000005],k=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	//memset(a,sizeof(a),-1);
	//cin>>a;

	cin>>b;
	while(b[n]!=NULL){
		n++;
		//cout<<n<<endl;
	}
	for(long long i=0;i<n;i++){
		if(b[i]=='0' || b[i]=='1' ||b[i]=='2' || b[i]=='3' || b[i]=='4' ||b[i]=='5' ||b[i]=='6' || b[i]=='7' ||b[i]=='8' ||b[i]=='9'){
			num[k]=int(b[i]-48);
			k++;
		}
	}
	//sort(num,num+ii);
	for(int j=k-1;j>=1;j--){
		cout<<num[j];
	}
	//cout<<n;
	return 0;
}
