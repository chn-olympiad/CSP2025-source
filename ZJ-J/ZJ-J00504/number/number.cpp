#include<bits/stdc++.h>
using namespace std;

char s[1000005];
long long i,n,j,b[105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=strlen(s);
	for(i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[int(s[i]-'0')]++;
		}
	}
	for(i=9;i>=0;i--){
		for(j=1;j<=b[i];j++){
			cout<<i;
		}
	}
	cout<<"\n";
	return 0;
}
/*
#Shang4Shan3Ruo6Shui4
*/
