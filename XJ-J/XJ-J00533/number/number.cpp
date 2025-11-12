#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;	
	int n=s.size()-1;
	int k=1;
	for(int i=0;i<=n;i++){
		if(s[i]=='1'){
			a[k]=1;
			k++;
		}
		if(s[i]=='2'){
			a[k]=2;
			k++;
		}
		if(s[i]=='3'){
			a[k]=3;
			k++;
		}
		if(s[i]=='4'){
			a[k]=4;
			k++;
		}
		if(s[i]=='5'){
			a[k]=5;
			k++;
		}
		if(s[i]=='6'){
			a[k]=6;
			k++;
		}
		if(s[i]=='7'){
			a[k]=7;
			k++;
		}
		if(s[i]=='8'){
			a[k]=8;
			k++;
		}
		if(s[i]=='9'){
			a[k]=9;
			k++;
		}
	}
	k--;
	sort(a+1,a+1+n+1,cmp);
	for(int i=1;i<=k;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//3d2f1gsd6sdfgfdsgsdgsgerytutyutyu45
//654321
//290es1q0
//92100
