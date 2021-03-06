#ifndef LIB_NL2PARK_USPK_H
#define LIB_NL2PARK_USPK_H

#include "../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Uspk: public Stream::Chunk {
        public:
            Uspk() {}

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);

            std::string getChunkName() { return "USPK"; }
            /*! \endcond */
        };
    }
}

#endif // LIB_NL2PARK_USPK_H
