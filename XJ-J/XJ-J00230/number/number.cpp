#include<bits/stdc++.h>
using namespace std;
struct Number{
	string x;
	bool flag_x;
};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,maxa;
	int n,numa=0,maax;
	cin>>s;
	n=s.size();
	Number a[n+10];
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[numa].x=s[i];
			a[numa].flag_x=0;
			numa++;
		}
	}
	for(int i=0;i<numa;i++){
		maxa='0';
		for(int j=0;j<numa;j++){
			if(a[j].flag_x==0&&a[j].x>maxa){
				maxa=a[j].x;
				maax=j;
			}
		}
		cout<<maxa;
		a[maax].flag_x=1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
