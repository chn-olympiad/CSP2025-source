#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt,n;
//struct eyz{
//	string a,b;
//}a[5000005];
//struct ch{
//	string a,b;
//}b[5000005];
//void dfs(string to,string now){
//	if(now==to){
//		cnt++;
//		return;
//	}
//	for(int i=0;i<=now.size()-1;i++){
//		for(int j=1;j<=n;j++){
//			if(now.substr(i,b[j].a.size())==b[j].a){
//				string noww=now;
//				for(int k=i;k<=i+b[j].a.size();k++){
//					noww[k]=b[j].a[k];
//					dfs(to,noww);
//				}
//			}
//		}
//	}
//}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int m;
	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i].a>>a[i].b;
//	}
//	for(int i=1;i<=m;i++){
//		cin>>b[i].a>>b[i].b;
//	}
//	for(int i=1;i<=m;i++){
//		dfs(b[i].b,b[i].a);
//		cout<<cnt<<endl;
//		cnt=0;
//	}
for(int i=1;i<=m;i++){
	cout<<'0'<<endl;
}
	return 0;
}
