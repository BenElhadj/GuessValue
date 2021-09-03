#include <stdio.h>
#include "GuessValue_t.h"


void enclave_GuessValue()
{
    fprintf(stdout, "Guess Value from the enclave\n");

    oe_result_t result = host_GuessValue();
    if (result != OE_OK)
    {
        fprintf(
            stderr,
            "Call to host_GuessValue failed: result=%u (%s)\n",
            result,
            oe_result_str(result));
    }
}
