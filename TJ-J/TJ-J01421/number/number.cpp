#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int k=0,t=0;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			a[k]=1;
		    k++;
		}else if(s[i]=='2'){
			a[k]=2;
			k++;
		}else if(s[i]=='3'){
			a[k]=3;
			k++;
		}else if(s[i]=='4'){
			a[k]=4;
			k++;
		}else if(s[i]=='5'){
			a[k]=5;
			k++;
		}else if(s[i]=='6'){
			a[k]=6;
			k++;
		}else if(s[i]=='7'){
			a[k]=7;
			k++;
		}else if(s[i]=='8'){
			a[k]=8;
			k++;
		}else if(s[i]=='9'){
			a[k]=9;
			k++;
		}else if(s[i]=='0'){
			a[k]=0;
			k++;
		}
	}
	for(int i=0;i<k;i++){
		int sum=0;
		for(int j=0;j<k;j++){
			if(a[j]>=sum){
				sum=a[j];
			}
		}
		if(sum!=-1){
			cout<<sum;
		}
		for(int j=0;j<k;j++){
			if(a[j]==sum){
				a[j]=-1;
				break;
			}
		}
	}
	return 0;
}

