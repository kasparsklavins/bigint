#include "assert.h"

#include "bigint.h"

namespace add{
    inline void add_test()
    {
        Dodecahedron::Bigint bint;
        int zero = 55;

        bint = zero;

        assert(Dodecahedron::to_string(bint) == "55");
        assert(bint == bint * 1);
        assert(bint == 55);
    };

    inline void add_test_1()
    {
        Dodecahedron::Bigint bint1 = 30;
        Dodecahedron::Bigint bint2 = 70;

        assert(Dodecahedron::to_string(bint1) == "30");
        assert(Dodecahedron::to_string(bint2) == "70");

        assert(bint1 + bint2 == 100);
    };
}
