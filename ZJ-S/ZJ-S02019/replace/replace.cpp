//3
#include<bits/stdc++.h>
using namespace std;
string a1,a2,c1,d1;
struct xxx{
	int cha,l,r;
};
xxx b[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a1>>a2;
		int a1wei=0,a2wei=0;
		while(a1[a1wei]=='a')a1wei++;
		while(a2[a2wei]=='a')a2wei++;
		b[i].cha=a1wei-a2wei;
		b[i].l=min(a1wei,a2wei);
		b[i].r=min(n-a1wei,n-a2wei);
	}
	for(int i=1;i<=q;i++){
		cin>>c1>>d1;
		int c1wei=0,d1wei=0;
		while(c1[c1wei]=='a')c1wei++;
		while(d1[d1wei]=='a')d1wei++;
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(c1wei-d1wei==b[i].cha&&c1wei>=b[i].l&&d1wei<=b[i].r)sum++;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
