#include<bits/stdc++.h>
using namespace std;

int n,q;
string s1[200010],s2[200010],t1,t2;
int l1[200010],b1[200010],b2[200010],l,c1,c2;
bool goodB=true;
int numB;
long long ans=0;
int lst,t;
bool flag;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		l1[i]=s1[i].length();
		if(!goodB) continue;
		numB=0;
		for(int j=0;j<l1[i];j++){
			if(s1[i][j]!='a'&&s1[i][j]!='b'){
				goodB=false;
				break;
			}
			if(s1[i][j]=='b') numB++;
			if(numB>=2){
				goodB=false;
				break;
			}
		}
		if(numB!=1||!goodB){
			goodB=false;
			continue;
		}
		numB=0;
		for(int j=0;j<l1[i];j++){
			if(s2[i][j]!='a'&&s2[i][j]!='b'){
				goodB=false;
				break;
			}
			if(s2[i][j]=='b') numB++;
			if(numB>=2){
				goodB=false;
				break;
			}
		}
		if(numB!=1||!goodB){
			goodB=false;
			continue;
		}
	}
	if(!goodB){
		while(q--){
			cin>>t1>>t2;
			l=t1.length();
			if(l!=t2.length()){
				puts("0");
				continue;
			}
			lst=-1;
			ans=0;
			for(int i=l-1;i>=0;i--)
				if(t1[i]!=t2[i]){
					lst=i;
					break;
				}
			for(int i=0;i<l;i++){
				for(int j=1;j<=n;j++){
					t=l1[j];
					if(t+i-1>=l) continue;
					if(i+t<=lst) continue;
					flag=true;
					for(int k=0;k<t;k++)
						if(t1[i+k]!=s1[j][k]||t2[i+k]!=s2[j][k]){
							flag=false;
							break;
						}
					if(flag) ans++;
				}
				if(t1[i]!=t2[i]) break;
			}
			printf("%lld\n",ans);
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<l1[i];j++)
				if(s1[i][j]=='b'){
					b1[i]=j;
					break;
				}
			for(int j=0;j<l1[i];j++)
				if(s2[i][j]=='b'){
					b2[i]=j;
					break;
				}
		}
		while(q--){
			cin>>t1>>t2;
			l=t1.length();
			if(l!=t2.length()){
				puts("0");
				continue;
			}
			ans=0;
			for(int i=0;i<l;i++)
				if(t1[i]=='b'){
					c1=i;
					break;
				}
			for(int i=0;i<l;i++)
				if(t2[i]=='b'){
					c2=i;
					break;
				}
			for(int i=1;i<=n;i++)
				if(c2-c1==b2[i]-b1[i]&&b1[i]<=c1&&c1+l1[i]-b1[i]<=l) ans++;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
