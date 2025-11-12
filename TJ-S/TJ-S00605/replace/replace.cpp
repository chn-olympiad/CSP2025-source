#include<bits/stdc++.h>
using namespace std;
struct pa{
	string a,b;
}p[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n;
	cin>>n;
	int k;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].b;
	}
	while(k--){
		string s1,s2;
		cin>>s1>>s2;
		int num=0;
		for(int i=1;i<=n;i++){
			if(s1.find(p[i].a)<=5000001&&s2.find(p[i].b)<=5000001){
				bool flag1=1,flag2=1;
				for(int j=0;j<s1.find(p[i].a);j++){
					if(s1[j]!=s2[j]){
						flag1=0;
						break;
					}
				}
				for(int j=s1.find(p[i].a)+p[i].a.size();j<s1.size();j++){
					if(s1[j]!=s2[j]){
						flag2=0;
						break;
					}
				}
				if(flag1&&flag2){
					num++;
				}
			}
		}
		cout<<num<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
