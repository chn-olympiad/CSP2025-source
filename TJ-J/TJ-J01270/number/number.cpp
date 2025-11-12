#include<bits/stdc++.h>
using namespace std;
string s;
int c[1000000],x[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int sum=0,a,k;
	cin>>s;
	int v=s.size();
	for(int i=0;i<v;i++){
		if(s[i]<='9'&&s[i]>=0){			
			c[i]=s[i];
			c[i]=c[i]-48;
			k+=1;
		}
	}
	for(int j=0;j<v;j++){
		sum=0;
		for(int i=0;i<v;i++){
			if(c[i]>=sum){
				sum=c[i];
				a=i;	
			}
		}
		c[a]=0;
		x[j]=sum;
	}
	for(int i=0;i<k;i++){
		cout<<x[i];
	}
	return 0;
}
