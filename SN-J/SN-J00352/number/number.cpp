//SN-J00352张晟轩渭南初级中学 
#include<bits\stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;

const int N=10001;
int a[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int u=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[u]=s[i]-'0';
			u++;
		}
	}
	sort(a+1,a+u);
	int sum=0;                   
	for(int i=1;i<u;i++){
		sum+=a[i]*pow(10,i-1);
	}
	cout<<sum<<endl;
	return 0;
}
