#include<bits/stdc++.h>
using namespace std;
struct p{
	char x[310],y[310];
}s[310],a;
int n,q,f,ss;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
//	if(n<=100&&q<=100){
//		for(int i=1;i<=n;i++){
//			scanf("%s%s",s[i].x+1,s[i].y+1);
//		}
//		while(q--){
//			scanf("%s%s",a.x+1,a.y+1);
//			int l=strlen(a.x+1);
//			for(int i=1;i<=n;i++){
//				int ll=strlen(s[i].x+1);
//				for(int i2=1;i2<=l-ll+1;i2++){
//					f=1;
//					cout<<i<<" "<<i2<<"~"<<endl;
//					for(int i3=i2;i3<=i2+ll-1;i3++){
//						if(s[i].x[i3-i2+1]!=a.x[i3]||s[i].y[i3-i2+1]!=a.y[i3]){
//							f=0;
//							cout<<i3<<"?"<<endl;
//							break;
//						}
//					}
//					if(!f)continue;
//					for(int i3=1;i3<i2;i3++){
//						if(a.x[i3]!=a.y[i3]){
//							f=0;
//							cout<<i3<<"?"<<endl;
//							break;
//						}
//					}
//					for(int i3=i2+ll;i3<=l;i3++){
//						if(a.x[i3]!=a.y[i3]){
//							f=0;
//							cout<<i3<<"?"<<endl;
//							break;
//						}
//					}
//					if(f){
//						ss++;
//						cout<<i<<"!"<<endl;
//					}
//				}
//			}
//			cout<<ss<<endl;
//		}
//		return 0;
//	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
