#include <iostream>
#include <algorithm>
#include <cstdio>
//#include <string>

using namespace std;char a[1000005];char b[15];
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	string s;int j=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i];j++;
		}
	}



	for(int k=0;k<j;k++){
		int maxx=k;
		for(int i=k;i<j;i++){
			if(a[maxx]<a[i]){
				maxx=i;
			}

		}
		int temp=a[k];
		a[k]=a[maxx];a[maxx]=temp;
		cout<<a[k];
	}





	return 0;
}
