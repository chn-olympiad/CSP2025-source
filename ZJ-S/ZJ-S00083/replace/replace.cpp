#include<bits/stdc++.h>
using namespace std;
struct eyz{
	string s1,s2;
}z[10000],qu[10000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	
    	cin>>z[i].s1>>z[i].s2;
    	int l=0,r=z[i].s1.size()-1;
    	while(z[i].s1[l]!=z[i].s2[l]){
    		l++;
		}
		while(z[i].s2[r]!=z[i].s1[r]){
			r--;
		}
		string sa="",sx="";
		for(int i=l;i<=r;i++){
			sa=sa+z[i].s1[i];
			sx=sx+z[i].s2[i];
		}
	}
	for(int i=1;i<=m;i++){
		cin>>qu[i].s1>>qu[i].s2;
		int l=0,r=z[i].s1.size()-1;
    	while(qu[i].s1[l]!=qu[i].s2[l]){
    		l++;
		}
		while(qu[i].s2[r]!=qu[i].s1[r]){
			r--;
		}
		string sa="",sx="";
		for(int i=l;i<=r;i++){
			sa=sa+qu[i].s1[i];
			sx=sx+qu[i].s2[i];
		}
	}
	for(int i=1;i<=m;i++){
		int cnt3=0;
		for(int j=1;j<=n;j++){
			if(qu[i].s1==z[i].s1&&qu[i].s2==z[i].s2){
				cnt3++;
			}
		}
		cout<<cnt3<<endl;
	}
	return 0;
}
