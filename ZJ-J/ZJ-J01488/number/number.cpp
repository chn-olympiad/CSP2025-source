#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,no;
	
	cin>>a;
	
	if(a.size()==1){
		cout<<a;
		
	}
	else{
		for(int i=0;i<a.size();i++){
			if(a.size()!=1&&a[i]/a[i]==1){
				cout<<a[i];
				break;
			}
		}
		
	}for(int i=1;i<=no.size();i++){
		cout<<no[i];
	}
	
	return 0;
}
