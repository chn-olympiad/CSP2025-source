#include<iostream>
using namespace std;
string s;
int x=1,a[10005],xx;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[x]=s[i]-'0';
			x++;
		}
	}
	for(int i=1;i<x;i++){
		for(int j=i;j<x;j++){
			if(a[j]>a[i]){
				xx=a[i];
				a[i]=a[j];
				a[j]=xx;
			}
		}
	}
	for(int i=1;i<x;i++){
		cout<<a[i];
	}
	return 0;
}
