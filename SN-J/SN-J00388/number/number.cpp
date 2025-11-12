#include<bits/stdc++.h>
using namespace std;
const int NUM=1e6+10;
char a[NUM];
int b[NUM];
int ans;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[ans++]=a[i]-'0';
		}
	}
	sort(b,b+ans,cmp);
	for(int i=0;i<ans;i++){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
