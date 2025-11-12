#include<iostream>
#include<string>
using namespace std;
int a[100005];
int main(){
	string s;
	int cur=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(!(s[i]<='z'&&s[i]>='a')) a[++cur]=s[i]-'0';
	}
	for(int i=1;i<=cur;i++){
		int k=i,maxn=-1e9;
		for(int j=i;j<=cur;j++){
			if(maxn<a[j]){
				maxn=a[j];
				k=j;
			}
		}
		int x=a[i];
		a[i]=a[k];
		a[k]=x;
	}
	for(int i=1;i<=cur;i++){
		cout<<a[i];
	}
	return 0;
}

