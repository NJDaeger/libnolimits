#ifndef LIB_NL2PARK_VERSION_H
#define LIB_NL2PARK_VERSION_H

#include "../../Nolimits.h"
#include <string>
#include "../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Version: public Stream::Chunk {
        public:
            void debug() {
                std::cout << "Version[getMajor]: " << getMajor() << std::endl;
                std::cout << "Version[getMinor]: " << getMinor() << std::endl;
                std::cout << "Version[getRevision]: " << getRevision() << std::endl;
                std::cout << "Version[getBuild]: " << getBuild() << std::endl;
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            uint8_t getMajor() const;
            void setMajor(const uint8_t &value);

            uint8_t getMinor() const;
            void setMinor(const uint8_t &value);

            uint8_t getRevision() const;
            void setRevision(const uint8_t &value);

            uint8_t getBuild() const;
            void setBuild(const uint8_t &value);

        private:
            uint8_t major;
            uint8_t minor;
            uint8_t revision;
            uint8_t build;
        };
    }
}

#endif
