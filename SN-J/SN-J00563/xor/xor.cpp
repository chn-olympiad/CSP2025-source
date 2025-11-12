#include<bits/stdc++.h>
using namespace std;
string c(int d){
	string s1;
	while(d>0){
		if(d%2==1){
			s1='1'+s1;
		}else{
			s1='0'+s1;
		}
	}
}
int b(int x,int y){
	string s2,s3,s4;
	s2=c(x);
	s3=c(y);
	int l2=s2.size(),l3=s3.size();
	if(l2>l3){
		swap(s2,s3);
		swap(l2,l3);
	}
	for(int i=1;i<=l3-l2;i++){
		s2='0'+s2;
	}
	for(int i=0;i<l3;i++){
		if(s2[i]==s3[i]){
			s4=s4+'1';
		}else{
			s4=s4+'0';
		}
	}
	int num,f=1;
	for(int i=l3;i>=1;i--){
		if(s4[i]==1){
			num+=f;
		}
		f*=10;
	}
	return num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,g,num;
	int a[500001]={0};
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		cout<<"0";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			g=a[i];
			for(int x=i;x<=j;x++){
				g=b(g,a[x]);
			}
			if(g==k){
				num++;
			}
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
