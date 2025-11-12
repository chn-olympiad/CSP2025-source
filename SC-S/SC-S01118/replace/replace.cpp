#include<bits/stdc++.h> 
#include<iostream> 
int q=0,w=0,e=0,y=0,u=0;
long long i[10000][2],p[1000][2][10000],o=0,r=0,t=0;
char a[1000][2][10000],s[1000][2][10000];
using namespace std;
void Q(int j,int k,int l){
	for(int z=0;z<e;z++){
		o*=131;
		o+=a[j][k][z];
	}
	return;
}
void W(int j,int k,int l){
	for(int z=0;z<e;z++){
		o*=131;
		o+=a[j][k][z];
		s[j][k][z]=o;
	}
	return;
}
int main(){
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
	cin>>q>>w;
	for(int z=0;z<q;z++){
		cin>>a[z][0];
		cin>>a[z][1];
		e=strlen(a[z][0]);
		o=0;
		Q(z,0,0);
		i[z][0]=o;
		o=0;
		Q(z,1,0);
		i[z][1]=o;
	}
	for(int z=0;z<w;z++){
		cin>>s[z][0];
		cin>>s[z][1];
		e=strlen(s[z][0]);
		o=0;
		W(z,0,0);
		o=0;
		W(z,1,0);
		for(int x=0;x<e;x++){
			for(int c=1;c<e;c++){
				r=s[z][0][x];
				t=s[z][1][x];
				for(int v=x;v<c;v++){
					r*=131;
					t*=131;
				}
				for(int v=0;v<w;v++){
					if((s[z][0][c]-r==i[v][0])&&(s[z][1][c]-t==i[v][1])){
						y++;
					}
				}
			}
		}
		cout<<y<<"\n";	
	}
	return 0;
}