#include<bits/stdc++.h>
using namespace std;
int n,q;
struct op{
	string x,y;
}a[100001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=q;i++){
		int yy=0;
		string o,p;
		cin>>o>>p;
		for(int j=0;j<o.length();j++){
			for(int k=j;k<o.length();k++){
				string z="";
				for(int l=j;l<=k;l++){
					z+=o[l];
				}
				for(int l=1;l<=n;l++){
					if(a[l].x==z){
						string h="";
						for(int m=0;m<=j-1;m++){
							h+=o[m];
						}
						h+=a[l].y;
						for(int m=k+1;m<o.length();m++){
							h+=o[m];
						}
						if(h==p){
							yy++;
						}
					}
				}
			}
		}
		cout<<yy<<endl;
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/
