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
}
