#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef struct sss{
	string s1;
	string s2;
}sc;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans;
	cin>>n>>q;
//	cout<<1;
	sc s[n],t[q];
	for(int i=0;i<n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	for(int i=0;i<q;i++){
		cin>>t[i].s1>>t[i].s2;
	}
//	cout<<1;
	for(int i=0;i<q;i++){
		int jie=0;
		
		for(int j=0;j<n;j++){
			int ii=0,iif=0;
			while(t[i].s1[ii]!=NULL&&iif!=1){
				if(t[i].s1[ii]==s[j].s1[0]&&t[i].s2[ii]==s[j].s2[0]){
					iif=1;
					bool tf=true;
					int jj=1;
					while(s[j].s1[jj]!=NULL){
						
						if(t[i].s1[ii+jj]!=s[j].s1[jj]||t[i].s2[ii+jj]!=s[j].s2[jj])tf=false;
						jj++;
					}
				
					if(t[i].s1[ii+jj]!=t[i].s2[ii+jj])tf=false;
					if(tf)jie++;
				}
				ii++;
			}
		}
		cout<<jie<<'\n';
	}
	
	return 0;
}
/*	int l=-1,r=-1;
		int j=0;	
while(t[i].s1[j]!=NULL){
			if(t[i].s1[j]!=t[i].s2[j]){
				if(l<0)l=j;
				r=j;
			}
		}
		char cha1[r-l+1],cha2[r-l+1];
		for(int j=l;j<=r;j++){
			cha1[j]=t[i].s1[j];
			cha2[j]=t[i].s2[j];
		}
		for(int j=0;j<n;j++){
			while()
		}*/
