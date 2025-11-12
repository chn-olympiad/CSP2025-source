#include<iostream>
#include<algorithm>

using namespace std;

const long long Min=-999999999;
long long T,n,sum,s[5];

struct Member{
	long long a[7],ma,mi,ch;
}m[100050];

long long Read(){
	long long Ra=0,Rf=1;
	char Rc=getchar();
	while(Rc<'0'||Rc>'9'){
		if(Rc=='-') Rf=-1;
		Rc=getchar();
	}
	while(Rc>='0'&&Rc<='9'){
		Ra=(Ra<<1)+(Ra<<3)+(Rc&15);
		Rc=getchar();
	}
	return Ra*Rf;
}bool cmp(Member u,Member v){
	return u.ch>v.ch;
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=Read();
	while(T--){
		n=Read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				m[i].a[j]=Read();
			}
		}
//		cout<<n<<"\n";
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				cout<<a[i][j]<<" "<<"\n";
//			}
//			cout<<"\n";
//		}
//		cout<<"\n\n";
		for(int i=1;i<=n;i++){
			if(m[i].a[1]==m[i].a[2]&&m[i].a[2]==m[i].a[3]) m[i].ma=m[i].mi=4;
			else if(m[i].a[1]>=m[i].a[2]&&m[i].a[2]>=m[i].a[3]) m[i].ma=1,m[i].mi=2,m[i].a[3]=Min;
			else if(m[i].a[1]>=m[i].a[3]&&m[i].a[3]>=m[i].a[2]) m[i].ma=1,m[i].mi=3,m[i].a[2]=Min;
			else if(m[i].a[2]>=m[i].a[1]&&m[i].a[1]>=m[i].a[3]) m[i].ma=2,m[i].mi=1,m[i].a[3]=Min;
			else if(m[i].a[2]>=m[i].a[3]&&m[i].a[3]>=m[i].a[1]) m[i].ma=2,m[i].mi=3,m[i].a[1]=Min;
			else if(m[i].a[3]>=m[i].a[1]&&m[i].a[1]>=m[i].a[2]) m[i].ma=3,m[i].mi=1,m[i].a[2]=Min;
			else if(m[i].a[3]>=m[i].a[2]&&m[i].a[2]>=m[i].a[1]) m[i].ma=3,m[i].mi=2,m[i].a[1]=Min;
			m[i].ch=m[i].a[m[i].ma]-m[i].a[m[i].mi];
		}
		sort(m+1,m+n+1,cmp);
		s[1]=s[2]=s[3]=sum=0;
		for(int i=1;i<=n;i++){
			if(s[m[i].ma]>=n/2){
				sum+=m[i].a[m[i].mi];
				s[m[i].mi]++;
			}else{
				sum+=m[i].a[m[i].ma];
				s[m[i].ma]++;
			}
		}
		cout<<sum<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
//±ð³¬Ê± 
