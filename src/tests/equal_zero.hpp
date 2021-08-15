#include "assert.h"

#include "bigint.h"

namespace equal_zero{
    inline void test()
    {
        Dodecahedron::Bigint bint;
        int zero = 0;

        bint = zero;

        assert(Dodecahedron::to_string(bint)=="0");
        assert(bint == bint * 0);
        assert(bint == 0);
    };
}
