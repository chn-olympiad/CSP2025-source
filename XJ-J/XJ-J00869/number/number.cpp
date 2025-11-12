#include<bits/stdc++.h>
using namespace std;
int main(){/
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[s.size()],b=0;
	for(int i=0;i<s.size();i++){
		if(int(s[i]<10)){
			a[i]=int(s[i]);
			b+=1;
		}
	}
	for(int i=0;i<b-1;i++){
		for(int j=0;j<b-i-1;j++){
			if(a[j]<a[j-1]){
				int x=a[j];
				a[j]=a[j-i];
				a[j-i]=x;
			}                                                       
		}
	}
	for(int i=0;i<b;i++){
	cout<<a[i];
	}
	return 0;
}
