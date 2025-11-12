#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
string a;
int k;
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[k]=a[i]-'0';
			k++;
		}
	}
	sort(b,b+k,cmp);
	for(int i=0;i<k;i++){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}