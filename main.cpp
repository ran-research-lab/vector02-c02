#include <vector>
#include <iostream>
#include <algorithm>

// Variables and macros for assertions, DO NOT CHANGE ****
int totalAssertions = 0;
int passedAssertions  = 0;
#define expect( chk )  \
    totalAssertions++; \
    if (!(chk)) \
        printf("\x1B[31mAssertion (%s) failed %s at line %d\033[0m\t\t\n", #chk, __FILE__,__LINE__); \
    else { \
        printf("\x1B[32mPassed line %d: %s\033[0m\t\t\n", __LINE__, #chk); \
        passedAssertions++; \
    }
#define assertionReport() { \
     printf("==========================================\n"); \
     printf("Passed %d of %d assertions\n",passedAssertions,totalAssertions); \
     printf("\n"); \
    }
//*******************************************************

using namespace std;



// Esta es una versión medio ineficiente pero bien compacta de expresar.

bool equalWOZeroes_v01( vector<int> &A, vector<int> &B ) {
    // borramos los ceros de A
    for (int i = A.size() -1; i >= 0; i--)
        if (A[i] == 0) A.erase(A.begin()+i);

    // borramos los ceros de B
    for (int i = B.size() -1; i >= 0; i--)
        if (B[i] == 0) B.erase(B.begin()+i);

    // devolvemos el resultado de la comparación
    return A == B;
}


// Aquí vas a implementar el algoritmo que les presenté en el video.

bool equalWOZeroes_v02( const vector<int> &A, const vector<int> &B ) {
    return false;
}


int main() {
	vector<int> A {10,20,0,30,40,0,0};
	vector<int> B {10,20,30,0,40};
	vector<int> C {0,0,0,0,10,20,30,40};
	vector<int> D {0,0,0,0,20,10,30,40};
	vector<int> E {0,0,0,0,0};
	vector<int> F {0,0,0,0,0};
    vector<int> G {1,2};
    vector<int> H {1};


    expect( equalWOZeroes_v02(A,B) );
    expect( equalWOZeroes_v02(A,C) );
    expect( equalWOZeroes_v02(A,D) == false );
    expect( equalWOZeroes_v02(D,D)  );
    expect( equalWOZeroes_v02(E,F)  );
    expect( equalWOZeroes_v02(F,E)  );
    expect( equalWOZeroes_v02(G,H) == false );
    expect( equalWOZeroes_v02(H,G) == false );


    expect( equalWOZeroes_v01(A,B) );
    expect( equalWOZeroes_v01(A,C) );
    expect( equalWOZeroes_v01(A,D) == false );
    expect( equalWOZeroes_v01(D,D)  );
    expect( equalWOZeroes_v01(E,F)  );
    expect( equalWOZeroes_v01(F,E)  );
    expect( equalWOZeroes_v01(G,H) == false );
    expect( equalWOZeroes_v01(H,G) == false );

    assertionReport();

}
