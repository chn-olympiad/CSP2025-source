#include<bits/stdc++.h>
using namespace std;
long long n,a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out ","w",stdout);
	cin>>n;
	char s[n],d[n];
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]%1==0){
		    s[i]=d[i];
		}else{
			a++;
		}
	}
	for(int i=1;i<=n-a;i++){
		for(int j=1;j<=i+1;j++){
			if(d[i]<=d[j])
			swap(d[j],d[i]);
		}
	}
    for(int i=1;i<=n-a;i++){
		if(d[i!=0]){
		cout<<d[i];
		}
	}
	return 0;
}
