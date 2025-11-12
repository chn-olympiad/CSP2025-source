#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long b=s.size(),q,a[b],n=0,num=0,big=0;
	for(int i=0;i<b;i++){
		if(s[i]>=48 && s[i]<=57){
			a[n]=s[i]-48;
			n++;
		}
	}
	for(long long i=0;i<n;i++){
		big=0;
		for(long long l=0;l<n;l++){
			if(a[l]>big){
				big=a[l];
				q=l;
			}
		}
		a[q]=0-1;
		if(b==1){
			num+=big;
			break;
		}
		num+=big;
		num*=10;
		b--;
	}
	if(num%10==num) num*=10;
	cout<<num/10;
	return 0;
}
