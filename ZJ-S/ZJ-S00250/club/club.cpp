#include<bits/stdc++.h>
using namespace std;
int n,a[2][100006],t,fav[2][50006],b[2][100006],in1[3],in2[3],tot[3],maxx,flag;
long long cn,dlta[100006];
int jin[3][100006];
void sor() {
	for(int i=0; i<3; i++) {
		for(int j=2; j>i; j--) {
			if(in1[j]>in1[i]) {
				swap(in1[j],in1[i]);
				swap(in2[j],in2[i]);
			}
		}
	}
}
void so() {
	for(int i=0; i<n; i++) {
		for(int j=n; j>i; j--) {
			if(dlta[j]>dlta[i]) {
				swap(dlta[j],dlta[i]);
			}
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0; i<t; i++) {
		cn=0;
		cin>>n;
		tot[0]=0,tot[1]=0,tot[2]=0;
		maxx=-1;
		flag=0;
		for(int j=0; j<n; j++) {
			cin>>in1[0]>>in1[1]>>in1[2];
			in2[0]=0;
			in2[1]=1;
			in2[2]=2;
			sor();
			jin[0][j]=in1[0];
			jin[1][j]=in1[1];
			jin[2][j]=in1[2];
			a[0][j]=in1[0];
			b[0][j]=in2[0];
			a[1][j]=in1[1];
			b[1][j]=in2[1];
			tot[b[0][j]]+=1;
		}
		for(int j=0; j<3; j++) {
			if(maxx<tot[j]) {
				maxx=tot[j],flag=j;
			}
		}
		//cout<<flag<<endl;
		for(int j=0; j<=n; j++) {
			fav[0][j]=0;
			fav[1][j]=0;
			dlta[j]=0;
		}
		//int k=n/2;
		for(int j=0; j<n; j++) {
			if(flag==b[0][j]) {
				cn+=a[1][j];
				dlta[j]=a[0][j]-a[1][j];
			} else {
				cn+=a[0][j];
				dlta[j]=jin[flag][j]-a[0][j];
			}
		//cout<<"["<<cn<<"]"<<endl;
		}
		so();
		for(int k=0; k<n/2; k++)cn+=dlta[k];
		cout<<cn<<endl;
	}
	

	return 0;
}
