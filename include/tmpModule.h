#ifndef TMP_MODULE
#define TMP_MODULE

/*Standard Includes*/

/* Custom Includes */
#include "BaseModule.h"

/**
 * @brief Converts time chunks to FFT chunks and computes FFT
 */
class TMPModule : 
    public BaseModule
{
    public:
    /**
     * @brief Construct a new FFTModule object
     * @param uBufferSize size of processing input buffer
     */
    TMPModule(unsigned uBufferSize);
};

#endif
