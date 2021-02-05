#include <vector>
#include <iostream>
#include <algorithm>

#define expect( chk )  \
    if (!(chk)) \
        printf("Assertion (%s) failed %s at line %d \n", #chk, __FILE__,__LINE__);

using namespace std;



// Esta es una versión medio ineficiente pero bien
// compacta de expresar.

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


// Aquí vas a implementar el algoritmo que les presenté en el
// video.
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

//    Descomenta estas pruebas cuando implementes la
//    segunda version
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

    cout << "FIN! (si no ves Assertions arriba pas'o todas las pruebas)\n";


}
