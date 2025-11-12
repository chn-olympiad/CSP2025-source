//fw小L没实力还要求这么多，wcnm，就你TM还学校算法协会的成员，你TM没学算法尽撸管了吧，跟那个日本potato（zzr）一样
//look here please:想上迷惑行为大赏，这行和代码(除了T3)不用放上去，感谢，tyty
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int V=1e6;
ll n,s[100],a[V],b[V],c[V],maxx[V],p[V],mp[V],f=0,sum=0,l,q,g;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=1;j<=s[i];j++)
			cin>>a[j]>>b[j]>>c[j];
		for(int j=1;j<=s[i];j++){
			mp[j]=0;
			p[j]=0;
			maxx[j]=0;
			f=0;
			sum=0;
			l=0;
			q=0;
		}
		l=s[i]/2;
		for(int j=1;j<=s[i];j++){
			maxx[j]=max(a[j],max(b[j],c[j]));
			if(maxx[j]==a[j]) p[j]=1;
			else if(maxx[j]==b[j]) p[j]=2;
			else p[j]=3;
//			cout<<"maxx "<<maxx[j]<<endl;
//			cout<<"p "<<p[j]<<endl;
		}
		for(int j=1;j<=s[i];j++){
			mp[p[j]]++;
		}
		for(int j=1;j<=s[i];j++){
			if(mp[j]>l) {
				f=1;
				g=j;
			}
//			cout<<"mp "<<mp[j]<<endl;
		}
//		cout<<"f "<<f<<endl;
		if(f==0){
			for(int j=1;j<=s[i];j++){
				sum+=maxx[j];
			}
		}
		else if(f==1){
			sort(maxx,maxx+s[i]+1);
			for(int j=s[i];j>=l+1;j--){
				sum+=maxx[j];
			}
			if(s[i]==2){
				sum=max(a[1]+b[2],max(a[1]+b[3],max(a[2]+b[1],max(a[2]+b[3],max(a[3]+b[1],a[3]+b[2])))));
			}
			else if(s[i]==4){
				sum=max(a[1]+a[2]+b[3]+b[4],max(a[1]+a[2]+b[3]+c[4],max(a[1]+a[2]+c[3]+c[4],max(a[1]+a[2]+c[3]+b[4],max(b[1]+b[2]+a[3]+a[4],max(b[1]+b[2]+a[3]+c[4],max(b[1]+b[2]+c[3]+c[4],max(b[1]+b[2]+c[3]+a[4],max(c[1]+c[2]+a[3]+a[4],max(c[1]+c[2]+b[3]+b[4],max(c[1]+c[2]+a[3]+b[4],max(c[1]+c[2]+b[3]+a[4],max(a[1]+b[2]+b[3]+a[4],max(a[1]+b[2]+b[3]+c[4],max(a[1]+c[2]+c[3]+a[4],max(a[1]+c[2]+c[3]+b[4],max(b[1]+a[2]+a[3]+b[4],max(b[1]+a[2]+a[3]+c[4],max(b[1]+c[2]+c[3]+b[4],max(b[1]+c[2]+c[3]+a[4],max(c[1]+a[2]+a[3]+c[4],max(c[1]+a[2]+a[3]+b[4],max(c[1]+b[2]+b[3]+c[4],max(c[1]+b[2]+b[3]+a[4],max(a[1]+b[2]+c[3]+a[4],max(a[1]+b[2]+c[3]+b[4],max(a[1]+b[2]+c[3]+c[4],max(b[1]+a[2]+c[3]+a[4],max(b[1]+c[2]+a[3]+c[4],max(a[1]+b[3]+c[2]+a[4],max(a[1]+b[3]+c[2]+b[4],max(a[1]+b[3]+c[2]+c[4],max(c[1]+b[2]+a[3]+a[4],max(c[1]+b[2]+a[3]+b[4],max(c[1]+b[2]+a[3]+c[4],max(a[1]+a[3]+b[2]+b[4],max(a[1]+b[3]+c[2]+c[4],max(c[1]+b[3]+c[2]+a[1],max(c[1]+c[3]+a[2]+a[4],max(b[1]+b[3]+c[2]+c[4],a[1]+c[2]+b[3]+c[4]))))))))))))))))))))))))))))))))))))))));
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/