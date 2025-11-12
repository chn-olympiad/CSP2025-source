//SN-J00835 白梓桐 西安市曲江第二中学
#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=0;
	string s;
	cin>>s;
	int ask;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ask=s[i]-'0';
			a[k]=ask;
			k++;
		}
		
	}
	int mb=a[0];
	int u=-1;
	for(int i=0;i<k;i++){
		if(i!=0){
			if(mb==a[i]||mb>a[i]){
				u=i;
				break;
			}
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=0;i<k;i++){
		if(i!=0){
			if(u==i){
				cout<<mb;
			}
			cout<<a[i];
		}
	}
	if(u==-1) cout<<mb;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
