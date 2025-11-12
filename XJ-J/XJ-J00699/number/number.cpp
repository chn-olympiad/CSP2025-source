#include<iostream>
using namespace std;
string s;
int a[10000010],j=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0; i<len; i++){
		if(isdigit(s[i])){
			a[j]=s[i];
			j++;
		}
	}
	for(int i=1; i<j-1; i++){
		for(int k=1; k<j-1; k++){
			if(a[k]<a[k+1]){
				swap(a[k],a[k+1]); 
			}
		}
	}
	for(int i=1; i<j; i++){
		cout<<char(a[i]);
	}
	return 0;
}
