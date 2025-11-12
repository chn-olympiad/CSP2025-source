#include<bits/stdc++.h>
using namespace std;
long long n=0,q=0,s=0;
string a[1000000],a1[1000000],b[100000],b1[100000];
int main(){
	freopen("replace.in",'r',stdin);
	freopen("replace.out",'w',stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i]>>a1[i];
	}
	for(int i=0;i<q;i++){
		cin>>b[i]>>b1[i];
	}
	for(int i=0;i<q;i++){
		s=0;
		for(int j=0;j<n;j++){
			if(b[i]==a[j]&&b1[i]==a1[j]){
				s+=2;
			}
		}
		cout<<s<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
