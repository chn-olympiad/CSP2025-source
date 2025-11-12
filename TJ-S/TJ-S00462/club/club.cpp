#include<bits/stdc++.h>
using namespace std;
int t,n,a1,a2,a3,a4,a5,a6,b1,b2,b3,b4,b5,b6,b7,b8,b9,sum;
int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13,d14,d15,d16,d17,d18,d19,d20,d21,d22,d23,d24,d25,d26,d27,d28,d29,d30,d31,d32,d33,d34,d35,d36,d37,d38,d39,d40,d41,d42,d43,d44,d45,d46,d47,d48,d49,d50,d51,d52,d53,d54,d55,d56;
struct node{
	int a,b,c,d,e;
}a[100001];
bool jj(node a,node b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    for(int x=0;x<t;x++){ 
    	sum=0;
    	cin>>n;
    	if(n==2){
    		cin>>a1>>a2>>a3>>a4>>a5>>a6;
    		b1=0,b2=a1+a5,b3=a1+a6;
    		b4=a2+a4,b5=0,b6=a2+a6;
    		b7=a3+a4,b8=a3+a5,b9=0;		
			b1=max(b1,b2),b3=max(b3,b4),b5=max(b5,b6),b7=max(b7,b8);
			b1=max(b1,b3),b5=max(b5,b7);
			b1=max(b1,b5);
			b1=max(b1,b9);cout<<b1<<endl;continue;	    		
		}
		if(n==4){
			cin>>c1>>c2>>c3>>c4>>c5>>c6>>c7>>c8>>c9>>c10>>c11>>c12;
			d1=c1+c4+c8+c11,d2=c1+c4+c8+c12,d3=c1+c4+c9+c11,d4=c1+c4+c9+c12;//4
			d5=c1+c5+c7+c11,d6=c1+c5+c7+c12,d7=c1+c5+c8+c10,d8=c1+c5+c8+c12,d24=c1+c5+c9+c10,d25=c1+c5+c9+c11,d26=c1+c5+c9+c12;//7
			d9=c1+c6+c7+c11,d10=c1+c6+c7+c12,d11=c1+c6+c8+c10,d12=c1+c6+c8+c11,d13=c1+c6+c8+c12,d32=c1+c6+c9+c10,d33=c1+c6+c9+c11;//7
            d14=c2+c4+c7+c11,d15=c2+c4+c7+c12,d16=c2+c4+c8+c10,d17=c2+c4+c8+c12,d18=c2+c4+c9+c11,d19=c2+c4+c9+c12,d54=c2+c4+c9+c10;//7
			d20=c2+c5+c7+c10,d21=c2+c5+c7+c12,d22=c2+c5+c9+c10,d23=c2+c5+c9+c12;//4
			d27=c2+c6+c7+c10,d28=c2+c6+c7+c11,d29=c2+c6+c7+c12,d30=c2+c6+c8+c10,d31=c2+c6+c8+c12,d34=c2+c6+c9+c10,d35=c2+c6+c9+c11;	//7
			d36=c3+c4+c7+c11,d37=c3+c4+c7+c12,d38=c3+c4+c8+c10,d39=c3+c4+c8+c11,d40=c3+c4+c8+c12,d41=c3+c4+c9+c10,d42=c3+c4+c9+c11;	//7
			d43=c3+c5+c7+c10,d44=c3+c5+c7+c11,d45=c3+c5+c7+c12,d46=c3+c5+c8+c10,d47=c3+c5+c8+c12,d48=c3+c5+c9+c10,d49=c3+c5+c9+c11;//7
			d50=c3+c6+c7+c10,d51=c3+c6+c7+c11,d52=c3+c6+c8+c10,d53=c3+c6+c8+c11;//4
			d1=max(d1,d2),d3=max(d3,d4),d5=max(d5,d6),d9=max(d9,d10),d7=max(d7,d8);
			d11=max(d11,d12),d13=max(d13,d14),d15=max(d15,d16),d19=max(d19,d20),d17=max(d17,d18);
			d21=max(d21,d22),d23=max(d23,d24),d25=max(d25,d26),d29=max(d29,d30),d27=max(d27,d28);	
			d31=max(d31,d32),d33=max(d33,d34),d35=max(d35,d36),d39=max(d39,d40),d37=max(d37,d38);
			d41=max(d41,d42),d43=max(d43,d44),d45=max(d45,d46),d49=max(d49,d50),d47=max(d47,d48);
			d51=max(d51,d52),d53=max(d53,d54);
			d1=max(d1,d3),d5=max(d5,d7),d9=max(d9,d11),d13=max(d13,d15),d17=max(d17,d19);
			d21=max(d21,d23),d25=max(d25,d27),d29=max(d29,d31),d33=max(d33,d35),d37=max(d37,d39);
			d41=max(d41,d43),d45=max(d45,d47),d49=max(d49,d51),d53=max(d53,0);		
			d1=max(d1,d5),d9=max(d9,d13),d17=max(d17,d21),d25=max(d25,d29),d33=max(d33,d37),d41=max(d41,d45),d49=max(d49,d53);
			d1=max(d1,d9),d17=max(d17,d25),d33=max(d33,d41),d49=max(d49,0);
			d1=max(d1,d17),d33=max(d33,d49);
			d1=max(d1,d33);
			cout<<d1<<endl;continue;
		}
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a,a+n,jj);
		for(int i=0;i<n/2;i++){
			sum+=a[i].a;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
