#include<bits/stdc++.h>
using namespace std;
string a;
int k=0;
int booknum[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if((a[i]>='0')&&(a[i]<='9')){
			k++;
			booknum[k]=(int)(a[i]-'0');	
		}
	}
	sort(booknum+1,booknum+k+1,cmp);
	for(int i=1;i<=k;i++){
		cout<<booknum[i];
	}
	return 0;
} 
