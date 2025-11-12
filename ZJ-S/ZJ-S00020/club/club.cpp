#include<bits/stdc++.h>
using namespace std;
int T;
struct Node{
	int a1,a2,a3,id;
}a[100005];
bool cmp(Node p,Node q){
	return p.a1>q.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int mm=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].id=i;
			if(a[i].a2==0) mm++;
			if(a[i].a3==0) mm++;
		}
		if(n==2){
			int b=a[1].a1+a[2].a2;
			int c=a[1].a1+a[2].a3;
			int d=a[1].a2+a[2].a1;
			int e=a[1].a2+a[2].a3;
			int f=a[1].a3+a[2].a1;
			int g=a[1].a3+a[2].a2;
			int x=max(b,c);
			int y=max(d,e);
			int z=max(f,g);
			int w=max(x,y);
			int r=max(w,z);
			cout<<r<<endl;
		}
		else if(n==4){
			int b1=a[1].a1+a[2].a1+a[3].a2+a[4].a2;
			int c1=a[1].a1+a[2].a1+a[3].a2+a[4].a3;
			int d1=a[1].a1+a[2].a1+a[3].a3+a[4].a2;
			int e1=a[1].a1+a[2].a1+a[3].a3+a[4].a3;
			int f1=a[1].a1+a[2].a2+a[3].a1+a[4].a2;
			int g1=a[1].a1+a[2].a2+a[3].a1+a[4].a3;
			int h1=a[1].a1+a[2].a2+a[3].a2+a[4].a1;
			int i1=a[1].a1+a[2].a2+a[3].a2+a[4].a3;
			int j1=a[1].a1+a[2].a2+a[3].a3+a[4].a1;
			int k1=a[1].a1+a[2].a2+a[3].a3+a[4].a2;
			int l1=a[1].a1+a[2].a2+a[3].a3+a[4].a3;
			int m1=a[1].a1+a[2].a3+a[3].a1+a[4].a2;
			int n1=a[1].a1+a[2].a3+a[3].a1+a[4].a3;
			int o1=a[1].a1+a[2].a3+a[3].a2+a[4].a1;
			int p1=a[1].a1+a[2].a3+a[3].a2+a[4].a2;
			int q1=a[1].a1+a[2].a3+a[3].a2+a[4].a3;
			int r1=a[1].a1+a[2].a3+a[3].a3+a[4].a1;
			int s1=a[1].a1+a[2].a3+a[3].a3+a[4].a2;
			int aaa=max(b1,c1);
			int bbb=max(d1,e1);
			int ccc=max(f1,g1);
			int ddd=max(h1,i1);
			int eee=max(j1,k1);
			int fff=max(l1,m1);
			int ggg=max(n1,o1);
			int hhh=max(p1,q1);
			int iii=max(r1,s1);
			int aaabbb=max(aaa,bbb);
			int cccddd=max(ccc,ddd);
			int eeefff=max(eee,fff);
			int ggghhh=max(ggg,hhh);
			int aaabbbcccddd=max(aaabbb,cccddd);
			int eeefffggghhh=max(eeefff,ggghhh);
			int aaabbbcccdddeeefffggghhh=max(aaabbbcccddd,eeefffggghhh);
			int maxn1=max(aaabbbcccdddeeefffggghhh,iii);
			int b11=a[1].a2+a[2].a1+a[3].a1+a[4].a2;
			int c11=a[1].a2+a[2].a1+a[3].a1+a[4].a3;
			int d11=a[1].a2+a[2].a1+a[3].a2+a[4].a1;
			int e11=a[1].a2+a[2].a1+a[3].a2+a[4].a3;
			int f11=a[1].a2+a[2].a1+a[3].a3+a[4].a1;
			int g11=a[1].a2+a[2].a2+a[3].a3+a[4].a1;
			int h11=a[1].a2+a[2].a2+a[3].a3+a[4].a3;
			int i11=a[1].a2+a[2].a2+a[3].a1+a[4].a3;
			int j11=a[1].a2+a[2].a2+a[3].a1+a[4].a1;
			int k11=a[1].a2+a[2].a2+a[3].a3+a[4].a1;
			int l11=a[1].a2+a[2].a2+a[3].a3+a[4].a3;
			int m11=a[1].a2+a[2].a3+a[3].a1+a[4].a2;
			int n11=a[1].a2+a[2].a3+a[3].a1+a[4].a3;
			int o11=a[1].a2+a[2].a3+a[3].a1+a[4].a1;
			int p11=a[1].a2+a[2].a3+a[3].a2+a[4].a3;
			int q11=a[1].a2+a[2].a3+a[3].a2+a[4].a1;
			int r11=a[1].a2+a[2].a3+a[3].a3+a[4].a1;
			int s11=a[1].a2+a[2].a3+a[3].a3+a[4].a2;
			int aaa1=max(b11,c11);
			int bbb1=max(d11,e11);
			int ccc1=max(f11,g11);
			int ddd1=max(h11,i11);
			int eee1=max(j11,k11);
			int fff1=max(l11,m11);
			int ggg1=max(n11,o11);
			int hhh1=max(p11,q11);
			int iii1=max(r11,s11);
			int aaabbb1=max(aaa1,bbb1);
			int cccddd1=max(ccc1,ddd1);
			int eeefff1=max(eee1,fff1);
			int ggghhh1=max(ggg1,hhh1);
			int aaabbbcccddd1=max(aaabbb1,cccddd1);
			int eeefffggghhh1=max(eeefff1,ggghhh1);
			int aaabbbcccdddeeefffggghhh1=max(aaabbbcccddd1,eeefffggghhh1);
			int maxn2=max(aaabbbcccdddeeefffggghhh1,iii1);
			int b111=a[1].a3+a[2].a1+a[3].a1+a[4].a2;
			int c111=a[1].a3+a[2].a1+a[3].a1+a[4].a3;
			int d111=a[1].a3+a[2].a1+a[3].a2+a[4].a1;
			int e111=a[1].a3+a[2].a1+a[3].a2+a[4].a2;
			int f111=a[1].a3+a[2].a1+a[3].a2+a[4].a3;
			int g111=a[1].a3+a[2].a2+a[3].a3+a[4].a1;
			int h111=a[1].a3+a[2].a2+a[3].a3+a[4].a2;
			int i111=a[1].a3+a[2].a2+a[3].a1+a[4].a1;
			int j111=a[1].a3+a[2].a2+a[3].a1+a[4].a2;
			int k111=a[1].a3+a[2].a2+a[3].a1+a[4].a3;
			int l111=a[1].a3+a[2].a2+a[3].a2+a[4].a1;
			int m111=a[1].a3+a[2].a2+a[3].a2+a[4].a3;
			int n111=a[1].a3+a[2].a2+a[3].a3+a[4].a1;
			int o111=a[1].a3+a[2].a2+a[3].a3+a[4].a2;
			int p111=a[1].a3+a[2].a3+a[3].a1+a[4].a2;
			int q111=a[1].a3+a[2].a3+a[3].a1+a[4].a1;
			int r111=a[1].a3+a[2].a3+a[3].a2+a[4].a1;
			int s111=a[1].a3+a[2].a3+a[3].a2+a[4].a2;
			int aaa11=max(b111,c111);
			int bbb11=max(d111,e111);
			int ccc11=max(f111,g111);
			int ddd11=max(h111,i111);
			int eee11=max(j111,k111);
			int fff11=max(l111,m111);
			int ggg11=max(n111,o111);
			int hhh11=max(p111,q111);
			int iii11=max(r111,s111);
			int aaabbb11=max(aaa11,bbb11);
			int cccddd11=max(ccc11,ddd11);
			int eeefff11=max(eee11,fff11);
			int ggghhh11=max(ggg11,hhh11);
			int aaabbbcccddd11=max(aaabbb11,cccddd11);
			int eeefffggghhh11=max(eeefff11,ggghhh11);
			int aaabbbcccdddeeefffggghhh11=max(aaabbbcccddd11,eeefffggghhh11);
			int maxn3=max(aaabbbcccdddeeefffggghhh11,iii11);
			int maxn4=max(maxn1,maxn2);
			int maxn=max(maxn4,maxn3);
			cout<<maxn<<endl;
		}
		else if(mm==2*n){
			sort(a+1,a+n+1,cmp);
			int maxn=0;
			for(int i=1;i<=n/2;i++){
				maxn+=a[i].a1;
			}
			cout<<maxn<<endl;
		}
		else{
			int maxnnn[100005];
			int num=0;
			for(int i=1;i<=n;i++){
				int abcdefg=max(a[i].a1,a[i].a2);
				maxnnn[i]=max(abcdefg,a[i].a3);
				num+=maxnnn[i];
			}
			cout<<num<<endl;
		}
	}
	return 0;
}
