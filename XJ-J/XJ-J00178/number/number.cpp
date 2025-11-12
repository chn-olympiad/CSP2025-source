#include<bits/stdc++.h>
using namespace std;
const int N=10e6+10;
string n;
int m[N],q;
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();++i){
		
		if((n[i]>='0')&&(n[i]<='9')){
			++q;
			m[i]=n[i]-48;
			sort(m,m+q);
			cout<<m[i]; 
			continue;
		}
		
	}
	cout<<endl;
//for(int i=0;i<=q;++i){
	//	for(int j=i;j<=q;++j){
	//		if(m[i]<m[j]){
	//			int h=m[i];
	//			m[i]=m[j];
	//			m[j]=h;
	//		
	//		}
	//		cout<<m[i];
	//	}
	//}//
	//cout<<endl;
	--q;
    sort(m+1,m+q+1);
	for(int i=q;i>=0;--i){
		cout<<m[i];
	}
	
return 0;
}  
