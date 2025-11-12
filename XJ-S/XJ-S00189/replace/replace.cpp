#include<bits/stdc++.h>
using namespace std;
const int N=1e6+12;
int n,q;
string s[N][3],x1,x2;
string get(int a,int b,string c){
	string x;
	for(int i=a;i<=b;i++)
		x+=c[i];
	return x;
}
int find(string c){
	for(int i=1;i<=n;i++){
		if(s[i][1]==c)return i;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int size=sizeof(t1);
		for(int j=0;j<=size;j++){
			for(int k=j;k<=size;k++){
				if(j!=0){
					x1=get(0,j-1,t1);
					x2=get(0,j-1,t2);
				}
				string y1=get(j,k,t1);string y2=get(j,k,t2);int flag=find(y1);
				string z1=get(k+1,size,t1);string z2=get(k+1,size,t2);
//				cout<<j<<' '<<k<<' '<<y1<<' '<<flag<<' ';
				if(flag){
//					cout<<y2<<' ';
					if(s[flag][2]==y2 && x1==x2 && z1==z2)ans+=1;
//					cout<<x1<<' '<<x2<<' '<<s[flag][2]<<' '<<y2<<' '<<z1<<' '<<z2<<' '<<ans;
				}
//				cout<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
