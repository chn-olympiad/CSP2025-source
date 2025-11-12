#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[100005],b=0,c[100005],d=-1,c1=0;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>=1&&s[i]<=9){
			a[b]=s[i]);
			b++;
		}
	}
	for(int i=0;i<=b;i++){
		d=-1;
		for(int i=0;i<=b;i++){
			if(s[i]>d) d=s[i];
		}
		c[c1]=d;
		c1++;
	}
	for(int i=0;i<c1;i++){
		cout<<c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
