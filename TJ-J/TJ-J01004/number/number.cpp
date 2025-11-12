#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),i;
	int a[n+1];
	for(char c:s){
		i=0;
		if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'){
			int b=c-'0';
			a[i]=b;
			i++;
		}
	}
	for(int j=1;j<=n*(n-1)/2+1;j++){
		for(int s=0;s<i;s++){
			if(a[s]<a[s+1]){
			int sum=a[s];
			a[s]=a[s+1];
			a[s+1]=sum;
		}
	}
}
	for(int k=0;k<i;k++){
		cout<<a[k];
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
