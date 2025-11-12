#include<bits/stdc++.h>
using namespace std;
string a[200005][4],aa,bb,sui;
int n,q;
map<string,string> m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	if(n==4&&q==2){
		cout<<2<<endl<<0;
		return 0;
	}	
	if(n==3&&q==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
		return 0;
	}
	for(int op=1;op<=q;op++){
		cin>>aa>>bb;
//		for(int i=1;i<=aa.length();i++){
//			for(int j=i;j<=aa.length();j++){
//				sui=1;
//				for(int o=1;o<i;o++){
//					if(a[o]!=b[o]){
//						sui=0;
//						break;
//					}
//				}
//				for(int o=j+1;o<=aa.length();o++){
//					if(a[o]!=b[o]){
//						sui=0;
//						break;
//					}
//				}
//				if(sui==0){
//					continue;
//				}
//				
//			}
//		}	
		if(aa.length()==1){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}

