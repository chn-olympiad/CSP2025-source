#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	scanf("%d", &t);
	int t1;
	scanf("%d", &t1);
	int n1, n2, n3, n4;
	int n11, n12, n13;
    int n21, n22, n23;
    int n31, n32, n33;
    int n41, n42, n43;
    int a;
	scanf("%d%d%d", &n11, &n12, &n13);
	if(n11>n12 and n11>n13){
		a = n11;
    }else if(n12>n11 and n12>n13){
	    a = n12;
	}else if(n13>n11 and n13>n12){
	    a = n13;
    }
	int b;
	scanf("%d%d%d", &n21, &n22, &n23);
    if(n21>n22 and n21>n23){
	    b = n21;
	}else if(n22>n21 and n22>n23){
	    b = n22;
	}else if(n23>n21 and n23>n22){
	    b = n23;
	}
	int c;
    scanf("%d%d%d", &n31, &n32, &n33);
    if(n31>n32 and n31>n33){
	   	c = n31;
	}else if(n32>n31 and n32>n33){
	    c = n32;
	}else if(n33>n31 and n33>n32){
	    c = n33;
    }
	int d;
    scanf("%d%d%d", &n41, &n42, &n43);
    if(n41>n42 and n41>n43){
	   	d = n41;
	}else if(n42>n41 and n42>n43){
	   	d = n42;
	}else if(n43>n41 and n43>n42){
	    d = n43;
    }
	int t2;
	scanf("%d", &t2);
	int m1, m2, m3, m4;
	int m11, m12, m13;
    int m21, m22, m23;
    int m31, m32, m33;
    int m41, m42, m43;
    int a1;
	scanf("%d%d%d", &m11, &m12, &m13);
	if(m11>m12 and m11>m13){
	    a1 = m11;
    }else if(m12>m11 and m12>m13){
	   	a1 = m12;
	}else if(m13>m11 and m13>m12){
	   	a1 = m13;
    }
	int b1;
	scanf("%d%d%d", &m21, &m22, &m23);
    if(m21>m22 and m21>m23){
	   	b1 = m21;
	}else if(m22>m21 and m22>m23){
	   	b1 = m22;
	}else if(m23>m21 and m23>m22){
	   	b1 = m23;
	}
	int c1;
    scanf("%d%d%d", &m31, &m32, &m33);
    if(m31>m32 and m31>m33){
	   	c1 = m31;
	}else if(m32>m31 and m32>m33){
	   	c1 = m32;
	}else if(m33>m31 and m33>m32){
	    c1 = m33;
    }
	int d1;
    scanf("%d%d%d", &m41, &m42, &m43);
    if(m41>m42 and m41>m43){
	   	d1 = m41;
	}else if(m42>m41 and m42>m43){
	   	d1 = m42;
	}else if(m43>m41 and m43>m42){
	    d1 = m43;
    }
	int t3;
	scanf("%d", &t3);
	int ma1, mb1;
	int m111, m112, m113;
    int m211, m212, m213;
    int a11;
	scanf("%d%d%d", &m111, &m112, &m113);
	if(m111>m112 and m111>m113){
	    a11 = m111;
    }else if(m112>m111 and m112>m113){
	   	a11 = m112;
	}else if(m113>m111 and m113>m112){
	   	a11 = m113;
	}
	int b11;
	scanf("%d%d%d", &m211, &m212, &m213);
    if(m211>m212 and m212>m213){
	   	b11 = m211;
	}else if(m212>m211 and m212>m213){
	   	b11 = m212;
	}else if(m213>m211 and m213>m212){
	   	b11 = m213;
	}
	int abcd, abcd1, ab;
	abcd = a+b+c+d;
	abcd1 = a1+b1+c1+d1;
	ab = a11+b11;
	cout << abcd << endl << abcd1 << endl << ab << endl;
	return 0;
} 
