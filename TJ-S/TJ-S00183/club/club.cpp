#include<bits/stdc++.h>
using namespace std;
long long n=0,t=0,s=1,w1=0,w2=0,w3=0,ty=0;
long long a[100000]={0},a1[100000]={0},a2[100000]={0},cha[300000]={0};
long long b[100000]={1},b1[100000]={2},b2[100000]={3},po[100]={0};
int main(){
	freopen("club.in",'r',stdin);
	freopen("club.out",'w',stdout);
	cin>>ty;
	for(int i=1;i<=ty;i++){
		t=0;
		w1=0;
		w2=0;
		w3=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>a1[j]>>a2[j];
			b[j]=1;
			b1[j]=2;
			b2[j]=3;
			if(a[j]<a1[j]){
				swap(a[j],a1[j]);
				swap(b[j],b1[j]);
			}
			if(a2[j]>a1[j]){
				swap(a2[j],a1[j]);
				swap(b2[j],b1[j]);
			}
			if(a2[j]>a[j]){
				swap(a2[j],a[j]);
				swap(b2[j],b[j]);
			}
			cha[j]=a[j]-a1[j];
		}
		for(int j=1;j<n;j++){
			for(int z=j+1;z<=n;z++){
				if(cha[j]<cha[z]){
					swap(cha[j],cha[z]);
					swap(a[j],a[z]);
					swap(a1[j],a1[z]);
					swap(a2[j],a2[z]);
					swap(b[j],b[z]);
					swap(b1[j],b1[z]);
					swap(b2[j],b2[z]);
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(b[j]==1){
				if(w1<n/2){
					t+=a[j];
					w1++;
				}
				else{
					t+=a1[j];
				}
			}
			else if(b[j]==2){
				if(w2<n/2){
					t+=a[j];
					w2++;
				}
				else{
					t+=a1[j];
				}
			}
			else{
				if(w3<n/2){
					t+=a[j];
					w3++;
				}
				else{
					t+=a1[j];
				}
			}
		}
		po[s]=t;
		s++;
	}
	for(int i=1;i<=ty;i++){
		cout<<po[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
