#include "assert.h"

#include "bigint.h"
#include <iostream>

namespace divide{
    inline void divide_test_1()
    {
        Dodecahedron::Bigint bint1 = 30;
        Dodecahedron::Bigint bint2 = 3;

        assert(Dodecahedron::to_string(bint1) == "30");
        assert(Dodecahedron::to_string(bint2) == "3");

        assert(bint1 / bint2 == 10);
    };
    
    inline void divide_test_2()
    {
        Dodecahedron::Bigint bint1 = 70;
        Dodecahedron::Bigint bint2 = 8;

        assert(Dodecahedron::to_string(bint1) == "70");
        assert(Dodecahedron::to_string(bint2) == "8");

        //TODO change / operator to get 9 instead 8
        assert(bint1 / bint2 == 8);
    };
}
